#!/bin/bash

declare -a array # Crear estructura array

for ((i=0; i<1000000; i++)); do
    array[i]=$i # Añadir elemento por elemento del for al array
done

while true; do # No acabar el proceso para poder graficar los datos
    sleep 1
done
