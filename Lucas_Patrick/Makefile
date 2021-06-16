CC=gcc -fsanitize=address
CPPFLAGS= -MMD
CFLAGS= -Wall -Wextra -std=c99 -O0 -g
LDFLAGS=
LDLIBS= 

OBJ = tools.o calcul.o split.o build_tree.o main.o
DEP = ${OBJ:.o=.d}

all: main

main: ${OBJ}

clean: ${RM} ${OBJ} ${DEP} main

-include ${DEP}



