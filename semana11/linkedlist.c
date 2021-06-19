#include "linkedlist.h"
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

struct linkedlist *list_create() {
        struct linkedlist *ll = (struct linkedlist *) malloc(sizeof(struct linkedlist));
        ll->first = NULL;
        ll->last = NULL;
        ll->size = 0;
}

void add_element(struct linkedlist *ll, char *value) {

        struct lnode *ln = (struct lnode *) malloc(sizeof(struct lnode));

        ln->value = strdup(value);
        ln->next = NULL;
        (ll->size)++;

        if (ll->last == NULL) {
                ll->first = ln;
                ll->last = ln;
        } else {
                ll->last->next = ln;
                ll->last = ln;
        }
}

void delete_first(struct linkedlist *ll) {

        if (ll->size == 0)
                error(3, errno, "List has no elements");

        if (ll->size == 1) {
                ll->last = NULL;
        }

        (ll->size)--;
        struct lnode *first = ll->first;
        ll->first = ll->first->next;
        free((void *) first);
}

void print_list(struct linkedlist *ll, FILE *ofp) {

        struct lnode *ln;

        for (ln = ll->first; ln != NULL; ln = ln->next)
                fprintf(ofp, "%s", ln->value);

}

void delete_list(struct linkedlist * ll) {

        struct lnode *ln = ll->first;
        struct lnode *temp;

        if (ln == NULL)
                return;

        while(ln->next != NULL) {
                temp = ln->next;
                free((void *) ln);
                ln = temp;
        }

        free((void *) ln);
        free((void *) ll);
}