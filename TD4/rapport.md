CPS - TD4
=========

Exercice 1
----------

NMAX est une pseudo-constante définie par une directive ``#define``. Il ne s'agit donc pas réellement d'une variable.
L'utilisation de ceci permet, pendant la compilation, de remplacer toutes les occurences de NMAX sont remplacés par la
valeur de NMAX.

Si l'on supprime la définition de NMAX dans le fichier main.c, le compilateur ne saura alors pas par quoi remplacer
NMAX et le programme ne compilera donc pas.

En rajoutant dans les options de compilations ``-DNMAX=200``, la pseudo-constante sera alors définie et le programme
compilera donc bien.

Exercice 2
----------

Les librairies partagées sont chargées au démarrage du programme. Si parmis ces librairies, certaines ne se trouvent pas
dans un emplacement référencé par la variable d'envrionnement $LD_LIBRARY_PATH, alors le programme ne les trouvera pas
et donc ne se lancera pas.

Pour pouvoir lancer le programme, il a donc fallu rajouter le dossier lib de notre projet à la variable
$LD_LIBRARY_PATH.
