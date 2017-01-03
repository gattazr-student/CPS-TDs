#include <stdio.h>

int compte(int x){
    int i;
    for(i = 1; i <= 4; i++)
        x = x*i;
    return x;
}

int main(void){
    int k;
    printf("Saisir la valeur pour le calcul : ");
    scanf("%d", &k);
    printf("La fonction renvoie %d et k vaut maintenant %d\n", compte(k), k);
    return 0;
}

/*
En saisissant n : "La fonction renvoie n*1*2*3*4 et k vaut maintenant n"
La fonction compte ne modifie pas la valeur de k. La variable x dans la fonction compte est une nouvelle variable qui
contient initialement la valeur de k. k est passé par valeur.
*/
