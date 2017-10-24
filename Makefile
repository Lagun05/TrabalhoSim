all: sim
sim: gerador.o fila.o main.o
	gcc -o sim gerador.o fila.o main.o -lm
	rm -rf *.o
gerador.o: src/gerador/gerador.c
	gcc -o gerador.o -c src/gerador/gerador.c
fila.o: src/fila/fila.c
	gcc -o fila.o -c src/fila/fila.c 
main.o: main.c src/fila/fila.h src/gerador/gerador.h
	gcc -o main.o -c main.c
clean:
	rm -rf sim
