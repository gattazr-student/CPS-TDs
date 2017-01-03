#include <stdio.h>

int factorielle(int aRang){
    int wFact = 1;
    for(int wI = 2; wI <= aRang; wI++){
        wFact = wFact * wI;
    }
    return wFact;
}

int factorielleRecursive(int aRang){
    if(aRang == 0){
        return 1;
    }else{
        return factorielleRecursive(aRang-1)*aRang;
    }

}

int somme(int aRang){
    int wSomme = 0;
    for(int wI = 1; wI <= aRang; wI++){
        wSomme = wSomme + wI;
    }
    return wSomme;
}

int sommeRecursive(int aRang){
    if(aRang == 0){
        return 0;
    }else{
        return aRang + sommeRecursive(aRang-1);
    }
}

int main(void){
    int wRang;

    do{
        printf("Quelle est le rang à calculer ? ");
        scanf("%d", &wRang);

        if(wRang > 0){
            printf("Le résultat de factorielle %d est %d\n", wRang, factorielleRecursive(wRang));
            printf("Le résultat de la somme des %d premiers entiers est %d\n", wRang, sommeRecursive(wRang));
        }
    }while(wRang != -1);

    // A partir du rang 17, la valeur de factorielle est incorrect.
    // Ce problème vient du fait que la valeur maximum d'un entier signé
    // codé sur 32 bits est (2^31)-1 et que !17 > 2^31.
    return 0;
}
