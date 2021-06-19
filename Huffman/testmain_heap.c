#include <stdio.h>
#include "heap_generic.h"

struct heap {
    int prio;       // prioridad (se ordena por este campo)
    char *texto;    // puede alojar cualquier cosa - referencia nada más
};

int
heap_min_compare(const void *p, const void *q)
{
    // compara POR MENOR dos estructuras heap *p y *q, de acuerdo a su campo prio
    const struct heap *hp = p, *hq = q;
    return hp->prio < hq->prio;
}

int
heap_max_compare(const void *p, const void *q)
{
    // compara POR MAYOR dos estructuras heap *p y *q, de acuerdo a su campo prio
    const struct heap *hp = p, *hq = q;
    return hp->prio > hq->prio;
}

int
main(void)
{
    struct heap A[] = {
        { 3, "caminar" },
        { 0, "INICIO" },
        { 4, "no comer postre" },
        { 6, "leer un libro" },
        { 5, "levantar pesas" },
        { 7, "usar las escaleras" },
        { 2, "desayunar fuerte" },
        { 1, "dormir bien" },
        { 99, "FIN" },
        { 5, "salir a correr" },
        { 9, "hacer un ejemplo de heap" }
    };

    int heaplen = sizeof(A)/sizeof(struct heap);

    int (*compar)(const void *, const void *);

    compar = heap_min_compare; // elegir de acuerdo a minheap o maxheap
    // compar = heap_max_compare; // elegir de acuerdo a minheap o maxheap

    for (int i=0; i<heaplen; i++) {
        printf("i = %3d, prio = %3d, texto = %s\n", i, A[i].prio, A[i].texto);
    }

    // build_heap(A, heaplen, sizeof(struct heap), compar);
    // el siguiente for es alternativo a build_heap
    for (int i=0; i<heaplen; i++) {
        heap_bubbleup(A, heaplen, sizeof(struct heap), i, compar);
    }

    printf("-----\n");

    for (int i=0; heaplen>0; i++, heaplen--) {
        printf("i = %3d, prio = %3d, texto = %s\n", i, A[0].prio, A[0].texto);
        swap_heap_elem(A, heaplen, sizeof(struct heap), 0, heaplen-1);
        heap_bubbledown(A, heaplen-1, sizeof(struct heap), 0, compar);
    }
}
