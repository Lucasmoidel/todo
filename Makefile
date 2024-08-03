#CPP = clang++
#C = clang
CPP = g++
C = gcc

### Linux

LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
CFLAGS = -Wall -c
BIN1 = hello


all: $(BIN1)

$(BIN1): hello.o /usr/include/kiss_sdl/kiss_widgets.o /usr/include/kiss_sdl/kiss_draw.o /usr/include/kiss_sdl/kiss_general.o /usr/include/kiss_sdl/kiss_posix.o
	$(C) $^ $(LDFLAGS) -o $@ && rm *.o

hello.o: hello.c
	$(C) $(CFLAGS) $^ -o $@

clean:
	rm $(BIN1)
#	del *.o
#	del $(BIN1)
#	del $(BIN2)

