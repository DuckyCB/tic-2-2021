#include "minish.h"
#include "util.h"

int builtin_history(int argc, char **argv) {

    // line variables definitions
    char *line;
    size_t len;
    int nlinesread = 0;
    int ft, i = 0;
    int c;

    // Set max number of lines to read
    int n_to_print = 10;
    if (argc > 1 && my_isinteger(argv[1]))
        n_to_print = atoi(argv[1]);

    // history file path
    char path[MAXCWD];
    *path = '\0';
    strcat(path, getenv("HOME"));
    strcat(path, "/");
    strcat(path, HISTORY_FILE);

    // read history file
    FILE *fptr;
    fptr = fopen(path,"r");

    // could not open file
    if (fptr == NULL)
        return 1;


    fseek(fptr, 0, SEEK_END);
    ft = ftell(fptr);
    while (nlinesread <= n_to_print && ++i < ft)
    {
        fseek(fptr, -i, SEEK_END);
        if (fgetc(fptr) == '\n')
            nlinesread++;
    }

    if (i != ft)
        fseek(fptr, -i+1, SEEK_END);
    
    while ((c = fgetc(fptr)) != EOF)
        putchar(c);

    fclose(fptr);

    return 0;

}
