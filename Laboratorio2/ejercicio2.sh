#!/bin/bash

is_process_running() {
    local process_name=$1 # Primer parametro de la funcion es el nombre del proceso
    pgrep $process_name > /dev/null 2>&1 # pgrep para verificar si existe un proceso con ese nombre
}

if [ -z $1 ] && [ -z $2 ]; then # Si los dos parametros estan vacios
    # Mensaje de ayuda
    echo "Formato: $0 [nombreProceso] 'comando'"
    exit 1

else
    while true; do # Repetir indefinidamente
        if ! is_process_running $1; then
	    # Si el proceso no esta ejecutandose
            $2 & # Levantar el proceso en bg
        fi
        sleep 5 # Repeticion cada 5 segundos
    done
fi

