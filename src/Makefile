# Trivial makefile for MacOS X
CC = cc
CFLAGS = -g -O2 
LATEX2RTF = latex2rtf

SRC = cfg.c\
      direct.c\
      funct1.c\
      funct2.c\
      ignore.c\
      main.c\
      optind.c\
      stack.c\
      commands.c\
      encode.c\
      l2r_fonts.c\
      mygetopt.c\
      parser.c\
      util.c

OBJ = cfg.o\
      direct.o\
      funct1.o\
      funct2.o\
      ignore.o\
      main.o\
      stack.o\
      commands.o\
      encode.o\
      l2r_fonts.o\
      parser.o\
      util.o
      
latex2rtf : $(OBJ)
	$(CC) $(CFLAGS) -o ../app/$(LATEX2RTF) $(OBJ)

clean : 
	rm *.o

test :
	cd ../app
	./$(LATEX2RTF) ../test/oddchars.tex

