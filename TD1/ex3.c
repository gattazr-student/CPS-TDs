#include <stdio.h>

int main (void){
    int wFact;
    int wX;
    int wI;

    // lecture d'un nombre
    printf("Quelle factorielle calculer ? ");
    scanf("%d", &wX);

    // calcul de la factorielle
    wFact = 1;
    for(wI = 2; wI <= wX; wI++){
        wFact = wFact * wI;
    }

    // affichage du résultat
    printf("Le résultat est %d\n", wFact);

    return 0;
}
