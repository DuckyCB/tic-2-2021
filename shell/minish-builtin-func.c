#include "minish.h"
#include <grp.h>

/*
>help (command)
Displays help for a command.
*/
int builtin_help (int argc, char **argv){
    struct builtin_struct *node;
    // Verifica que el comando tenga 1 parametro
    if (argc == 2){
        if ((node = builtin_lookup(argv[1]))) {
            printf("%s \n", node->help_txt);
            return 0;
        } else {
            printf("No se encontró el comando %s \n", argv[1]);
            return 1;
        }
    }
    printf("Uso: help [cd|dir|exit|help|getenv|pid|setenv|status|uid|unsetenv]\n");
    return 0;
}

/*
>pid
Displays process id.
*/
int builtin_pid (int argc, char **argv){
    UNUSED(argc);
    UNUSED(argv);

    printf("pid: %d, ppid: %d \n", getpid(), getppid());
    return 0;
}

/*
>uid
Displays the user's id, name and information .
*/
int builtin_uid (int argc, char **argv){
    UNUSED(argc);
    UNUSED(argv);

    struct passwd *pws;
    pws = getpwuid(geteuid());
    printf("Uid: %d\nName: %s\nInfo: '%s'\n",pws->pw_uid, pws->pw_name, pws->pw_gecos);
    return 0;
}


/*
>gid
Displays the user's primary and secondary groups. 
*/
int builtin_gid (int argc, char **argv){
    UNUSED(argc);
    UNUSED(argv);

    struct passwd *pw;
    pw = getpwuid(geteuid());
    int ngroups = 0;
    
    getgrouplist(pw->pw_name, pw->pw_gid, NULL, &ngroups);
    __gid_t groups[ngroups];
    getgrouplist(pw->pw_name, pw->pw_gid, groups, &ngroups);
    
    register gid_t gid = getgid();
    register struct group *grp;
    grp = getgrgid(gid);
    
    printf("Real Gid: %d(%s)\nGroups: ",gid, grp->gr_name);
    for (int i = 0; i < ngroups; i++){
        grp = getgrgid(groups[i]);
        if(grp == NULL){
        perror("getgrgid error: ");
        }
        if (i + 1 == ngroups){
            printf("%d(%s)\n", grp->gr_gid, grp->gr_name);
            return 0;
        }
        printf("%d(%s), ", grp->gr_gid, grp->gr_name);
    }
    return 0;
}

extern char **environ;
/*
>getenv var (var1 var2 …)
Displays the path of the environment variables.
*/
int builtin_getenv (int argc, char **argv){
    int toReturn = 0;
    if (argc != 1) {
        for (int i = 1; i < argc; i++){
            if (getenv(argv[i])){
                printf("%s = %s\n", argv[i], getenv(argv[i]));
            } else {
                fprintf(stderr,"Error obteniendo variable de ambiente \"%s\": %d\n", argv[i], errno);
                toReturn = 1;
            }
        }
    } else {
        for(char **current = environ; *current; current++) {
            puts(*current);
        }
    }
    return toReturn;
}


/*
>setenv name PATH
Creates new environment variable.
If it already exists, changes PATH.
*/
int builtin_setenv(int argc, char **argv) {
    if (argc != 3) {
        printf("Error: cantidad incorrecta de argumentos\n");
        printf("Use: setenv var val\n");
        return 1;
    }
    return setenv(argv[1], argv[2], 1);
}

/*
>unsetenv var (var1 var2 …)
Deletes existing environment variables.
*/
int builtin_unsetenv (int argc, char **argv){
    int toReturn = 0;
    if (argc > 1){
        for (int i = 1; i < argc; i++){
            if (getenv(argv[i])){
                unsetenv(argv[i]);
                printf("%s unset\n", argv[i]);
            } else {
                printf("%s no es variable de ambiente\n", argv[i]);
                toReturn = 1;
            }
        }
    } else {
        printf("Debe pasar al menos una variable de ambiente como argumento\n");
        return 1;
    }
    return toReturn;
}

/*
>cd (dir, -)
Cambia el directorio.
*/
int builtin_cd (int argc, char **argv){
    if (argc == 2) {
        char path[MAXCWD];
        strcpy(path,argv[1]);
        char cwd[MAXCWD];
        if(argv[1][0] != '/')
        {// true for the dir in cwd
            if(argv[1][0] == '-'){
                getcwd(cwd,sizeof(cwd));
                chdir(getenv("OLDPWD"));
                setenv("OLDPWD", cwd, 1);
                return 0;
            }
            getcwd(cwd,sizeof(cwd));
            setenv("OLDPWD", cwd,1);
            strcat(cwd,"/");
            strcat(cwd,path);
            chdir(cwd);
            return 0;
        } 
        chdir(path);
        return 0;
    }
    if (argc == 1){
        chdir(getenv("HOME"));
        return 0;
    }
    printf("Use help cd para ver el funcionamiento de cd\n");
    return 1;
}

/*
>status
Muestra el estado de retorno del último comando ejecutado.
*/
int builtin_status (int argc, char **argv){
    UNUSED(argc);
    UNUSED(argv);

    printf("%d\n", globalstatret);
    return 0;
}
