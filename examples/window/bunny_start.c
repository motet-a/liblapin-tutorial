#include <unistd.h>
#include "lapin.h"

int			main()
{
  t_bunny_window	*window;

  window = bunny_start(800, 600, 0, "Ma fenêtre");
  if (!window)
    {
      return (1);
    }
  bunny_display(window);
  sleep(2);
  bunny_stop(window);
  return (0);
}
