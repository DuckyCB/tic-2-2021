

CC=gcc
CFLAGS=-Wall -Wextra -std=gnu99 -ggdb


minish: minish.o minish-func.o minish-builtin-func.o dir.o exit.o history.o util.o
	$(CC) $(CFLAGS) -o $@ $^	
	
minish.o: minish.h 

minish-func.o: minish.h minish-func.h

minish-builtin-func.o: minish.h

dir.o: minish.h 

exit.o: minish.h util.h

history.o: minish.h util.h 

util.o: util.h
