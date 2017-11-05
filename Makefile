##Compilador
CC = gcc

##Objetos
OBJS = gerador.o fila.o thread.o main.o

##Flags
DEBUG = -g
CFLAGS = -Wall -pedantic -c $(DEBUG)

##Bibliotecas
LIBS = -lm -lpthread

##Principal
all: sim
sim: $(OBJS)
	@$(CC) -o $@ $(OBJS) $(LIBS)
	@rm -rf *.o

##Objetos
gerador.o: src/gerador/gerador.c
	@$(CC) $(CFLAGS) -o $@ $<

fila.o: src/fila/fila.c
	@$(CC) $(CFLAGS) -o $@ $<

thread.o: src/thread/thread.c
	@$(CC) $(CFLAGS) -o $@ $<

main.o: main.c src/fila/fila.h src/gerador/gerador.h src/thread/thread.h
	@$(CC) $(CFLAGS) -o $@ $<

##Apagar
clean:
	@rm -rf sim
