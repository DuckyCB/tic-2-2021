#include <stdio.h>
#define HASHSIZE 101


struct nlist {
        struct nlist *next;
        char *name;
        char *defn;
};

struct nlist *hashtab[HASHSIZE];
unsigned hash (char *s);
struct nlist *lookup (char *s);
struct nlist *install (char *name, char *defn);
int getword(char *word, int lim);