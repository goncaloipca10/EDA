CC=gcc
CFLAGS=-Wall

all: menu

menu: menu.o clientes.o gestores.o meio.o
	$(CC) $(CFLAGS) -o menu menu.o clientes.o gestores.o meio.o

menu.o: menu.c header.h
	$(CC) $(CFLAGS) -c menu.c

clientes.o: clientes.c header.h
	$(CC) $(CFLAGS) -c clientes.c

gestores.o: gestores.c header.h
	$(CC) $(CFLAGS) -c gestores.c

meio.o: meio.c header.h
	$(CC) $(CFLAGS) -c meio.c

clean:
	rm -f *.o menu
