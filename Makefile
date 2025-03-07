# define the C compiler to use
CC       = gcc
# define compiler flags
CFLAGS   = -std=c11 -Wall -fmax-errors=10 -Wextra
# define library paths in addition to /usr/lib
LFLAGS   = 
# define libraries to use
LIBS     = 
# define the object files that this project needs
OBJFILES = 7p3activity1plants.o
# define the name of the executable file
MAIN     = 7p3activity1plants
# define the C source files
#SRCFILES = 7p3activity1plants.c
# define the header files
#HDRFILES =
# define the files to remove when cleaning up
#CLEANFILES = $(OBJFILES) $(MAIN)
# define the files to run when launching
#LAUNCHFILES = $(MAIN)

# all of the below is generic - one typically only adjusts the above

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES) $(LFLAGS) $(LIBS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJFILES) $(MAIN)

launch: $(MAIN)
	./$(MAIN)