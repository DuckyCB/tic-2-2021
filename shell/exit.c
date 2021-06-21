#include "minish.h"
#include "util.h"
#include <ctype.h>
#include <stdlib.h>

int builtin_exit(int argc, char **argv) {

    // No arguments passed or argument is not a number. Exit status is last command's return status.
    if (argc == 1 || !my_isinteger(argv[1])) {
        my_free(argv);
        exit(globalstatret);
    }

    int status = atoi(argv[1]);
    my_free(argv);

    // Exit status is argument's value
    exit(status);

}
