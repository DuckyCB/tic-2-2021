#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_char(const void *a, const void *b) {
    if (*(char *)a != *(char *)b)
        return *(char *)a - *(char *)b;
    return 0;
}


char *sort_word(char *word) {
	qsort(word, strlen(word), sizeof *word, compare_char);
}

int main() {
    char s[] = "decbaa";
    //printf("%d", compare_chars(c, d));
    printf("\n");
    printf(s);
    printf("\n");
    sort_word(s);
    printf(s); 
}