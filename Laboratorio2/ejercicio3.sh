#!/bin/bash

is_process_running() {
    ps -e -o pid | grep -q $1
}

if [ ! -x $1 ] || [ -z $1 ]; then
    echo "Formato: $0 [archivoEjecutable]"
    exit 1
fi

# Ejecutar el script en bg
./$1 &
process_id=$!

direccionArchivoLog="./CPU_memoria.txt"
echo "" > $direccionArchivoLog # Borrar contenido previo

while is_process_running $process_id; do 
    consumoCPU=$(ps -p "$process_id" -o "%cpu" --no-headers)
    consumoMemoria=$(ps -p "$process_id" -o "%mem" --no-headers)

    echo "$(date '+%D %T')  $consumoCPU $consumoMemoria" >> $direccionArchivoLog

    sleep 2
done

QT_QPA_PLATFORM=wayland
gnuplot << EOF
    # Establecer el formato de tiempo para el eje x
    set xdata time
    set timefmt "%m/%d/%y %H:%M:%S"
    set format x "%H:%M:%S"

    # Definir el archivo de datos y las columnas a utilizar
    datafile = "CPU_memoria.txt"
    x_column = 1  # Columna del tiempo en el archivo (1-based index)
    y_column = 2  # Columna de los datos x en el archivo (1-based index)

    # Configurar la gráfica
    set title "Gráfica del consumo de CPU en función del tiempo"
    set xlabel "Hora"
    set ylabel "Consumo de CPU (%)"
    set xtics font ",8"
    set grid
    set term png
    set output "grafico1.png"
    set yrange [0:100]

    # Crear la gráfica
    plot datafile using 1:3 with linespoints title "Consumo de CPU"
EOF

gnuplot << EOF
    # Establecer el formato de tiempo para el eje x
    set xdata time
    set timefmt "%m/%d/%y %H:%M:%S"
    set format x "%H:%M:%S"

    # Definir el archivo de datos y las columnas a utilizar
    datafile = "CPU_memoria.txt"
    x_column = 1  # Columna del tiempo en el archivo (1-based index)
    y_column = 3  # Columna de los datos x en el archivo (1-based index)

    # Configurar la gráfica
    set title "Gráfica del consumo de memoria en función del tiempo"
    set xlabel "Hora"
    set ylabel "Consumo de memoria (%)"
    set xtics font ",8"
    set grid
    set term png
    set output "grafico2.png"
    set yrange [0:100]

    # Crear la gráfica
    plot datafile using 1:4 with linespoints title "Consumo de memoria"
EOF

