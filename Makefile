### PL. Fichero makefile basico
# FUENTE: nombre fichero fuente con extension .l
FUENTE = try
# PRUEBA: nombre fichero de prueba
PRUEBA = a.c
# LIB (libreria flex): lfl (gnu/linux, windows); ll (macos)
LIB = lfl

all: compile run

compile:
	flex $(FUENTE).l
	bison -r all -o $(FUENTE).tab.c $(FUENTE).y -yd
	gcc -o $(FUENTE) lex.yy.c $(FUENTE).tab.c -$(LIB) 

clean:
	rm $(FUENTE) lex.yy.c $(FUENTE).tab.c $(FUENTE).tab.h

run:
	./$(FUENTE) < $(PRUEBA)

run2:
	./$(FUENTE)

