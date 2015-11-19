# Dessin #

## Couleurs ##

Les couleurs de la liblapin sont représentées grâce à des entiers de 32
bits, autrement dit des `int` sur la plupart des architectures.

Une couleur (et donc un pixel) est encodée au [format RGBA][],
c’est à dire que chaque couleur est constituée de quatre
composantes de 8 bits :
  - Une composante pour le rouge ;
  - Une composante pour le vert ;
  - Une composante pour le bleu ;
  - Une composante pour la transparence, le « canal alpha » ;

La macro `GET_COLOR(rgb)` permet de convertir une couleur `rgb` au format
RGB vers le format RGBA en mettant la nouvelle composante alpha à 255,
de façon à ce que la couleur résultante soit totalement opaque.

La macro `ALPHA(a, rgb)` permet de convertir une couleur `rgb` au format
RGB vers le format RGBA, dont la nouvelle composante alpha sera donnée
par `a`.

Les macros suivantes sont également disponibles :

```
| Nom           | Description   |
|---------------|---------------|
| BLACK         | Noir          |
| BLUE          | Bleu          |
| GREEN         | Vert          |
| PINK          | Rose          |
| PURPLE        | Violet        |
| RED           | Rouge         |
| TEAL          | ?             |
| WHITE         | Blanc         |
| YELLOW        | Jaune         |
```

Noter que la liblapin ne pourra pas être utilisée sur n’importe quelle
architecture, et qu’une bonne compréhension de l’*[endianness][]* est nécéssaire
pour se faire une bonne idée du fonctionnement de la gestion des couleurs.

## Généralités ##

Il n’est pas possible de dessiner directement dans le buffer
d’une fenêtre sans appeller une fonction interdite de la liblapin.
Nous allons donc dessiner dans un tableau de pixels représenté
par le type `t_bunny_pixelarray`, transférer ce tableau de pixels
sur le buffer de la fenêtre, puis mettre à jour la fenêtre.

Le type `t_bunny_pixelarray` est défini ainsi :

```c
typedef struct
{
  t_bunny_clipable	clipable;
  void				*pixels;
}					t_bunny_pixelarray;
```

Le membre `pixels` contient le tableau de pixels interne,
et le membre `clipable` contient diverses informations dont la taille du
`t_bunny_pixelarray`.

## Créer un tableau de pixels ##

```c
t_bunny_pixelarray	*bunny_new_pixelarray(unsigned int	width,
										  unsigned int	height);
```

La fonction `bunny_new_pixelarray()` crée un nouveau `t_bunny_pixelarray`
de taille donnée.

## Détruire un tableau de pixels ##

```c
void		bunny_delete_clipable(t_bunny_clipable	*clipable);
```

Cette fonction peut servir à détruire un `t_bunny_pixelarray` dont le clipable
lui est passé en paramètre.

## Dessiner dans un tableau de pixels ##

Le membre `pixels` d’un `t_bunny_pixelarray` peut être converti vers un
pointeur vers un entier de 32 bits, représentant la liste des pixels.


[format RGBA]: https://en.wikipedia.org/wiki/RGBA_color_space
[endianness]: https://fr.wikipedia.org/wiki/Endianness
