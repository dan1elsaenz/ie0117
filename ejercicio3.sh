#!/bin/bash

mostrarError() {
    while IFS= read -r linea; do
        hora=$(echo $linea | cut -f 2 -d " ")
        descripcion=$(echo $linea | cut -f5- -d " ")

        echo "Hora del Error: $hora" >> output.txt
        echo "Descripcion del Error: $descripcion" >> output.txt
    done
}

modo=0
date=0
while getopts "hm:d:" parametro; do
    case $parametro in
        h)
            echo "Modo de empleo: ./ejercicio3.sh [MODE] [DATE]"
            
            echo "Opciones:"
            echo "-h   Imprime el menu de ayuda"
            echo "-m   Modo de funcionamiento del informe"
            echo "        [servidor_web | base_de_datos | proceso_batch | aplicacion | monitoreo]"
            echo "-d   Especifica la fecha. Formato: aaaa-mm-dd"
            ;;

        m)
            if ! [ -z $OPTARG ]; then
                modo=$OPTARG
            fi
            ;;
        d)
            if ! [ -z $OPTARG ]; then
                date=$OPTARG
            fi
            ;;

    esac
done


case "$modo,$date" in
    0,0)
        echo "Revise el menu de ayuda con -h" >&2
        exit 1
        ;;
    0,*)
        # Si se indica solo el date
        if (ls -l "./system_logs" | grep -q $date); then
            echo "Fecha: $date" > output.txt
            cat "./system_logs/log_$date.log" | grep "ERROR" | mostrarError
        else
            echo "No se encuentran logs de esa fecha"
        fi
        ;;
    *,0)
        # Recorrer todos los directorios si no se indica el date
        echo "" > output.txt
        for archivo in ./system_logs/*; do
            if grep -q -E "ERROR\s\[$modo\]" $archivo; then
                fecha=$(echo $archivo | cut -d "_" -f3 | cut -d "." -f1)
                echo "Fecha: $fecha" >> output.txt
                cat $archivo | grep -E "ERROR\s\[$modo\]" | mostrarError
            fi
        done
        ;;
    *)
        # En caso contrario, se indicaron ambos parametros
        if (ls -l "./system_logs" | grep -q $date); then
            echo "Fecha: $date" > output.txt
            cat "./system_logs/log_$date.log" | grep -E "ERROR\s\[$modo\]" | mostrarError
        else
            echo "No se encuentran logs con la fecha y el modo indicados"
        fi
        ;;
esac
