#include <stdio.h>

void q1(){
    // initialisation des paramètres
    unsigned int wX;
    unsigned int wSomme;
    int wI;

    // on lit la valeur au clavier
    printf("Saisir la borne pour le calcul de la somme : ");
    scanf("%u", &wX);

    // avec un for
    wSomme = 0;
    for( wI = 1; wI <= wX; wI++ ){
        wSomme = wSomme + wI;
    }

    // avec un while
    // wSomme = 0;
    // wI = 0;
    // while(wI <= wX){
    //     wSomme = wSomme + wI;
    //     wI++;
    // }

    // affichage du résultat
    printf("La somme des entiers de 1 à %d est %d\n", wX, wSomme);
}

void q2(){

    // initialisation des paramètres
    unsigned int wX, wY;
    unsigned int wSomme;
    int wI;

    // on lit les deux valeurs au clavier
    printf("Saisir la borne infé puis la born sup pour votre somme : ");
    scanf("%u %u", &wX, &wY);

    while (wX > wY){
        printf("Attention saisir la borne inf puis la born sup : ");
        scanf("%u %u", &wX, &wY);
    }

    // avec un for
    wSomme = 0;
    for( wI = wX; wI <= wY; wI++ ){
        wSomme = wSomme + wI;
    }

    // affichage du résultat
    printf("La somme des entiers de %d à %d est %d\n", wX, wY, wSomme);

}

int main (void){

    q1();
    q2();
    return 0;
}
