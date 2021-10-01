CC = clang
CFLAGS = -I. -Wall -fPIC -ansi

PLASMA = plasma/libplasma.so

LDLIBS = $(PLASMA)

BINS = $(PLASMA) tests/hello tests/zero tests/window

all: $(BINS)

debug: CFLAGS += -g
debug: $(BINS)

$(PLASMA): plasma/plasma.o plasma/graphics.o plasma/sdl.o
	$(CC) $^ -shared -o $@

clean:
	rm -f $(BINS) plasma/*.o