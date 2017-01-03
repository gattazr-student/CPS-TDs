#include <stdio.h>

int main (void){
    int wM, wN;
    int wPPCM;
    int wTemp;
    int wI;
    int wFound;

    // lecture de M et N
    printf("Entrer deux nombres entiers : ");
    scanf("%d %d", &wM, &wN);

    // on inverse les valeurs si M > N
    if(wM > wN){
        wTemp = wN;
        wN = wM;
        wM = wTemp;
    }

    // recherche du PPCM
    wFound = 1;
    wI = 1;
    while(wFound != 0){
        wPPCM = wM * wI;
        wFound = wPPCM % wN;
        wI++;
    }

    // affichage du PPCM
    printf("Le PPCM de %d et %d est %d\n", wM, wN, wPPCM);

    return 0;
}
