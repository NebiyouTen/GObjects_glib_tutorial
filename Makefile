CC=gcc
CFLAGS=-std=c11 `pkg-config --cflags glib-2.0 gio-2.0 gobject-2.0`
LDFLAGS=`pkg-config --libs glib-2.0 gio-2.0 gobject-2.0`

EXEC=main

SRC=main.c\
    animal.c\
    dog.c\
    cat.c

OBJ=main.o\
    animal.o\
    dog.o\
    cat.o


$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean run

clean:
	rm -f $(OBJ) $(EXEC)
