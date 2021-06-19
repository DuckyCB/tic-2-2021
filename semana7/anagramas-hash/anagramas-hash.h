
#include <stdio.h>
#include <stdlib.h>

#define MAXWORD     32
#define HASHSIZE    10457   // un número primo lejano a una potencia de 2
#define DICT        "/usr/share/dict/spanish"
/*
 * fgetword_normalizada: lee una palabra en español de un archivo, la normaliza
 * (saca tildes y eñes y las convierte en vocales y enes)
 * retorna NULL si no hay más palabras
 */
extern char *fgetword_normalizada (FILE *fp, char *word, int maxword);

/*
 * fgetword_lower_alpha_normal: similar a fgetword_normalizada pero retorna word
 * que tiene solamente minúsculas, eliminando cualquier carácter no alfabético
 */
extern char *fgetword_lower_alpha_normal(FILE *fp, char *word, int maxword);
    // invoca a fgetword_normalizada, convierte word a una palabra
    // que tiene solamente minúsculas, eliminando cualquier carácter no alfabético
    // retorna NULL si no hay más palabras

struct list {               // lista enlazada simple
    int qty;                // cantidad de elementos de la lista
    struct listnode *first, *last;  // punteros al nodo comienzo y nodo final
};

struct hashnode {           // nodo de una lista enlazada simple
    char *key;              // clave asociada a este nodo
    struct list *wlist;     // lista de palabras asociadas a esta clave
    struct hashnode *next;  // siguiente de la lista o NULL si es el último
};

struct listnode {           // nodo de una lista enlazada simple
    char *word;             // palabra asociada a este nodo
    struct listnode *next;  // siguiente de la lista o NULL si es el último
};


struct hashnode *anagrams[HASHSIZE];

extern unsigned int hash(char *str);
    // genera un número único (grande) asociado al string

/*
 *
 * DE ACÁ ADELANTE ESTÁN LAS FUNCIONES QUE DEBEN DESARROLLAR LOS ESTUDIANTES
 *
 */

extern struct list *list_create(void);


extern struct list *list_insert_last_word(struct list *l, char *word);


extern struct hashnode *hash_insert_word(struct hashnode *node, char *key, char *word);

    // busca key en el hash (y si no encuentra inserta key al inicio en lista simple)
    // luego agrega palabra al final de la lista de anagramas asociadas a la key
    // retorna siempre el primero de la lista: node si key estaba o el nuevo nodo si se insertó

extern char *sort_word(char *word);
    // ordena EN EL LUGAR la palabra 'word' según código ASCII en forma ascendente

extern void print_anagrams(struct hashnode *hn);
    // escribe (printf) la lista de anagramas para ese hashnode
