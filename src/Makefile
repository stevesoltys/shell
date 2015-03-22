CC=gcc
CFLAGS=-Wall -g

all:
	make builtins.o command.o interpreter.o list.o main.o process.o shell.o tokenizer.o myshell

builtins.o: builtins.c builtins.h
	$(CC) $(CFLAGS) -c builtins.c

command.o: command.c command.h
	$(CC) $(CFLAGS) -c command.c

interpreter.o: interpreter.c interpreter.h
	$(CC) $(CFLAGS) -c interpreter.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

process.o: process.c process.h
	$(CC) $(CFLAGS) -c process.c

shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -c shell.c

tokenizer.o: tokenizer.c tokenizer.h
	$(CC) $(CFLAGS) -c tokenizer.c

myshell:
	$(CC) $(CFLAGS) builtins.o command.o interpreter.o list.o main.o process.o shell.o tokenizer.o -o myshell

clean:
	-rm -rf *.o myshell *.dSYM

rebuild:
	make clean all
