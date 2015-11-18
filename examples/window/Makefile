
CC		= cc

RM		= rm -f

NAMES		= bunny_start size

CFLAGS		= -Wall

LDFLAGS		= -llapin \
		  -lsfml-audio \
		  -lsfml-graphics \
		  -lsfml-window \
		  -lsfml-system \
		  -lstdc++ -ldl \
		  -ljpeg \
		  -lm

all: $(NAMES)

bunny_start: bunny_start.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

size: size.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

clean:

fclean: clean
	$(RM) $(NAMES)
