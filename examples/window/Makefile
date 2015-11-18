
CC		= cc

RM		= rm -f

CFLAGS		= -Wall

LDFLAGS		= -llapin \
		  -lsfml-audio \
		  -lsfml-graphics \
		  -lsfml-window \
		  -lsfml-system \
		  -lstdc++ -ldl \
		  -ljpeg \
		  -lm

all: bunny_start

bunny_start: bunny_start.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

clean:

fclean: clean
	$(RM) bunny_start
