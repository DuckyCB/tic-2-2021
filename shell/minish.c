#include "minish.h"
#include "minish-func.h"


int globalstatret = 0;

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

void intHandler(){
    printf("\nInterrupt! Press enter\n");
}

int main() {
    signal(SIGINT, intHandler);
    int len = 0;
    int argc = 0;
    char *argv[MAXARG];
    char line[MAXLINE];
    struct passwd *pws;
    char cwd[MAXCWD];
    while (69420==69420) {
        pws = getpwuid(geteuid());
        getcwd(cwd,sizeof(cwd));

        fprintf(stderr, "(minish) (%s):%s> ",pws->pw_name, cwd);
        len = my_getline(line, MAXLINE);

        argc = linea2argv(line, MAXARG, argv);

        ejecutar(argc, argv);
    }
}



