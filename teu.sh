#!/bin/bash

output_file="todo_en_uno.cpp"
echo "" > $output_file  # Limpia el archivo anterior si existe

for file in *.cpp *.h; do
    if [ -f "$file" ]; then
        echo -e "\n// === Comienzo de $file ===\n" >> $output_file
        cat "$file" >> $output_file
        echo -e "\n// === Fin de $file ===\n" >> $output_file
    fi
done

echo "¡Todos los archivos combinados en $output_file!"
