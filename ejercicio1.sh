#! /bin/bash

get_permissions_verbose() {
    permisosformatted=""
    for (( i=1; i<=${#1}; i++ )); do
        p=$(echo $1 | cut -c $i) # Extraer un permiso por ejecucion
        
        # Concatenar por cada case
        case $p in 
            "r")
                permisosformatted="${permisosformatted}read"
                ;;
            "w")
                permisosformatted="${permisosformatted},write"
                ;;
            "x")
                permisosformatted="${permisosformatted},execute"
                ;;
        esac
    done

    if [ -z $permisosformatted ]; then
        # Si esta vacia
        permisosformatted="none"
    fi

    echo "$2:$permisosformatted"
}

if [ -z $1 ]; then
    echo -e "Ingrese dos parametros\nFormato: ./ejercicio1.sh [nombreArchivo]" >&2
    exit 1

elif [ -e $1 ]; then
    permisos="$(stat -c "%A%" $1)" # Obtener permisos
    permisos=$(echo $permisos | cut -c2-) # Quitar el primer caracter

    # Cortar en permisos en trios
    permisos_user=$(echo $permisos | cut -c 1-3)
    permisos_group=$(echo $permisos | cut -c 4-6)
    permisos_other=$(echo $permisos | cut -c 7-9)

    # Llamar funciones
    get_permissions_verbose $permisos_user "User"
    get_permissions_verbose $permisos_group "Group"
    get_permissions_verbose $permisos_other "Other"

else
    echo "El archivo no existe" >&2
    exit 1
fi
