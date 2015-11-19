
CC		= cc

RM		= rm -f

NAMES		= bunny_start size multiple_windows

CFLAGS		= -Wall

LDFLAGS		= -L$(LD_LIBRARY_PATH) \
		  -lsfml-audio \
		  -lsfml-graphics \
		  -lsfml-window \
		  -lsfml-system \
		  -lstdc++ -ldl \
		  -ljpeg \
		  -lm \
		  -llapin

all: $(NAMES)

bunny_start: bunny_start.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

size: size.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

multiple_windows: multiple_windows.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

clean:

fclean: clean
	$(RM) $(NAMES)
