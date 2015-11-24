
CC		= cc

RM		= rm -f

NAMES		= blit

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

blit: blit.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

clean:

fclean: clean
	$(RM) $(NAMES)

re: fclean all
