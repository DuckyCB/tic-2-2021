#include <stdio.h>

int my_strlen(char s[]);

int main() {
	char s[255] = "Hola";
	char t[255] = "aeiou";
	int n = my_strlen(s);
	printf("%d", n);
	return 0;
}

int my_strlen(char s[]) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    return n;
}

int my_strcmp(char s[], char t[]) {
	int lens = my_strlen(s);
	int lent = my_strlen(t);
	if (lens == lent) {
		for (int i = 0; i < lens; ++i) {
			if (s[i] != t[i])
				return 0;
		}
	}
	return 1;
}

void my_strcpy(char s[], char t[]) {
	int i = 0;
	while (s[i] != '\0') {
		s[i] = t[i];
		++i;
	}
}

void my_strncpy(char s[], char t[], int n) {
	int i = 0;
	while (i < n) {
		s[i] = t[i];
		++i;
	}
}

void reverse(char s[]) {
    int len = my_strlen(s);
    for (int i = len; i > 0; i--) {
		printf("%d", s[i]);
	}
}

void squeeze(char s[], char t[]) {
	int lens = my_strlen(s);
	int lent = my_strlen(t);
	int aux[lens];
	int last;
	int equals = 0;
	for (int i = 0; i < lens; i++) {
		for (int j = 0; j < lent; j++) {
			if (s[i] == t[lent]) {
				equals = 1;
			}
		}
		if (equals == 0)
			aux[++last] = s[i];
		equals = 0;
	}
}

void my_strcat(char dest[], char src[]) {
	int lendest = my_strlen(dest);
	int lensrc = my_strlen(src);
	for (int i = 0; i < lensrc; ++i) {
		dest[lendest+i] = src[i];
	}
}

int my_strend(char s[], char end[]) {
	int lens = my_strlen(s);
	int lenend = my_strlen(end);
	if (lens >= lenend) {
		for (int i = 1; i <= lenend; ++i) {
			if (s[lens-i] != end[lenend-i])
				return 0;
		}
		return 1;
	}
	return 0;
}

int my_strcasecmp(char s[], char t[]) {
	int lens = my_strlen(s);
	int lent = my_strlen(t);
	if (lens == lent) {
		for (int i = 0; i < lens; ++i) {
			if (s[i] > 96) s[i] = s[i] - 32;
			if (t[i] > 96) t[i] = t[i] - 32;
			if (s[i] != t[i]) return 0;
		}
	}
	return 1;
}
