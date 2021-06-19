#ifndef MINISH_FUNC
#define MINISH_FUNC

#define HELP_CD      "cd [..|dir] - cambia de directorio corriente"
#define HELP_DIR     "dir [str]- muestra archivos en directorio corriente, que tengan 'str'"
#define HELP_EXIT     "exit [status] - finaliza el minish con un status de retorno (por defecto 0)"
#define HELP_GETENV   "getenv var [var] - muestra valor de variable(s) de ambiente"
#define HELP_GID      "gid - muestra el grupo principal y los grupos secundarios del usuario"
#define HELP_HELP     "help [cd|dir|exit|help|history|getenv|pid|setenv|status|uid]"
#define HELP_HISTORY  "history [N] - muestra los últimos N (10) comandos escritos"
#define HELP_PID      "pid - muestra Process Id del minish"
#define HELP_SETENV   "setenv var valor - agrega o cambia valor de variable de ambiente"
#define HELP_STATUS   "status - muestra status de retorno de ultimo comando ejecutado"
#define HELP_UID      "uid - muestra nombre y número de usuario dueño del minish"
#define HELP_UNSETENV "unsetenv var valor - elimina variables de ambiente"


struct builtin_struct * builtin_lookup(char *cmd);

int linea2argv(char *linea, int argc, char **argv);

int ejecutar(int argc, char **argv);

int externo(int argc, char **argv);

#endif