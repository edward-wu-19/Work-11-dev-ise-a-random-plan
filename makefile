all: main.o
	gcc -o grunt main.o

main.o: main.c
	gcc -c main.c

clean:
	rm -rf grunt main.o something

run:
	./grunt