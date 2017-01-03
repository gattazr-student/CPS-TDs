#include <stdio.h>

int main(void){
    int x,y,z;
    y = 0;
    printf("Saisir x ");
    scanf("%d", &x);
    printf("On va diviser par y... ");
    fflush(stdout);
    z = x / y;
    printf("Le résultat est : %d\n", z);
    return 0;
}
