#include <stdio.h>

int main() {
	int n = 0;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++n;
	}
	printf("%d", n);
	return 0;
}
