C_FLAGS=-std=c99 -Wall -Werror -Iinclude 

all: bin/graph.o bin/main.o
	
	gcc bin/graph.o bin/main.o -o bin/main ${C_FLAGS}

bin/graph.o:
	mkdir -p bin/
	gcc -g -c src/graph.c -o bin/graph.o -Iinclude 

bin/main.o:
	gcc -g -c src/main.c -o bin/main.o -Iinclude

clean:
	rm bin/*

run:
	./bin/main

debug:
	valgrind --leak-check=yes --log-file=valgrind.rpt ./bin/main
