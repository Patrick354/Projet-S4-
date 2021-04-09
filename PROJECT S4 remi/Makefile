	#OCR Makefile
CC=gcc

CPPFLAGS= `pkg-config --cflags gtk+-3.0` `pkg-config --cflags sdl` -MMD
CFLAGS= -Wall -Wextra -std=c99 -O3 -g  
LDFLAGS= $(PTHREAD) $(GTKLIB) -rdynamic
LDLIBS= `pkg-config --libs gtk+-3.0` `pkg-config --libs sdl` -lSDL_image -lm


SRC= main.c rotations.c pixel_operations.c outilsdl.c  #skrewcorrection.h
OBJ=${SRC:.c=.o}
DEP=${SRC:.c=.d}

all: main

main:${OBJ}



clean:
	${RM} ${OBJ} #remove object files
	${RM} ${DEP} #remove depedency files
	${RM} main   #remove main program




-include ${DEP}
#END

# This makefile is use to test the preprocessing step of our program.
# 
