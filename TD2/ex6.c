#include <stdio.h>

int main(void){

    int x,y,z;
    printf("Saisir x ");
    scanf("%d", &x);
    printf("Saisir y ");
    scanf("%d", &y);
    if (y == 0){
        fprintf(stderr, "Division par 0 impossible\n");
        return 1;
    }else{
        printf("On va divisier x par y... ");
        z = ++x / y;
        printf("Le résultat est : %d\n", z);
        x--;
        z = x++ / y;
        printf("Le résultat est : %d\n", z);
        return 0;
    }
}

/*
1)
Avec x = 26 et y = 3.
Le premier résultat est 9 et le second est 8.

Avec ++x, x est incrémenté avant l'instruction z = x/y. Le calcul effectué est donc z = 27 / 3 et après l'instruction x = 27. On a donc z = 3.
Avec x++, x est incrémenté après l'inscruction z = x/y. Le calcul effectué est donc z = 26 / 3 et après l'inscruction x = 27. Puisque il s'agit de la division entière, on a donc z = 8.
*/
