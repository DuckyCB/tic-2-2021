#include <stdio.h>
#include "table-lookup.h"
#define MAXWORD 100


void undef (char*);
int main()
{
    char str_nword[MAXWORD];
    char word[MAXWORD];
    int nword, i;
    struct nlist *np, *aux;
    
    nword = 1; 
    while (getword(word, MAXWORD) != EOF) {

        if (isalpha(word[0])) {
            snprintf(str_nword, MAXWORD, "%d", nword);
            if (install(word, str_nword) == NULL) {
                fprintf(stderr, "Error en install\n");
            }
        }
        nword++;
    }
    for (i=0; i<HASHSIZE; i++) {
        np = hashtab[i];
        while (np != NULL) {
            printf("%s: %s\n", np->name, np->defn);
            aux = np->next; // guardo np->next antes de hacer undef
            undef(np->name);
            np = aux;
        }
    }
}