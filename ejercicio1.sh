#! /bin/bash

get_permissions_verbose() {
    user="$(echo $permisos | cut -c 2-4)"
    grupos="$(echo $permisos | cut -c 5-7)"
    otros="$(echo $permisos | cut -c 8-10)"
}

if [ -z $1 ] || [ -z $2 ]; then
    echo -e "Ingrese dos parametros\nFormato: ./ejercicio1.sh [nombreArchivo] [r|w|x]" >&2
    exit 1

elif [ -e $1 ]; then
    permisos="$(stat -c "%A%" $1)"
    
    get_permissions_verbose
    
    if [ $2 = "r" ]; then
        echo "User: $(echo $user | cut -c 1)"
        echo "Group: $(echo $grupos | cut -c 1)"
        echo "Other: $(echo $otros | cut -c 1)"
    
    elif [ $2 = "w" ]; then
        echo "User: $(echo $user | cut -c 2)"
        echo "Group: $(echo $grupos | cut -c 2)"
        echo "Other: $(echo $otros | cut -c 2)"

    elif [ $2 = "x" ]; then
        echo "User: $(echo $user | cut -c 3)"
        echo "Group: $(echo $grupos | cut -c 3)"
        echo "Other: $(echo $otros | cut -c 3)"
    else
        echo "Tipo de permiso no encontrado" >&2
        exit 1
    fi

else
    echo "El archivo no existe" >&2
    exit 1
fi

