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

<table class="docutils">
  <tr>
    <th>Nom</th><th>Description</th>
  </tr>
  <tr>
    <td>BLACK</td><td>Noir</td>
  </tr>
  <tr>
    <td>BLUE</td><td>Bleu</td>
  </tr>
  <tr>
    <td>GREEN</td><td>Vert</td>
  </tr>
  <tr>
	<td>PINK</td><td>Rose</td>
  </tr>
  <tr>
	<td>PURPLE</td><td>Violet</td>
  </tr>
  <tr>
	<td>RED</td><td>Rouge</td>
  </tr>
  <tr>
	<td>TEAL</td><td>Cyan</td>
  </tr>
  <tr>
	<td>WHITE</td><td>Blanc</td>
  </tr>
  <tr>
	<td>YELLOW</td><td>Jaune</td>
  <tr>
</table>

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
  void	* const		*pixels;
}					t_bunny_pixelarray;
```

Le membre `pixels` contient le tableau de pixels interne,
et le membre `clipable` contient diverses informations dont la taille du
`t_bunny_pixelarray`.

## Créer un t_bunny_pixelarray ##

```c
t_bunny_pixelarray	*bunny_new_pixelarray(unsigned int	width,
										  unsigned int	height);
```

La fonction `bunny_new_pixelarray()` crée un nouveau `t_bunny_pixelarray`
de taille donnée.

## Détruire un t_bunny_pixelarray ##

```c
void		bunny_delete_clipable(t_bunny_clipable	*clipable);
```

Cette fonction peut servir à détruire un `t_bunny_pixelarray` dont le clipable
lui est passé en paramètre.

## Dessiner sur un t_bunny_pixelarray ##

Le membre `pixels` d’un `t_bunny_pixelarray` peut être converti en un
tableau d’entiers non signés de 32 bits, représentant la liste des pixels.

Cela signifie que chaque case du tableau représente un pixel,
respectivement dans l’ordre de gauche à droite.

Si un `t_bunny_pixelarray` fait 3 pixels de haut sur 4 pixels de large,
ses 12 pixels seront disposés ainsi :

```
<- largeur ->

0   1   2   3   ^
                |
4   5   6   7  hauteur
                |
8   9  10  11   v
```

Ainsi, la case 0 du tableau correspond au pixel en haut
à gauche de l’écran, la case 1 au pixel juste à sa droite,
et ainsi de suite.

## Transférer un t_bunny_pixelarray vers une fenêtre ##

```c
void	bunny_blit(t_bunny_buffer			*buffer,
				   const t_bunny_clipable	*picture,
				   const t_bunny_position	*position);
```

Cette fonction peut servir à transférer un `t_bunny_pixelarray`
vers une fenêtre.
Il suffit de l’appeller avec le buffer de la fenêtre et le
clipable du `t_bunny_pixelarray` :

```c
void				blit_to_window(t_bunny_window *window,
				       		const t_bunny_pixelarray *pixelarray)
{
  t_bunny_position	position;

  position.x = 0;
  position.y = 0;
  bunny_blit(&window->buffer, &pixelarray->clipable, &position);
}
```

N'oubliez pas d'appeler ensuite la fonction `bunny_display` pour afficher ce que vous venez de transferer ! 

[Voir le fichier][blit.c]

[format RGBA]: https://en.wikipedia.org/wiki/RGBA_color_space
[endianness]: https://fr.wikipedia.org/wiki/Endianness
[blit.c]: https://github.com/motet-a/liblapin-tutorial/blob/master/examples/drawing/blit.c
