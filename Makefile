
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -std=c11
LDFLAGS=
EXEC=my_sh
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

my_sh: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
