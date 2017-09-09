CC=cc
FLAGS=-Wall -Wextra -pedantic 
STD=-std=c99
DBUG= -g

test: test.c
	$(CC) $(FLAGS) test.c unicode.c -o unicode $(STD) 
debug: test.c
	$(CC) $(FLAGS) test.c unicode.c -o unicode $(STD) $(DBUG)
clean:
	rm -rf unicode
