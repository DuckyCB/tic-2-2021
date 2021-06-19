#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
//#include <error.h>
#define MAXLINE 1000
#define DEFAULT_LINES 10


void filecopy(FILE *ifp, FILE *ofp, int limit)  // copia archivo ifp a archivo ofp
{
    int c, lines = 0;
    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
        
        if((c == '\n') ? ++lines == limit : 0){
            break;
        }
    }
}


int myisdigit(char* str){
    while (*str != '\0')
    {
        if (!isdigit(*str)){
            return 0;
        }
        str++;
    }
    return 1;
};

int main(int argc, char *argv[] )
{
    int limit, j, i, primerfile = 1;
    limit = 10;
    FILE *files[10] = { NULL };
    
    if (argc == 1){
        filecopy(stdin,stdout, limit);
        exit(0);
    }
   
    if(*argv[1] == '-'){
        if (myisdigit(argv[1] + 1)){
            limit = atoi((argv[1] + 1));
        } else {
            printf("Parámetro inválido: %s \n", *(++argv));
            exit(1);
        }
        if(argc == 2){
            filecopy(stdin,stdout, limit);
            exit(0);
        }
        primerfile = 2;
    }

    for (i = 0, j = 0; argv[i + primerfile] != NULL && j < MAXLINE; i++, j++){
        FILE *file = fopen(argv[primerfile + i], "r");
        if (! file){
            printf("Error abriendo archivo %s \n", argv[primerfile + i]);
            exit(1);
        }
        files[j] = file;
    }
    putchar('\n');
    for(i = 0; files[i] != NULL; i++){
        if (files[i] != NULL){
            printf("===> %s <=== \n", argv[primerfile + i]);
            filecopy(files[i], stdout, limit);
            putchar('\n');
            fclose(files[i]);
        }
    }
}