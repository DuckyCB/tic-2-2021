#include <stdio.h>
#include "huffman.h"

struct chars_freq {
    int freq;   // frequency
    char *c;    // character
};

struct MinHeapNode {
	char data;
	unsigned freq;
	struct MinHeapNode *left, *right;
};

struct MinHeap {
	// Current size of min heap
	unsigned size;
	// capacity of min heap
	unsigned capacity;
	// Array of minheap node pointers
	struct MinHeapNode** array;
};


int heap_min_compare(const void *p, const void *q) {
    // compara POR MENOR dos estructuras heap *p y *q, de acuerdo a su campo freq
    const struct chars_freq *hp = p, *hq = q;
    return hp->freq < hq->freq;
}


/*
Recibe un array de tuplas y un archivo. 
Lee caracter por caracter y cuenta la cantidad de veces que se repite cada caracter.
Guarda la informacion en el array de tuplas.
*/
void count_chars(struct chars_freq *chars_freq, FILE *file_original) {
    
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
        struct chars_freq chars_freq[MAXSYMBOL];
        count_chars(chars_freq, file_original);
        int size = count_non_null(chars_freq);

        // Guarda los valores del array chars_freq en un heap y los ordena en lugar
        int heap_len = sizeof(chars_freq)/sizeof(struct chars_freq);

        // build_heap(chars_freq, heap_len, sizeof(struct chars_freq), heap_min_compare);
        for (int i=0; i<heap_len; i++) {
            heap_bubbleup(chars_freq, heap_len, sizeof(struct heap), i, heap_min_compare);
        }


        // Crear un arbol binario asignando una hoja a cada caracter segun su uso
        // Mapear cada caracter a un numero binario
        // Crear un nuevo archivo guardando los numeros binarios correspondientes
        fclose(file_original);
    } else {
        print("Es necesario elegir un archivo para comprimir");
    }
    return 0;
}
