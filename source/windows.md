
# Fenêtres #

## Ouvrir une fenêtre ##

[manuel officiel][o bunny_start]

```c
t_bunny_window	*bunny_start(unsigned int	width,
							 unsigned int	height,
							 bool			fullscreen,
							 const char		*name);
```

La fonction `bunny_start()` ouvre une fenêtre dont le nom est spécifié par
`name`. `width` et `height` indiquent la taille de la fenêtre, `fullscreen`
doit être égal à `0` pour que la fenêtre ne soit pas en plein écran.

Cette fonction retourne soit la nouvelle fenêtre, soit `NULL` en cas d’erreur.

Noter qu’il n’y a aucun moyen de redimensionner ou de renommer
une fenêtre une fois qu’elle à été créée.
Seul l’utilisateur peut changer sa taille manuellement.

## Fermer une fenêtre ##

[manuel officiel][o bunny_stop]

```c
void	bunny_stop(t_bunny_window	*window);
```

La fonction `bunny_stop()` ferme une fenêtre.
Après un appel à `bunny_start()`, `bunny_stop()` doit toujours
être appellée avant la fin du programme pour libérer les ressources
allouées par `bunny_start()`.

## Afficher le contenu d’une fenêtre ##

[manuel officiel][o bunny_display]

```c
void	bunny_display(const t_bunny_window	*window);
```

Cette fonction affiche le contenu d’une fenêtre à l’écran.
Il est nécéssaire de l’appeller après `bunny_start()` pour être sûr
que la fenêtre soit visible.

## Exemples ##

```c
#include <unistd.h>
#include <lapin.h>

int					main()
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
```

[Voir le fichier][bunny_start.c]

Ce programme ouvre une fenêtre nommée « Ma fenêtre » pendant 2 secondes.

Il est possible d’ouvrir plusieurs fenêtres, comme l’illustre
[cet exemple][multiple_windows.c].

## Ouvrir une fenêtre avec plus de paramètres ##

```c
t_bunny_window	*bunny_start_style(unsigned int			width,
								   unsigned int			height,
								   t_bunny_window_style	winstyle,
								   const char			*name);
```

[Voir le fichier][bunny_start_style.c]

**Avertissement** : Cette fonction n’est pas décrite dans la
documentation officielle.

Cette fonction retourne soit la nouvelle fenêtre, soit `NULL` en cas d’erreur.

Pour les utilisateurs du gestionnaire de fenêtres i3, vous aurez remarqué
que les fenêtres ne sont pas affichées en mode flottant directement.
Pour cela, il faut que la valeur de `winstyle` soit `TITLEBAR | CLOSE_BUTTON`.

## Buffer ##

La structure `t_bunny_window` représentant une fenêtre contient
un membre `buffer`, de type `t_bunny_buffer`.

### Dimensions ###

Le buffer d’une fenêtre contient :
  - un membre `width` représentant la largeur interne de la fenêtre ;
  - un membre `height` représentant la hauteur.

Ces membres sont accessibles en lecture seule, les modifier ne
permettera pas de redimensionner la fenêtre.

Curieusement, ces membres contiennent toujours la taille de la
fenêtre lors de sa création, et ne sont pas mis à jours lors de
son redimensionnement :

```c
static void			print_size(t_bunny_window *window)
{
  t_bunny_buffer	*buffer;

  buffer = &window->buffer;
  printf("Window size: %dx%d\n", buffer->width, buffer->height);
}
```

[Voir le fichier][size.c]

[o bunny_start]: https://cdn.local.epitech.eu/elearning/B-MUL-051/doc_lapin.htm#bunny_start
[o bunny_stop]: https://cdn.local.epitech.eu/elearning/B-MUL-051/doc_lapin.htm#bunny_stop
[o bunny_display]: https://cdn.local.epitech.eu/elearning/B-MUL-051/doc_lapin.htm#bunny_display

[bunny_start.c]: https://github.com/motet-a/liblapin-tutorial/blob/master/examples/window/bunny_start.c
[bunny_start_style.c]: https://github.com/motet-a/liblapin-tutorial/blob/master/examples/window/bunny_start_style.c
[size.c]: https://github.com/motet-a/liblapin-tutorial/blob/master/examples/window/size.c
[multiple_windows.c]: https://github.com/motet-a/liblapin-tutorial/blob/master/examples/window/multiple_windows.c
