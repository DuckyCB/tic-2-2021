#include <stdio.h>

int main() {
	int c;
	int sp = '0';
	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			putchar(c);
			sp = '0';
		} else {
			if (sp == '0')
				putchar(' ');
			sp = '1';
		}
	}
	return 0;
}
