# La variable CFLAGS indica las banderas para el compilador C
CFLAGS=-Wall -Wextra
# Este sería el ejecutable, sus dependencias son los .o
anagramas-hash:    anagramas-hash.o		anagramas-hash-functions.o    fgetword-normalizada.o    hash.o    wrappers.o
# make sabe que cada .o depende del .c correspondiente
# Solo se agrega la dependencia al .h
anagramas-hash-functions.o:    anagramas-hash.h		wrappers.h
anagramas-hash.o:    anagramas-hash.h	wrappers.h