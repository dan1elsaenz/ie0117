#!/bin/bash

if [ -z $1 ] || [ -z $2 ]; then # Verificar que los parametros no esten vacios
    echo "Formato: ./ejercicio2.sh [nombreUsuario] [nombreGrupo]" # Mensaje de ayuda
    exit 1
else
    # Verificar la existencia del usuario que se pasa como parametro
    if grep -q "$1" /etc/passwd; then
        echo "El usuario $1 ya existe"
    else
        sudo adduser $1 # Se crea el usuario nuevo
    fi

    # Verificar la existencia del grupo
    if grep -q "$2" /etc/group; then
        echo "El grupo $2 ya existe"
    else
        sudo addgroup $2 # Creacion del grupo
    fi

    # Se añade el usuario default y el usuario nuevo
    sudo usermod -a -G $2 $1
    sudo usermod -a -G $2 $USER

    # Se cambian los permisos de ejecucion de ejercicio1.sh
    # para los miembros del grupo
    sudo chgrp $2 ejercicio1.sh
    chmod ugo-x ejercicio1.sh 
    chmod g+x ejercicio1.sh
fi
