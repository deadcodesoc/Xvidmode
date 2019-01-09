CFLAGS=-Wall -ansi -pedantic -g
LIBS=-lX11 -lXext -lXxf86vm
LIBSDIR=-L/usr/X11R6/lib

all: Xvidmode

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

Xvidmode.o: Xvidmode.c Xvidmode.h
	$(CC) $(CFLAGS) -c Xvidmode.c


Xvidmode: Xvidmode.o main.o
	$(CC) $(LIBS) $(LIBSDIR) Xvidmode.o main.o -o Xvidmode

install: Xvidmode
	install -s $(PROG) /usr/X11R6/bin/$(PROG)
	install tk$(PROG) /usr/X11R6/bin/tk$(PROG)

clean:
	rm -f *.o core Xvidmode
