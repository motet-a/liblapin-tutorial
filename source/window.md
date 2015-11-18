
# Fenêtre #

La liblapin ne gère qu’une seule fenêtre.

## Ouvrir la fenêtre ##

### Méthode simple ###

```
t_bunny_window	*bunny_start(unsigned int	width,
							 unsigned int	height,
							 bool			fullscreen,
							 const char		*name);
```

La fonction `bunny_start()` ouvre une fenêtre dont le nom est spécifié par
`name`. `width` et `height` indiquent la taille de la fenêtre, `fullscreen`
doit être égal à `0` pour que la fenêtre soit en plein écran.

Noter qu’il n’y a aucun moyen de redimensionner une fenêtre une fois
qu’elle à été créée. Seul l’utilisateur peut changer sa taille manuellement.
Il est toutefois possible de détecter les redimensionnements de
l’utilisateur grâce aux évenements.

*TODO: Rajouter un exemple*

### Méthode avancée ###

```
t_bunny_window	*bunny_start_style(unsigned int			width,
								   unsigned int			height,
								   t_bunny_window_style	winstyle,
								   const char			*name);
```

**Avertissement** : Cette fonction n’est pas décrite dans la
documentation officielle.

*TODO: Rajouter un exemple*

## Fermer la fenêtre ##
