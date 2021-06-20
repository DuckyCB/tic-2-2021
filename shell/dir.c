#include "minish.h"
#include <dirent.h>
#include <stdio.h>

/**
* returns 1 if str is contained in long_str, 0 otherwise
**/
int contains(char *str, char *long_str) {

    for (; *long_str != '\0'; long_str++) {
        if (*str == *long_str)
            str++;

        if (*str == '\0')
            return 1;
    }

    return !(*long_str - *str);
}

/**
* print files in current directory. returns status
**/
int builtin_dir(int argc, char **argv) {

    // check number of arguments
    if (argc > 2) {
        fprintf(stderr, "Error: wrong number of arguments %d", argc - 1);
        fprintf(stderr, "Usage: dir [name]");
        return 1;
    }

    DIR *d;
    struct dirent *dir;
    d = opendir(".");

    // check if directory opened succesfully
    if (!d) {
        fprintf(stderr, "Error: could not open directory: %s\n", argv[1]);
        return 1;
    }

    // dir with no name argument passed
    if (argc == 1) { 
        while ((dir = readdir(d)) != NULL)      // prints all files in d
            printf("%s\n", dir->d_name);

        closedir(d);

        return 0;
    }

    // dir with name agrument passed
    while ((dir = readdir(d)) != NULL)
        if (contains(argv[1], dir->d_name))
            printf("%s\n", dir->d_name);

    closedir(d);

    return 0;    
}