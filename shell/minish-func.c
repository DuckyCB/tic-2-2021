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

int linea2argv(char *linea, int argc, char **argv) {
    int nword = 0;
    char *word;
    int new_word = 0;
    int i;
    int wpos = 0;

    for (i = 0; linea[i] != '\0' && linea[i] != '\n' && nword < argc; i++) {


        if (linea[i] != ' ' && linea[i] != '\t') {
            word[wpos++] = linea[i];
            new_word = 1;
        } else if (new_word == 1) {
            word[wpos] = '\0';
            wpos = 0;
            argv[nword++] = strdup(word);
            new_word = 0;
        }
    }

    if (new_word == 1)
        argv[nword++] = strdup(word);

    argv[nword] = NULL;
    return nword;

    // for (int n=0; linea[n] != '\n' && linea[n] != '\0'; n++) {
    //     // Fin de palabra (verifica que haya una palabra antes)
    //     if ((linea[n] == ' ' || linea[n] == '\t') && first_word == 1) {
            
    //         *(argv + nword++) = word;
    //         word = NULL;
    //     } else {
    //         c = (linea[n] == '\'' || linea[n] == '\"') ?  ' ' : linea[n]; 
    //         *word++ = c;
    //         first_word = 1;
    //     }
    // }
    // argc = nword;
    // *(argv + nword) = NULL;
    // return nword;
}

int ejecutar(int argc, char **argv) {
    int toReturn = 0;
    if (builtin_lookup(argv[0]) != NULL) {
        toReturn = (builtin_lookup(argv[0])->func)(argc, argv);      
    } else {
        toReturn = externo(argc, argv);
    }
    globalstatret = toReturn;
    return toReturn;
}


int externo(int argc, char **argv) {
    pid_t ch_pid = fork();
    errno = 0;
    // Child process creation unsuccessful
    if (ch_pid == -1) {
        perror("fork");
    // Returned to the newly created child process
    } else if (ch_pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execve");
            char cwd[200];
            getcwd(cwd, sizeof(cwd));
            printf("%s> ", cwd );
        }
        exit(0);
    // Returned to parent or caller
    } else { // ch_pid == 1
        printf("spawn child with pid - %d\n", ch_pid);
        return ch_pid;
    }

    return errno;
}

