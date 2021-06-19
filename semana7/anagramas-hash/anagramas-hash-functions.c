#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anagramas-hash.h"
#include "wrappers.h"

extern struct list *list_create(){
	struct list *l;
	l = (struct list*) malloc_or_exit(sizeof(struct list));
	l -> qty = 0;
	l -> first = NULL;
	l -> last = NULL;
	return l;
}


extern struct list *list_insert_last_word(struct list *l, char *word) {
	struct listnode *new_node;
	new_node = (struct listnode*) malloc_or_exit(sizeof(struct listnode));
	new_node -> word = strdup_or_exit(word);
	new_node -> next = NULL;

	if (l == NULL) {
		l = list_create();
		l -> first = new_node;
	} else {
        l -> last -> next = new_node;
    }
	l -> last = new_node;
	l -> qty++;
    return l;
}


extern struct hashnode *hash_insert_word(struct hashnode *node, char *key, char *word) {
    struct hashnode *new_hashnode = (struct hashnode*) malloc_or_exit(sizeof(struct hashnode));
    new_hashnode -> key = strdup_or_exit(key);
    struct list *l = NULL;
    new_hashnode -> wlist = list_insert_last_word(l, word);
    new_hashnode -> next = NULL;
    if (node != NULL) {
        struct hashnode *actual_node = node;
        struct hashnode *previous_node = NULL;
        while (actual_node != NULL) {
            if (strcmp(actual_node -> key, key) == 0) {
                list_insert_last_word(actual_node->wlist, word);
                return node;
            }
            previous_node = actual_node;
            actual_node = actual_node -> next;
        }
        previous_node -> next = new_hashnode;
        return node;
    }
    return new_hashnode;
}

    // busca key en el hash (y si no encuentra inserta key al inicio en lista simple)
    // luego agrega palabra al final de la lista de anagramas asociadas a la key
    // retorna siempre el primero de la lista: node si key estaba o el nuevo nodo si se insertó

int compare_char(const void *a, const void *b) {
    if (*(char *)a != *(char *)b)
        return *(char *)a - *(char *)b;
    return 0;
}

char *sort_word(char *word) {
	qsort(word, strlen(word), sizeof *word, compare_char);
    return word;
}
    // ordena EN EL LUGAR la palabra 'word' según código ASCII en forma ascendente

extern void print_anagrams(struct hashnode *hn) {
    int i;
    struct listnode *principio = hn->wlist->first;
    for (i = 0; principio != NULL; i++)
    {
        printf("%s%c", principio->word, principio->next != NULL ? ',' : '\n');
        principio = principio->next;
    }
}
    // escribe (printf) la lista de anagramas para ese hashnode
