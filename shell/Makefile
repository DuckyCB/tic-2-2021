# La variable CFLAGS indica las banderas para el compilador C
#CFLAGS=-Wall -Wextra -std=gnu99 –ggdb
# Este sería el ejecutable, sus dependencias son los .o
minish:	minish.o	minish-func.o	minish-builtin-func.o	dir.o	history.o
# make sabe que cada .o depende del .c correspondiente
# Solo se agrega la dependencia al .h
minish-func.o:	minish.h minish-func.h
minish.o:	minish.h
minish-builtin-func.o:	minish.h
history.o: minish.h	history.h
dir.o: minish.h