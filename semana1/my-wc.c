#include <stdio.h>

int main() {
	int c;
	int nl = 0;
	int np = 0;
	int nc = 0;
	int sp = 1;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c != ' ' && sp == 1) {
			sp = 0;
			++np;	
		} else {
			sp = 1;
		}
	}
	printf("Numero de lineas %d\n", nl);
	printf("Numero de palabras %d \n", np);
	printf("Numero de caracteres %d \n", nc);
	return 0;
}
