
# Rafraîchissement #

Il est très souvent nécéssaire de rafraîchir une fenêtre à
une fréquence donnée.
La liblapin permet de faire cela en rappellant automatiquement
une de vos fonctions, qui sera chargée de rafraîchir votre
fenêtre.

Vous devez procéder en trois étapes :

  - Écrire la fonction « rafraîchissante » qui
  sera rappellée régulièrement par la liblapin ;
  - Indiquer à la liblapin votre fonction « rafraîchissante » -
  en lui passant un pointeur vers votre fonction ;
  - Indiquer à la liblapin votre fenêtre à rafraîchir et la
  fréquence de rafraîchissement.

## Signaler la fonction rafraîchissante ##

```c
void	bunny_set_loop_main_function(t_bunny_loop loop);
```

## Lancer le rafraîchissement ##

```c
t_bunny_response	bunny_loop(t_bunny_window *window,
							   unsigned char frequency,
							   void *your_data);
```

## Exemple ##

*À écrire*
