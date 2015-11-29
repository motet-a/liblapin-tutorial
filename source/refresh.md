
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

## Fonction rafraîchissante ##

Votre fonction rafraîchissante sera la fonction rappelée
rappellée à une fréquence donnée par la liblapin.
C’est dans cette fonction que vous devrez mettre toutes les
intructions devant être exécutées régulièrement par votre
application (par exemple, dans le cas d’un jeu à la
première personne, il faut capter les entrées clavier,
faire avancer le joueur, détecter les collisions, redessiner
toute la fenêtre, etc).
Cette fonction devra pouvoir être pointée par un `t_bunny_loop`,
qui est défini ainsi :

```c
typedef t_bunny_response	(*t_bunny_loop)(void *your_data);
```

Votre fonction devra donc prendre en paramètre un pointeur
sur `void` et retourner un `t_bunny_response`, qui est
un [type énuméré][enum]. Peut importe si vous ne connaissez
pas les types énumérés, retenez seulement pour l’instant que
`GO_ON` est un `t_bunny_response`, et que vous devez retourner
`GO_ON` dans votre fonction - un peu comme `main()` doit retourner `0`
lorsque le programme se termine avec succès.

Voici un modèle vide, à compléter, de fonction rafraîchissante :

```c
t_bunny_response	    refresh_my_game(void *my_data)
{
  /*
  ** Écrire ici les instructions permettant d’actualiser le jeu.
  */
  return (GO_ON);
}
```

Nous verrons plus tard qu’il est possible d’utiliser le
pointeur `my_data` pour passer à votre fonction rafraîchissante
des données concerant l’état de votre application.

## Signaler la fonction rafraîchissante ##

```c
void	bunny_set_loop_main_function(t_bunny_loop loop);
```

Cette fonction sert à indiquer à la liblapin votre fonction rafraîchissante.
Notez que `bunny_set_loop_main_function()` ne lance pas le rafraîchissement.

Pour dire à la liblapin d’utiliser `refresh_my_game()` comme fonction
rafraîchissante, vous avez juste à passer l’addresse de `refresh_my_game()`
en paramètre de `bunny_set_loop_main_function()` :

```c
bunny_set_loop_main_function(&refresh_my_game);
```

## Lancer le rafraîchissement ##

```c
t_bunny_response	bunny_loop(t_bunny_window *window,
							   unsigned char frequency,
							   void *your_data);
```

`bunny_loop()` lance le rafraîchissementsur une fenêtre
donnée à une fréquence donnée (en Hertz).

`bunny_set_loop_main_function()` doit être appellée avant
d’appeller `bunny_loop()`.

## Exemple ##

*À écrire*

[enum]: https://en.wikipedia.org/wiki/Enumerated_type
