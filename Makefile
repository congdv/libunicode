CC=cc
FLAGS=-Wall -Wextra -pedantic 
STD=-std=c99
DBUG= -g

ghi: unicode.c
	$(CC) $(FLAGS) unicode.c -o unicode $(STD)
debug: unicode.c
	$(CC) $(FLAGS) unicode.c -o unicode $(STD) $(DBUG)
clean:
	rm -rf unicode
