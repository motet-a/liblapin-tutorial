#include <unistd.h>
#include <lapin.h>

int			main()
{
  t_bunny_window	*window;

  window = bunny_start_style(800, 600, TITLEBAR | CLOSE_BUTTON, "Ma fenêtre");
  if (!window)
    {
      return (1);
    }
  bunny_display(window);
  sleep(2);
  bunny_stop(window);
  return (0);
}
