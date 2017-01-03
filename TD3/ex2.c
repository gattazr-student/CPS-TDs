#include <stdio.h>

void fact(int x, int *f){
	int i;
	*f = 1;
	for (i = 1; i <= x; i++){
		*f *= i;
	}
}

int main(void){
	int x, res;
	printf("Saisir la valeur pour le calcul de factorielle: ");
	scanf("%d", &x);
	fact(x, &res);
	printf("Factorielle(%d) est %d\n", x, res);

	return 0;
}
