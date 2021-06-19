#include "minish.h"

int builtin_history(int argc, char **argv) {
    char path[MAXCWD];
    strcat(path, getenv("HOME"));
    strcat(path, HISTORY_FILE);
    FILE *fptr;
    fptr = fopen(path,"r");
    if (fptr != NULL) {
        int n_to_print = (argc > 1) ? atoi(argv[1]) : 10;
        int n = 0;
        for (char c = fgetc(fptr); c != EOF || n < n_to_print; 
                c = fgetc(fptr), n = (c == '\n') ? n++ : n) {
            putchar(c);
        }
    } else {
        printf("F");
        return 1;
    }
    fclose(fptr);
    return 0;
}
