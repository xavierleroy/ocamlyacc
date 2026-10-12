CC=cc
CFLAGS=-O -Wall
LIBS=
OBJ=.o
EXE=

SOURCES=closure.c error.c lalr.c lr0.c main.c mkpar.c output.c reader.c skeleton.c symtab.c verbose.c warshall.c wstr.c

OBJECTS=$(SOURCES:.c=$(OBJ))

EXECUTABLE=ocamlyacc$(EXE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

$(OBJECTS): defs.h version.h

clean:
	rm -f $(EXECUTABLE)
	rm -f $(OBJECTS)
