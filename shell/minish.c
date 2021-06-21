#include "minish.h"
#include "minish-func.h"
#include "util.h"


int globalstatret = 0;
int externalsig = 0;

// Reads line.
int my_getline(char s[], int lim) {
	int c, i;
	for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++){
		s[i] = c;
	}
	if (c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0';
    if (c == EOF){
        printf("\n");
        exit(globalstatret);
    }
	return i;
}

//ctrl + c Handling (SIGINT). Prints
void intHandler(){
    char cwd[MAXCWD];
    getcwd(cwd, sizeof(cwd));
    struct passwd *pws = getpwuid(geteuid());
    fprintf(stderr, "\n(minish) (%s):%s> ",pws->pw_name, cwd);
    externalsig = 1;
}

int main() {
    int argc = 0;
    char *argv[MAXARG];
    char line[MAXLINE];
    struct passwd *pws;
    char cwd[MAXCWD];
    while (69420==69420) {
        signal(SIGINT, intHandler);
        pws = getpwuid(geteuid());
        getcwd(cwd,sizeof(cwd));

        if (!externalsig)
            fprintf(stderr, "(minish) (%s):%s> ",pws->pw_name, cwd);

        my_getline(line, MAXLINE);

        argc = linea2argv(line, MAXARG, argv);

        externalsig = 0;
        ejecutar(argc, argv);
        my_free(argv);
    }
}