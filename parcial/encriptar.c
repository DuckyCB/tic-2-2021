#include <stdio.h>
#include <string.h>

// /var/local/labii2021/PIC1/test_encriptar.py ./encriptar.so > ./resultado-final

char *encriptar(char *s, char *diccionario, int clave) {

	int dicc_len = strlen(diccionario);
	int desplazamiento = clave % dicc_len;
	int dicc_pos;
	int change;

	for (int i = 0; i < strlen(s); i++) {
		dicc_pos = 0;
		change = 1;
		while (*(s + i) != *(diccionario + dicc_pos)) {
			dicc_pos++;
			if (dicc_pos == dicc_len) {
				change = 0;
				break;
			}
		}
		if (change == 1) {
			*(s + i) = *(diccionario + (dicc_pos + desplazamiento) % dicc_len);
		}
		
	}
	return s;

}

char *desencriptar(char *s, char *diccionario, int clave) {

	int dicc_len = strlen(diccionario);
	int desplazamiento = clave % dicc_len;
	int dicc_pos;
	int change;

	for (int i = 0; i < strlen(s); i++) {
		dicc_pos = 0;
		change = 1;
		while (*(s + i) != *(diccionario + dicc_pos)) {
			dicc_pos++;
			if (dicc_pos == dicc_len) {
				change = 0;
				break;
			}
		}
		if (change == 1) {
			*(s + i) = *(diccionario + (dicc_pos - desplazamiento + dicc_len) % dicc_len);
		}
		
	}
	return s;

}