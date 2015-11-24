
# Gestion des fichiers INI #

## Format des fichiers INI ##

Concernant le format INI, [voir l’article sur Wikipedia][wikipedia].

```
[forme1]
type=fdf1
width=6
height=6
data=6,5,3,2,3,4,
4,2,1,1,1,2,
3,1,1,1,1,2,
2,1,1,0,0,1,
0,0,0,0,0,0,
0,0,0,0,0,0

[forme2]
type=fdf1
width=6
height=6
data=6,5,3,2,3,4,
4,2,1,1,1,2,
3,1,1,1,1,2,
2,1,1,0,0,1,
0,0,0,0,0,0,
0,0,0,0,0,0
```

Dans le fichier ci-dessus, on voit deux sections :
  - `forme1`, qui contient les champs `type`, `width`, `height`
  et `data` ;
  - `forme2`, qui contient les même champs.

## Lire un fichier INI ##

Tout d'abord, il faut charger le fichier .ini avec la fonction bunny_load_ini. Elle prend en paramètre le path vers le fichier et retourne un pointeur sur la structure t_bunny_ini.
N'oubliez pas de fermer ensuite le fichier avec bunny_delete_ini !

```c
t_bunny_ini	*ini;

ini = bunny_load_file("test.ini");
if (ini == NULL)
   my_putstr("Fichier introuvable\n");
else
   my_putstr("Fichier chargé !\n");
bunny_delete_ini(ini);
```

Ensuite, nous pouvons accéder aux variables qui nous intéresse avec la fonction bunny_ini_get_field. Elle prend trois paramètres : le pointeur sur notre structure t_bunny_ini, le scope, le field, et le numéro de la data qui nous interesse.

Attardons-nous un instant sur ce dernier paramètre : la fonction bunny_ini_get_field gère automatiquement un field qui contient plusieurs variables, spéraées par un espace.

Voici un fichier exemple:

```
[forme1]
data=-12,24,36
[forme2]
data=-12,
24,
36
```

Si j'appelle la fonction bunny_ini_get_field(ini, "forme1", "data", 0), la valeur retournée sera un string contenant le nombre -12.
En mettant comme dernier paramètre le nombre 1, le string correspondra alors à 24, et respectivement 36 si le dernier paramètre est égal à 2.
Il faut savoir que les retour à la ligne n'ont aucune importance. Ainsi, pour accéder aux datas de forme2, je devrais mettre les mêmes paramètres.

Pour en revenir au cas du fil de fer, il faut d'abord récupérer width et height, et incrémenter une variable temporaire de 0 jusqu'à width * height (avec width et height > 0). Cette variable temporaire est le numéro de la data à récupérer.

Exemple pour récupérer la variable width :

```c
t_bunny_ini	*ini;
int		width;

ini = bunny_load_file("test.ini");
width = 0;
if (ini == NULL)
   my_putstr("Fichier introuvable\n");
else
  {
    if (bunny_ini_get_field(ini, "forme1", "width", 0) != NULL)
      width = my_get_number(bunny_ini_get_field(ini, "forme1", "width", 0));
    else
      my_putstr("Le champs width dans le scope forme1 est introuvable :/\n");
  }
bunny_delete_ini(ini);
```

Voila ! Bon courage pour la suite :)

[wikipedia]: https://en.wikipedia.org/wiki/INI_file
