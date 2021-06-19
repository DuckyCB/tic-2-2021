#include <stdio.h>

int main() {
	int c;
	c = getchat();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}
