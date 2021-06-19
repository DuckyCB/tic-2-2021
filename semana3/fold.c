#include <stdio.h>

int main() {
	// Codigo
    return 0;
}

void fold(char s[], int n) {
    int i = 0;
    int column = 0;
    while (s[i++] != '\0') {
        if (column++ >= n) {
            if (s[i] == ' ') {
                s[i] = '\n';
                column = 0;
            }
        }
    }
}





void foldd(char s[], int n) {
    int i = 0;
    int column = 0;
    int last_space_index = 0;
    int word_len = 0;
    while (s[i++] != '\0') {
		if (word_len >= n)
			s = new_arr(s, i);
        if (s[i] == ' ' && column < n) {
            last_space_index = i;
            word_len = 0;
        }
		if (s[i] == '\n') {
			last_space_index = 0;
			word_len = 0;
		}
		if (s[i] != ' ')
			word_len++;
        if (column++ >= n) {
            if (s[i] == ' ') {
                s[i] = '\n';
            } else {
				s[last_space_index] = '\n';
				column = word_len - 1;
			}
        }
    }
}

char * new_arr(char s[], int index) {
	int i = 0;
	int sum = 0;
	int len = my_strlen(s);
	char sn[len+1];
	while (i++ != '\0') {
		if (i == index) {
			sn[i] = '\n';
			sum++;
		}
		sn[i+sum] = s[i];
	}
	return sn;
}

int my_strlen(char s[]) {
    int n = 0;
    while (s[n++] != '\0') ;
    return n;
}

void copy(char to[], char from[], int index){
    int i = 0;
	int sum = 0;
    while ((to[i+sum] = from[i]) != '\0') {
		if (i++ == index) {
			sum++;
			to[i] = '\n';
		}
    }
}
