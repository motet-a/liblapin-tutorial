#include <unistd.h>
#include <stdio.h>
#include "lapin.h"

static void		print_size(t_bunny_window *window)
{
  t_bunny_buffer	*buffer;

  buffer = &window->buffer;
  printf("Window size: %dx%d\n", buffer->width, buffer->height);
}

int			main()
{
  t_bunny_window	*window;

  window = bunny_start(800, 600, 0, "Ma fenêtre");
  if (!window)
    {
      return (1);
    }
  while (1)
    {
      bunny_display(window);
      print_size(window);
      sleep(1);
    }
  bunny_stop(window);
  return (0);
}
