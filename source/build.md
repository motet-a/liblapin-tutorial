
# Compilation #

Les exemples fonctionnent si la liblapin est installée correctement.

Si vous avez utilié le script `fake_install.sh`, le script
d’initialisation de votre shell (`.bashrc`, `.zshrc` ou autre)
doit normalement contenir les lignes suivantes :

```sh
export LD_LIBRARY_PATH="/home/${USER}/.froot/lib/"
export C_INCLUDE_PATH="/home/${USER}/.froot/include/"
export CPLUS_INCLUDE_PATH="/home/${USER}/.froot/include/"
```
