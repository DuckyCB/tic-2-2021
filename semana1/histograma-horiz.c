#include <stdio.h>

int main() {
    int c;
    int n = 0;
    int SIZE = 12;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c == ' ' || n >= 12 || c == '\n') {
            arr[n]++;
            n = 0;
        }
        n++;
    }
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < arr[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}