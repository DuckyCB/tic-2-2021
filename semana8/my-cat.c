/*
    Copia de archivos
    Símil cat, usando argumentos en la línea de comandos
    maneja errores con la función error(3) - no es del libro K&R
    K&R - 7.6
*/

#include <stdio.h>
#include <stdlib.h>             // requerida por función exit
#include <error.h>
#include <errno.h>              // acá está definida la variable externa errno
#include <locale.h>

void
filecopy(FILE *ifp, FILE *ofp)  // copia archivo ifp a archivo ofp
{
    int c;

    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}


int
main(int argc, char *argv[])
{
    FILE *fp;               // tipo declarado en stdio.h, al igual que stdin y stdout
    //char *prog = argv[0];   // nombre del programa para errores

    setlocale(LC_MESSAGES, "");

    if(argc == 1) {         // sin argumentos en la línea de comandos, copia stdin
        filecopy(stdin, stdout);
    } else {                // con argumentos, abre cada uno de los archivos
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {   // chequea retorno exitoso de fopen

                error(1, errno, "error in fopen '%s'", *argv);
                // fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                // exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }

    if (ferror(stdout)) {
        error(2, errno, "error writing stdout");
        // fprintf(stderr, "%s: error writing stdout\n", prog);
        // exit(2);
    }

    exit(0);
}