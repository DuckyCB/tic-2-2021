#include "dir.h"
#include <stdio.h>

int main() {

    int argc = 1;
    char *argv[2];
    argv[0] = "dir";
    argv[1] = "ma";
    return builtin_dir(argc, argv); 
}