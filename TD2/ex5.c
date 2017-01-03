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
        z = x / y;
        printf("Le résultat est : %d\n", z);
        return 0;
    }
}

/*
 1) L'instruction dans le if est une affectation. y va être mis à 0. Et puisque 0 = false, on va executer le else.
 Or maitenant que y = 0, la division de x par y va créer une erreur.

 2) On a corrigé l'erreur en modifiant le if  : if(y == 0)

 3) Lorsque un programme termine correctement, le code de sortie du programme est 0. Sinon, il peut avoir une valeur différente.

 Dans le cas ou y était différent de 0, on a pu constater que la valeur de sortie était à 0 et le résultat cohérent.
 Avec y = 0 en revanche, une erreur a été affiché et le code de sortie était 1.

 Pour consulter le code de sortie d'un programme, on utlise la commande "echo $?"

 4) ./ex5 > res.txt && mv res.txt Resultats/

*/
