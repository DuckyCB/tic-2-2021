# La variable CFLAGS indica las banderas para el compilador C
#CFLAGS=-Wall -Wextra -std=gnu99 –ggdb
# Este sería el ejecutable, sus dependencias son los .o
table-lookup:    table-lookup.o    table-lookup-func.o    getword.o
# make sabe que cada .o depende del .c correspondiente
# Solo se agrega la dependencia al .h
table-lookup-func.o:    table-lookup.h
table-lookup.o:    table-lookup.h