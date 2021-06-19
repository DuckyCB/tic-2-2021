#include <stdio.h>
#include "huffman.h"

int main(int argc, char **argv) {
    if (argc > 1) {
        char *path[255] = argv[1];
        FILE *file_original;
        file_original = fopen(path,"r");
        fclose(file_original);
    } else {
        print("Es necesario elegir un archivo para comprimir");
    }
    return 0;
}
