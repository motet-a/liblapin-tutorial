#include <unistd.h>
#include "lapin.h"

int			main()
{
  t_bunny_window	*window_a;
  t_bunny_window	*window_b;

  window_a = bunny_start(800, 600, 0, "Ma première fenêtre");
  if (!window_a)
    {
      return (1);
    }
  sleep(2);
  window_b = bunny_start(600, 400, 0, "Ma seconde fenêtre");
  if (!window_b)
    {
      return (1);
    }
  sleep(2);
  bunny_stop(window_a);
  bunny_stop(window_b);
  return (0);
}
