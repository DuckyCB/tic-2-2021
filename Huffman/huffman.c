#include <stdio.h>
#include "huffman.h"

struct chars_freq {
    int qty;    // quantity
    char *c;    // character
};


/*
Recibe un array de tuplas y un archivo. 
Lee caracter por caracter y cuenta la cantidad de veces que se repite cada caracter.
Guarda la informacion en el array de tuplas.
*/
int count_chars(struct chars_freq *chars_freq, FILE *file_original) {
    return 1;
}


/*
Recibe un array de tuplas.
Cuenta la cantidad de tuplas no nulas que hay.
Devuelve el tamaño real del array.
*/
int count_non_null(struct chars_freq *chars_freq) {
    int size = 0;
    return size;
}


int main(int argc, char **argv) {
    if (argc > 1) {

        // Toma el argumento con el nombre del archivo e intenta abrirlo
        char *path[255] = argv[1];
        FILE *file_original;
        file_original = fopen_or_exit(path,"r");

        // Analizar todo el file y crear un array con los caracteres mas usados y su frecuencia
        struct chars_freq chars_freq[MAXSYMBOL];
        count_chars(chars_freq, file_original);
        int size = count_non_null(chars_freq);

        // Guarda los valores del array chars_freq en un heap
        int heap_len = sizeof(chars_freq)/sizeof(struct chars_freq);

        // Crear un arbol binario asignando una hoja a cada caracter segun su uso
        // Mapear cada caracter a un numero binario
        // Crear un nuevo archivo guardando los numeros binarios correspondientes
        fclose(file_original);
    } else {
        print("Es necesario elegir un archivo para comprimir");
    }
    return 0;
}
