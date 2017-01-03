#include <stdio.h>
#include <stdlib.h>
#include <crible.h>


/**
 * main
 * Fonction de test
 */
int main(void){
    int *wCrible;
    int wMax;

    /* Récupère le nombre d'entiers*/
    printf("Entiers premiers jusqu'a ? ");
    scanf("%d", &wMax);

    /* Allocation en mémoire d'un table de NMAX entier */
    wCrible = (int *) malloc(sizeof(int)*NMAX);


    /* Initialisation du crible */
    initialiserCrible(wCrible, NMAX);
    /* Construit le crible */
    construit_crible(wCrible, NMAX, wMax);
    /* Affiche le crible */
    afficherCrible(wCrible, NMAX, wMax);
    return 0;
}
