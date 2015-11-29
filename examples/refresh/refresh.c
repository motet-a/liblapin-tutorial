#include <lapin.h>
#include <stdio.h>
#include <stdlib.h>

t_bunny_response        refresh_my_game(void *my_data)
{
  printf("There's no game yet\n");
  return (GO_ON);
}

int			main()
{
  t_bunny_window	*window;

  window = bunny_start(800, 600, 0, "My game");
  bunny_set_loop_main_function(&refresh_my_game);
  printf("Loop start\n");
  bunny_loop(window, 2, NULL);
  printf("Loop end\n");
  return (0);
}
