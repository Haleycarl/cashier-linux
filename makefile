# TO COMPILE THIS PROGRAM YOU NEED GCC AND MAKE
OUTFILE=main # Output file
INFILE=main.cpp # Input Files
LIBS=-lncurses -lsqlite3
CC=g++ # Compiler
linux:
	$(CC) $(LIBS) $(INFILE) -o $(OUTFILE)
run:
	./$(OUTFILE) 2> info.log

clean:
	rm main sqlite3
