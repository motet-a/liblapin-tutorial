#include <unistd.h>
#include <stdio.h>
#include <lapin.h>

static void	print_first_name(t_bunny_ini *ini)
{
  const char	*first_name;

  first_name = bunny_ini_get_field(ini, "player", "first_name", 0);
  if (!first_name)
    {
      printf("Le champ \"first_name\" dans la section"
	     " \"player\" est introuvable\n");
      return ;
    }
  printf("First name: %s\n", first_name);
}

int			main()
{
  t_bunny_ini		*ini;

  ini = bunny_load_ini("test.ini");
  if (!ini)
    {
      printf("Fichier introuvable\n");
      return (1);
    }
  print_first_name(ini);
  bunny_delete_ini(ini);
  return (0);
}
