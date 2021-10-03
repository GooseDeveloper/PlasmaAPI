CC = clang
CFLAGS = -I. -Wall -fPIC -ansi $(shell pkg-config --cflags sdl2)

PLASMA = $(PWD)/plasma/libplasma.so
PLASMALIBS = $(shell pkg-config --libs sdl2)

LDLIBS = $(PLASMA)

BINS = $(PLASMA) tests/hello tests/zero tests/window tests/box

all: $(BINS)

debug: CFLAGS += -g
debug: $(BINS)

$(PLASMA): plasma/plasma.o plasma/graphics.o plasma/sdl.o plasma/entity.o plasma/box.o
	$(CC) $^ -shared -o $@ $(PLASMALIBS)

clean:
	rm -f $(BINS) plasma/*.o