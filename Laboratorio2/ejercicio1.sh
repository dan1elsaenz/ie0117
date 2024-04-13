#!/bin/bash

# El argumento $1 representa el PID del proceso

#Verificar que se escriba un argumento
if [ -z $1 ]; then
    echo "Formato: $0 [PID]" # Formato del script
    exit 1 # Codigo de error

else
    pid=$1 # Valor de primer parametro a variable PID

    # Se guardan todas las salidas en el archivo infoProceso.txt
    
    nombreProceso=$(ps -p $pid -o comm --no-headers) # COMMAND indica nombre
    echo "Nombre: $nombreProceso" > infoProceso.txt

    echo "Process ID: $pid" >> infoProceso.txt

    ppid=$(ps -p $pid -o ppid --no-headers) # Parent process ID
    echo "ID del proceso padre: $ppid"  >> infoProceso.txt

    user=$(ps -p $pid -o user --no-headers) # usuario propietario
    echo "Usuario propietario del proceso: $user" >> infoProceso.txt

    porcentajeCPU=$(ps -p $pid -o %cpu --no-headers) # Porcentaje de CPU
    echo "%CPU: $porcentajeCPU" >> infoProceso.txt

    consumoMemoria=$(ps -p $pid -o %mem --no-headers) # Consumo de memoria
    echo "Memoria consumida: $consumoMemoria" >> infoProceso.txt

    estado=$(ps -p $pid -o stat --no-headers) # Estado del proceso
    echo "Estado: $estado" >> infoProceso.txt

    pathEjecutable=$(readlink "/proc/$pid/exe") # Leer el link simbolico en el directorio /proc
    echo "Path del ejecutable: $pathEjecutable" >> infoProceso.txt
fi

