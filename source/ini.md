
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

Les champs `data` sont particuliers : Ils contiennent une liste de données,
séparées par des virgules. Notez que cette liste peut s’étendre sur plusieurs
lignes, comme dans l’exemple ci-dessus.

## Lire un fichier INI ##

Tout d'abord, il faut charger le fichier INI avec la fonction
`bunny_load_ini()`.
Elle prend en paramètre l’adresse du fichier INI et retourne un pointeur
sur un nouveau `t_bunny_ini`.
N'oubliez pas de supprimer le `t_bunny_ini` avec la fonction
`bunny_delete_ini()`.

Exemple :

```c
t_bunny_ini	*ini;

ini = bunny_load_file("test.ini");
if (ini == NULL)
    my_putstr("Fichier introuvable\n");
else
    my_putstr("Fichier chargé !\n");
bunny_delete_ini(ini);
```

Ensuite, nous pouvons accéder aux variables qui nous intéressent avec
la fonction `bunny_ini_get_field()`.
Elle prend quatre paramètres :

- le pointeur sur notre `t_bunny_ini`
  - le nom de la section
  - le nom du champ
  - l’index de la donnée qui nous intéresse lorsque le champ est
  une liste séparée par des virgules (ou 0 si le champ n’est pas une liste)

Elle retourne soit une chaîne contenant la valeur, soit `NULL`.

Attardons-nous un instant sur ce dernier paramètre : la fonction
`bunny_ini_get_field()` gère automatiquement un champ qui contient
plusieurs variables, spéraées par un espace :

```
[forme1]
data=-12,24,36
```

Sur ce fichier, `bunny_ini_get_field(ini, "forme1", "data", 0)`,
retournera sera une chaîne de caractères contenant `"-12"`.
En mettant en dernier paramètre le nombre 1, la chaîne de caractères
correspondra alors à `"24"`, et `"36"` si le dernier paramètre
est égal à 2.

Pour en revenir au cas du fil de fer, il faut d'abord récupérer
`width` et `height`, et incrémenter une variable temporaire de 0
jusqu'à `width * height` (avec `width` et `height > 0`).
Cette variable temporaire est le numéro de la data à récupérer.

Exemple pour récupérer la variable `width` :

```c
t_bunny_ini	*ini;
int			width;

ini = bunny_load_file("test.ini");
width = 0;
if (ini == NULL)
   my_putstr("Fichier introuvable\n");
else
  {
    if (bunny_ini_get_field(ini, "forme1", "width", 0) != NULL)
      width = my_get_number(bunny_ini_get_field(ini, "forme1", "width", 0));
    else
      my_putstr("Le champs width dans le scope forme1 est introuvable :\n");
  }
bunny_delete_ini(ini);
```

Voila ! Bon courage pour la suite :)

[wikipedia]: https://en.wikipedia.org/wiki/INI_file
