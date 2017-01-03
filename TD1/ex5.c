#include <stdio.h>

int main(void){
    int wM, wN;
    int wMult;

    printf("Saisir la born inf puis la borne supr pour la recherche : ");
    scanf("%d %d", &wM, &wN);

    while (wM > wN){
        printf("Attention saisir la borne inf puis la born sup : ");
        scanf("%d %d", &wM, &wN);
    }

    wMult = wM % 3;
    if(wMult == 1){
        wMult = 2;
    }else if(wMult == 2){
        wMult = 1;
    }

    for(wMult += wM; wMult <= wN; wMult += 3) {
        printf("%d ", wMult);
    }
    printf("\n");


    return 0;
}
