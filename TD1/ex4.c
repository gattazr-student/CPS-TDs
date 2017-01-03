#include <stdio.h>

void q1(void){
    int wNbPair;
    unsigned int wX;
    int wI;

    wNbPair = 0;
    wI = 0;
    while(wI < 10){
        printf("Saisir un entier positif : ");
        scanf("%u", &wX);
        if(wX % 2 == 0){
            wNbPair++;
        }
        wI++;
    }
    printf("Vous avez saisi %d entiers pairs\n", wNbPair);
}

void q2(void){
    int wNbPair;
    unsigned int wX;
    int wI;
    int wContinue;

    wNbPair = 0;
    wI = 0;
    wContinue = 1;
    while(wContinue == 1){
        printf("Saisir un entier positif : ");
        scanf("%u", &wX);
        if(wX == 0){
            wContinue = 0;
        } else if(wX % 2 == 0){
            wNbPair++;
        }
    }
    printf("Vous avez saisi %d entiers pairs\n", wNbPair);
}

int main(void){
    q2();
    return 0;
}
