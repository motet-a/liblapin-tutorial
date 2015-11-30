#include <unistd.h>
#include <lapin.h>

void			fill_blue(t_bunny_pixelarray *pixelarray)
{
  int			i;
  int			total;
  unsigned		*pixels;

  pixels = (unsigned *)pixelarray->pixels;
  total = pixelarray->clipable.clip_width * pixelarray->clipable.clip_height;
  i = 0;
  while (i < total)
    {
      pixels[i] = BLUE;
      i++;
    }
}

void			blit_to_window(t_bunny_window *window,
				       const t_bunny_pixelarray *pixelarray)
{
  t_bunny_position	position;

  position.x = 0;
  position.y = 0;
  bunny_blit(&window->buffer, &pixelarray->clipable, &position);
}

int			main()
{
  t_bunny_window	*window;
  t_bunny_pixelarray	*pixelarray;

  window = bunny_start(800, 600, 0, "Ma fenêtre");
  if (!window)
    {
      return (1);
    }
  pixelarray = bunny_new_pixelarray(800, 600);
  fill_blue(pixelarray);
  blit_to_window(window, pixelarray);
  bunny_display(window);
  sleep(2);
  bunny_delete_clipable(&pixelarray->clipable);
  bunny_stop(window);
  return (0);
}
