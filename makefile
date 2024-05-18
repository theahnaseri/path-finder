all:
	gcc src/main.c src/grid.c -o main

clean:
	rm -f main