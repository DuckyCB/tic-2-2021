#include "util.h"

// Returns 0 if string is not a positive integer. 1 otherwise
int my_isinteger(char *str) {

    // Check is str is a null pointer
    if (str == NULL)
        return 0;

    int zero_length = 1;

    for (; *str != '\0'; str++) {

        zero_length = 0;
        if (!isdigit(*str))
            return 0;
    }
    
    return !zero_length;
}

// Frees argv memory
void my_free(char **argv) {

    int i;

    for (i = 0; argv[i] != NULL; i++)
        free(argv[i]);
}