
# Fenêtre #

La liblapin ne gère qu’une seule fenêtre.

## Ouvrir la fenêtre ##

```c
t_bunny_window	*bunny_start(unsigned int	width,
							 unsigned int	height,
							 bool			fullscreen,
							 const char		*name);
```

La fonction `bunny_start()` ouvre la fenêtre dont le nom est spécifié par
`name`. `width` et `height` indiquent la taille de la fenêtre, `fullscreen`
doit être égal à `0` pour que la fenêtre soit en plein écran.

Noter qu’il n’y a aucun moyen de redimensionner ou de renommer
une fenêtre une fois qu’elle à été créée.
Seul l’utilisateur peut changer sa taille manuellement.
Il est toutefois possible de détecter les redimensionnements de
l’utilisateur grâce aux évenements.

## Fermer la fenêtre ##

```c
void	bunny_stop(t_bunny_window	*window);
```

La fonction `bunny_stop()` ferme la fenêtre. Elle doit toujours être appellée
avant la fin du programme pour libérer les ressources allouées par
`bunny_start()`.

## Exemple ##

```c
#include <unistd.h>
#include "lapin.h"

int					main()
{
  t_bunny_window	*window;

  window = bunny_start(800, 600, false, "Ma fenêtre");
  sleep(2);
  bunny_stop(window);
  return (0);
}
```

*[Voir le fichier](https://github.com/motet-a/liblapin-tutorial/blob/master/examples/window/bunny_start.c)*

Cet exemple ouvre une fenêtre nommée « Ma fenêtre » pendant 2 secondes.

## Ouvrir une fenêtre avec plus de paramètres ##

```c
t_bunny_window	*bunny_start_style(unsigned int			width,
								   unsigned int			height,
								   t_bunny_window_style	winstyle,
								   const char			*name);
```

**Avertissement** : Cette fonction n’est pas décrite dans la
documentation officielle.

*TODO: Rajouter un exemple*

## Buffer ##

Étant donné que la fenêtre peut être redimensionnée par l’utilisateur,
sa taille à un moment donné lors de l’exécution du programme peut être
différente de la taille passée en paramètre à `bunny_start()`.

La structure `t_bunny_window` représentant la fenêtre contient
un membre `buffer`, de type `t_bunny_buffer`.

### Dimensions ###

Le buffer d’une fenêtre contient :
  - un membre `width` représentant la largeur interne de la fenêtre ;
  - un membre `height` représentant la hauteur.

Ces membres sont accessibles en lecture seule, les modifier ne
permettera pas de redimensionner la fenêtre.

*TODO: Rajouter un exemple*
