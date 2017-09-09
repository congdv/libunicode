CC=cc
FLAGS=-Wall -Wextra -pedantic 
STD=-std=c99
DBUG= -g

test: test.c
	$(CC) $(FLAGS) test.c unicode.c -o test $(STD) 
debug: test.c
	$(CC) $(FLAGS) test.c unicode.c -o test $(STD) $(DBUG)
clean:
	rm -rf test
