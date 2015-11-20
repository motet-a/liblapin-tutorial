
CC		= cc

RM		= rm -f

NAMES		= bunny_start bunny_start_style size multiple_windows

CFLAGS		= -Wall

LIBLAPIN_PATH	= -L/home/${USER}/.froot/lib/ -llapin \
		  -L/usr/local/lib

LDFLAGS		= $(LIBLAPIN_PATH) \
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

bunny_start_style: bunny_start_style.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

size: size.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

multiple_windows: multiple_windows.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

clean:

fclean: clean
	$(RM) $(NAMES)

re: fclean all
