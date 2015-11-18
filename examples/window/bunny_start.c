
#include <unistd.h>
#include "lapin.h"

int			main()
{
  t_bunny_window	*window;

  window = bunny_start(800, 600, false, "Ma fenêtre");
  sleep(2);
  bunny_stop(window);
  return (0);
}
