#include <stdio.h>

int suite(int aTerme, int aInit){
    int wResult = aInit;
    for(int wI = 0; wI < aTerme; wI++ ){
        wResult = wResult * 3 + 2;
    }
    return wResult;
}


int main(void){

    int wTerme;
    int wInit;
    int wResult;

    do{
        printf("Quelle est le premier terme ? ");
        scanf("%d", &wInit);

        printf("Quelle terme retourner ? ");
        scanf("%d", &wTerme);

        if(wTerme != -1 && wTerme >= 0){
            // calcul de la valeur
            wResult = suite(wTerme, wInit);
            printf("Le résultat est %d\n", wResult);
        }
    }while( wTerme != -1 );

    return 0;
}
