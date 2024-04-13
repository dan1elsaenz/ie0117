#!/bin/bash

is_process_running() {
    local process_name=$1
    pgrep $process_name > /dev/null 2>&1
}

if [ -z $1 ] && [ -z $2 ]; then
    echo "Formato: $0 [nombreProceso] 'comando'"
    exit 1

else
    while true; do
        if ! is_process_running $1; then
            $2 & # Levantar el proceso en bg
        fi
        sleep 5
    done
fi

