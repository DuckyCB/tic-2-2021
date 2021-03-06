#include "minish.h"
#include "minish-func.h"

struct builtin_struct builtin_arr[] = {
    { "cd", builtin_cd, HELP_CD },
    { "dir", builtin_dir, HELP_DIR},
    { "exit", builtin_exit, HELP_EXIT},
    { "getenv", builtin_getenv, HELP_GETENV},
    { "gid", builtin_gid, HELP_GID},
    { "help", builtin_help, HELP_HELP},
    { "history", builtin_history, HELP_HISTORY},
    { "pid", builtin_pid, HELP_PID},
    { "setenv", builtin_setenv, HELP_SETENV},
    { "status", builtin_status, HELP_STATUS},
    { "uid", builtin_uid, HELP_UID },
    { "unsetenv", builtin_unsetenv, HELP_UNSETENV},
    { NULL, NULL, NULL }
};

struct builtin_struct * builtin_lookup(char *cmd) {
    for (int i = 0; builtin_arr[i].cmd != NULL; i++) {
        if (strcmp(cmd, builtin_arr[i].cmd) == 0) {
            return &builtin_arr[i];
        }
    }
    return NULL;
}

/*
Gets a line, splits it in words and counts them.
*/
int linea2argv(char *linea, int argc, char **argv) {
    int nword = 0;
    char word[MAXLINE];
    int new_word = 0;
    int i;
    int wpos = 0;

    // Reads each char
    for (i = 0; linea[i] != '\0' && linea[i] != '\n' && nword < argc; i++) {

        // Creates new word
        if (linea[i] != ' ' && linea[i] != '\t') {
            word[wpos++] = linea[i];
            new_word = 1;
        // Adds char to existing word
        } else if (new_word == 1) {
            word[wpos] = '\0';
            wpos = 0;
            argv[nword++] = strdup(word);
            new_word = 0;
        }
    }

    if (new_word == 1) {
        word[wpos] = '\0';
        argv[nword++] = strdup(word);
    }

    argv[nword] = NULL;
    return nword;
}
/*
Tries to execute internal command,
executes external command otherwise.
*/
int ejecutar(int argc, char **argv) {
    int toReturn = 0;

    if (argc == 0)
        return 0;

    // history file path
    char path[MAXCWD];
    *path = '\0';
    strcat(path, getenv("HOME"));
    strcat(path, "/");
    strcat(path, HISTORY_FILE);

    // append command to history file
    FILE *fptr;
    fptr = fopen(path,"a");
    if (fptr == NULL)
        fprintf(stderr, "Error: Fallo al intentar abrir archivo de historial\n");
    else {
        fprintf(fptr, "%s\n", argv[0]);
        fclose(fptr);
    }

    // Execute command
    if (builtin_lookup(argv[0]) != NULL) {
        toReturn = (builtin_lookup(argv[0])->func)(argc, argv);      
    } else {
        toReturn = externo(argc, argv);
    }
    globalstatret = toReturn;
    return toReturn;
}


// Execute external command
int externo(int argc, char **argv) {
    UNUSED(argc);

    pid_t ch_pid = fork();
    int status = 0;

    // Child process creation unsuccessful
    if (ch_pid == -1) {
        perror("fork");
        return 1;
    }
    
    // Child process
    if (ch_pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execve");
        }
        exit(EXIT_FAILURE);
    }

    // Wait for child process to complete
    waitpid(ch_pid, &status, 0);
    if (WIFEXITED(status))
        status = WEXITSTATUS(status);

    return status;
}

