OBJ = main.o getch.o getop.o stack.o
CC = gcc
ARGS = -Wall
LIBS = -lm # standard libraries for linking final program
DEBUG = -g # Add -g after DEBUG to compile with debugging symbols for gdb

rpn: $(OBJ)
	$(CC) $(ARGS) $(DEBUG) $(OBJ) -o rpn $(LIBS)

main.o: main.c calc.h
	$(CC) $(ARGS) $(DEBUG) -c main.c

getch.o: getch.c calc.h
	$(CC) $(ARGS) $(DEBUG) -c getch.c

getop.o: getop.c calc.h
	$(CC) $(ARGS) $(DEBUG) -c getop.c

stack.o: stack.c calc.h
	$(CC) $(ARGS) $(DEBUG) -c stack.c
	
.PHONY: clean
clean:
	rm -rf rpn $(OBJ)
