#!/bin/bash

mostrarError() {
    # Leer linea por linea el contenido que se pasa por el unnamed pipe
    while IFS= read -r linea; do
        # Cortar el string para sacar hora y descripcion
        hora=$(echo $linea | cut -f 2 -d " ")
        descripcion=$(echo $linea | cut -f5- -d " ")

        # Informacion al archivo output.txt
        echo "Hora del Error: $hora" >> output.txt
        echo "Descripcion del Error: $descripcion" >> output.txt
    done
}

# Valores predeterminados de modo y date
modo=0
date=0
# getopts para las flags
while getopts "hm:d:" parametro; do
    case $parametro in
        h)
            # Guia de ayuda
            echo "Modo de empleo: ./ejercicio3.sh [MODE] [DATE]"
            
            echo "Opciones:"
            echo "-h   Imprime el menu de ayuda"
            echo "-m   Modo de funcionamiento del informe"
            echo "        [servidor_web | base_de_datos | proceso_batch | aplicacion | monitoreo]"
            echo "-d   Especifica la fecha. Formato: aaaa-mm-dd"
            ;;

        m)
            if ! [ -z $OPTARG ]; then # Si el argumento no esta vacio entonces se cambia modo
                modo=$OPTARG
            fi
            ;;
        d)
            if ! [ -z $OPTARG ]; then # Mismo procedimiento que el anterior
                date=$OPTARG
            fi
            ;;

    esac
done


case "$modo,$date" in
    0,0)
        # Mensaje de ayuda si no indico flags
        echo "Revise el menu de ayuda con -h" >&2
        exit 1
        ;;
    0,*)
        # Si se indica solo el date
        if (ls -l "./system_logs" | grep -q $date); then # Se busca en el directorio la fecha por grep
            echo "Fecha: $date" > output.txt
            cat "./system_logs/log_$date.log" | grep "ERROR" | mostrarError # Sacar ERRORES con grep
        else
            echo "No se encuentran logs de esa fecha"
        fi
        ;;
    *,0)
        # Recorrer todos los directorios si no se indica el date
        echo "" > output.txt # Para vaciar el archivo de output.txt
        for archivo in ./system_logs/*; do # Para cada archivo en el directorio
            if grep -q -E "ERROR\s\[$modo\]" $archivo; then # Busqueda por modo
                fecha=$(echo $archivo | cut -d "_" -f3 | cut -d "." -f1)
                echo "Fecha: $fecha" >> output.txt
                cat $archivo | grep -E "ERROR\s\[$modo\]" | mostrarError
            fi
        done
        ;;
    *)
        # En caso contrario, se indicaron ambos parametros
        if (ls -l "./system_logs" | grep -q $date); then # Se busca el date en el directorio
            echo "Fecha: $date" > output.txt
            cat "./system_logs/log_$date.log" | grep -E "ERROR\s\[$modo\]" | mostrarError # Se filtran ERRORES por el modo
        else
            echo "No se encuentran logs con la fecha y el modo indicados"
        fi
        ;;
esac

