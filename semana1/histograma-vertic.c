#include <stdio.h>

int main() {
    int c;
    int n = 0;
    int SIZE = 12;
    int arr[SIZE];
    int max = 0;
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c == ' ' || n >= 12 || c == '\n') {
            arr[n]++;
            if (n > max)
                max = n;
            n = 0;
        }
        n++;
    }
	for (int i = max; i > 0; i--) {
		for (int j = 0; j < SIZE; j++) {
			if (arr[j] >= i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
	for (int i = 0; i < SIZE; i++) {
		printf("%d", i+1);
	}
    return 0;
}