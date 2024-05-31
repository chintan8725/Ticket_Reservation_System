# you can put include files in this directory
IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

# directory where object files will be created
ODIR=obj
# you can put library files in this directory
LDIR =../lib
# looks for library libm.so or libm.a
LIBS=-lm

# create string with ../include/<header filename> in our case ../include/myheader.h
_DEPS = myheader.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# create string with obj/<object filename> in our case obj/add.o and obj/sub.o  (obj folder will be created under current i.e. source directory)
_LIBOBJ = bus_reservation.o flight_reservation.o
LIBOBJ = $(patsubst %,$(ODIR)/%,$(_LIBOBJ))
LIBSRC = bus_reservation.c flight_reservation.c
_APPOBJ = ticket_reservation.o
APPOBJ = $(patsubst %,$(ODIR)/%,$(_APPOBJ))

$(ODIR)/bus_reservation.o: bus_reservation.c
	$(CC) -c -fPIC -o $@ $< $(CFLAGS)

$(ODIR)/flight_reservation.o: flight_reservation.c
	$(CC) -c -fPIC -o $@ $< $(CFLAGS)

$(LDIR)/libmybooking.so:$(LIBOBJ)
	$(CC) -shared -o $@ $^

$(APPOBJ): ticket_reservation.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
ticket_reservation.out: $(APPOBJ) $(LDIR)/libmybooking.so
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LDIR)/libmybooking.so
	
.PHONY: clean

# removes object files and temporary files created with ~ at the end of file name in current i.e. source and include directory
clean: 
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm -f ticket_reservation.out $(LDIR)/libmybooking.so
	
.PHONY: all
all: $(LDIR)/libmybooking.so ticket_reservation.out
