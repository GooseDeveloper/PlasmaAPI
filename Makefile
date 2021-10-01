CC = clang
CFLAGS = -I. -Wall -ansi

PLASMA = plasma/libplasma.so

LDLIBS = $(PLASMA)

BINS = $(PLASMA) tests/hello tests/zero

all: $(BINS)

$(PLASMA): plasma/plasma.o
	$(CC) -fPIC -shared $^ -o $@