#include <stdio.h>
#include "huffman.h"
#include "huffman_func.h"


/**
 * @brief Creates an array of Symcode with each symbol and its count
 * 
 * @param file_original File
 * @return char* Symcode array
 */
char* count_chars(FILE *file_original) {
    char* array[MAXSYMBOL];
    // code
    return array;
}



/*
PUTO EL QUE LEE
Ahora que tengo tu atencion, no puse ningun malloc ni ninguna de esas
basuras de C. gg izi 
Mirar testmain_heap.c y test.c que hay ejemplos
*/
int main(int argc, char **argv) {
    if (argc > 1) {

        // Toma el argumento con el nombre del archivo e intenta abrirlo
        char *path[255] = argv[1];
        FILE *file_original;
        file_original = fopen_or_exit(path,"r");

        // Analizar todo el file y crear un array con los caracteres mas usados y su frecuencia

        // Guarda los valores del array chars_freq en un heap y los ordena en lugar

        // build_heap(chars_freq, heap_len, sizeof(struct chars_freq), heap_min_compare);


        // Crear un arbol binario asignando una hoja a cada caracter segun su uso
        // Mapear cada caracter a un numero binario
        // Crear un nuevo archivo guardando los numeros binarios correspondientes
        fclose(file_original);
    } else {
        print("Es necesario elegir un archivo para comprimir");
    }
    return 0;
}
