#CPP = clang++
#C = clang
CPP = g++
C = gcc

### Linux

LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
CFLAGS = -Wall -c -g
BIN1 = hello

all: clean $(BIN1)

$(BIN1): hello.o kiss_sdl/kiss_widgets.o  kiss_sdl/kiss_draw.o  kiss_sdl/kiss_general.o  kiss_sdl/kiss_posix.o
	$(C) $^ $(LDFLAGS) -o $@ && rm *.o

hello.o: hello.c
	$(C) $(CFLAGS) $^ -o $@

 kiss_sdl/kiss_widgets.o:  kiss_sdl/kiss_widgets.c
	$(C) $(CFLAGS) $^ -o $@

 kiss_sdl/kiss_draw.o:  kiss_sdl/kiss_draw.c
	$(C) $(CFLAGS) $^ -o $@

 kiss_sdl/kiss_general.o:  kiss_sdl/kiss_general.c
	$(C) $(CFLAGS) $^ -o $@

 kiss_sdl/kiss_posix.o:  kiss_sdl/kiss_posix.c
	$(C) $(CFLAGS) $^ -o $@

clean:
	rm $(BIN1) && rm kiss_sdl/*.o
