CPP = g++
CFLAGS = -Wall -g
LIBS = -lusb-1.0 -L../libusbasp -lusbasp
INCLUDES = -I../libusbasp/include -I.

SRCS = dump.cpp SPI.cpp MFRC522.cpp
OBJS = $(SRCS:.cpp=.o)

all: libusbasp.a usbasp_dump

usbasp_dump: libusbasp.a $(OBJS)
	$(CPP) $(LFLAGS) $(OBJS) -o usbasp_dump $(LIBS)

libusbasp.a:
	+make -C ../libusbasp

.cpp.o:
	$(CPP) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	rm -f *.o *.d *_read *_dump
	make clean -C ../libusbasp
