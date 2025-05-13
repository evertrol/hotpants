#############################################################
# TO BE CHANGED BY EACH USER TO POINT TO include/ AND lib/
# DIRS HOLDING CFITSIO *.h AND libcfitsio IF THEY ARE NOT IN
# THE STANDARD PLACES
#

CFITSIODIR =

INCDIR = $(CFITSIODIR)/include
LIBDIR = $(CFITSIODIR)/lib


# Compiler
CC =



#
#############################################################
# COMPILATION OPTIONS BELOW
#

# another good memory checker is valgrind : http://valgrind.kde.org/index.html
# valgrind --tool=memcheck hotpants

# for memory checking with libefence
# LIBS  = -L$(LIBDIR) -lm -lcfitsio -lefence

# for profiling with gprof
# CFLAGS = -pg -fprofile-arcs -funroll-loops -O3 -ansi -pedantic-errors -Wall -I$(INCDIR)

# for gdbugging
#CFLAGS = -g3 -funroll-loops -O3 -ansi -pedantic-errors -Wall -I$(INCDIR)

# standard usage
# recently added -std=c99 after a bug report
CFLAGS = -funroll-loops -O3 -std=c99 -pedantic-errors -Wall -I$(INCDIR)
LIBS = -L$(LIBDIR) -lm -lcfitsio

#
#
#############################################################
# BELOW SHOULD BE OK, UNLESS YOU WANT TO COPY THE EXECUTABLES
# SOMEPLACE AFTER THEY ARE BUILT eg. hotpants
#

STDH = functions.h globals.h defaults.h
ALL = main.o vargs.o alard.o functions.o

.PHONY: all clean

all: hotpants extractkern maskim

hotpants: $(ALL)
	$(CC) $(ALL) -o hotpants $(LIBS) $(CFLAGS)
#	cp hotpants ../../bin/$(ARCH)

main.o: $(STDH) main.c
	$(CC) $(CFLAGS)  -c main.c

alard.o: $(STDH) alard.c
	$(CC) $(CFLAGS)  -c alard.c

functions.o: $(STDH) functions.c
	$(CC) $(CFLAGS)  -c functions.c

vargs.o: $(STDH) vargs.c
	$(CC) $(CFLAGS)  -c vargs.c

extractkern : extractkern.o
	$(CC) extractkern.o -o extractkern $(LIBS) $(CFLAGS)

extractkern.o : $(STDH) extractkern.c
	$(CC) $(CFLAGS)  -c extractkern.c

maskim : maskim.o
	$(CC) maskim.o -o maskim $(LIBS) $(CFLAGS)

maskim.o: $(STDH) maskim.c
	$(CC) $(CFLAGS)  -c maskim.c

clean :
	rm -f *.o
	rm -f *~ .*~
	rm -f hotpants
	rm -f extractkern
	rm -f maskim
