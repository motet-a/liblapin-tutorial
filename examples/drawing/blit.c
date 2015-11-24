#include <unistd.h>
#include <lapin.h>

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
  blit_to_window(window, pixelarray);
  bunny_display(window);
  sleep(2);
  bunny_delete_clipable(&pixelarray->clipable);
  bunny_stop(window);
  return (0);
}
