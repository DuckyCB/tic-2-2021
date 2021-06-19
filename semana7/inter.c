#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 32

/* simple compare function for qsort, returns 
   less than 0 if char 'b' is larger than char 'a',
   a positiver number if 'a' is larger than 'b', and
   zero if they are equal (note: you can return 
   'b' - 'a' to sort in reverse order.)
*/
int compare_char (const void *a, const void *b) {
    if (*(char *)a != *(char *)b)
        return *(char *)a - *(char *)b;

    return 0;
}

int main (void) {

    char word[MAXS]   = {0};
    char sorted[MAXS] = {0};

    printf ("\n Enter a string: ");         /* read word from stdin   */
    if (!scanf ("%31[^\n]%*c", word)) {
        printf ("  [ctrl+d] received\n\n");
        return 1;
    }

    /* copy word to sorted before sort */
    strncpy (sorted, word, sizeof word);

    /* sort the chars in sorted[] */
    qsort (sorted, strlen (word), sizeof *word, compare_char);

    /* print results */
    printf ("\n word   : %s\n sorted : %s\n\n", word, sorted);

    return 0;
}