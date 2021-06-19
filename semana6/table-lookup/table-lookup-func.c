#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table-lookup.h"
#define HASHSIZE 101

char *my_strdup(char *s){
    char *p;
    p= (char *) malloc(strlen(s)+1);
    if(p!= NULL)
        strcpy(p,s);
    return p;    
}

unsigned hash (char *s)
{
        unsigned hashval;

        for (hashval = 0; *s != '\0'; s++){
                hashval = *s + 31 * hashval;
        }
        return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
        struct nlist *np;

        for (np = hashtab[hash(s)]; np != NULL; np = np->next){
                if (strcmp (s, np->name) == 0){// -> es una forma de acceder a atributos de struct
                        return np;
                }
        }
        return NULL;
}


struct nlist *install(char *name, char *defn)
{
        struct nlist *np;
        unsigned hashval;
        if ((np = lookup (name)) == NULL)
        {
                np = (struct nlist *)malloc(sizeof(*np));

                if (np == NULL || (np->name = my_strdup(name)) == NULL)
                {
                    return NULL;
                }
                hashval = hash(name);
                np->next = hashtab[hashval];
                hashtab[hashval] = np;
        }else{
            free ((void *) np->defn);
        }
        if ((np->defn = my_strdup(defn)) == NULL)
        {
            return NULL;
        }
        return np;
}

void undef(char *s)
{
    struct nlist *np1, *np2;
    unsigned hashval = hash(s);

    for (np1 = hashtab[hashval], np2 = NULL; 
         np1 != NULL;
         np2 = np1, np1 = np1->next) {
        if (strcmp(s, np1->name) == 0) {
                /* found a match */
                free(np1->name);
                free(np1->defn);
                if (np2 == NULL) 
                /* at the beginning? */
                hashtab[hashval] = np1->next;
                else 
                /* in the middle or at the end? */
                np2->next = np1->next;
                free(np1);
                return;
        }
    }
}