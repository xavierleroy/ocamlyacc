include $(shell ocamlc -where)/Makefile.config

CFLAGS=$(BYTECODE_CFLAGS) -DWINDOWS_UNICODE=$(WINDOWS_UNICODE)

SOURCES=closure.c error.c lalr.c lr0.c main.c mkpar.c output.c reader.c skeleton.c symtab.c verbose.c warshall.c wstr.c

OBJECTS=$(SOURCES:.c=$(EXT_OBJ))

EXECUTABLE=ocamlyacc$(EXE)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OUTPUTEXE)$@ $(OBJECTS)

$(OBJECTS): defs.h version.h

test:
	$(MAKE) -C tests all

clean:
	rm -f $(EXECUTABLE)
	rm -f $(OBJECTS)
	$(MAKE) -C tests clean

