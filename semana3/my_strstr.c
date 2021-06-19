#include <stdio.h>

int main() {
	// Codigo
    return 0;
}

int my_strstr(char pajar[], char aguja[]) {
    int i = 0;
    int lenaguja = my_strlen(aguja);
    int n = 0;
    int index;
    while (pajar[i++] != '\0') {
        if (pajar[i] == aguja[0]) {
            index = i;
            n = 0;
            while (n++ < lenaguja) {
                if (pajar[i+n] == aguja[n]) {
                    if (n == lenaguja)
                        return index;
                } else
                    n = lenaguja;
            }
        } else
            n = 0;
    }
    return -1;
}

int my_strlen(char s[]) {
    int n = 0;
    while (s[n++] != '\0') ;
    return n;
}