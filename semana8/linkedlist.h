#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdio.h>

struct lnode {
        char *value;
        struct lnode *next;
};

struct linkedlist {
        struct lnode *first;
        struct lnode *last;
        int size;
};

struct linkedlist *list_create();
void add_element(struct linkedlist *, char *);
void delete_first(struct linkedlist *);
void print_list(struct linkedlist *, FILE *);
void delete_list(struct linkedlist *);

#endif