#include <stdio.h>

void mystere(unsigned int x, unsigned int *res){
	*res = 1 << x;
}

int main(void){
	unsigned int val;
	mystere(5, &val);
	printf("Resultat = %u\n", val);
	return 0;
}

/*
La fonction mystère met dans *res le résultat de 2^x
Dans la première version du programme, *res n'était pas initialisé. Du coup,
lors de la fonction mystère, l'écriture à l'adresse pointé par res à créé une
erreur de segmentation.

Pour corriger le problème, j'ai défini val comme étant un entier et passé
l'adresse de val à la fonction mystère. Il a aussi fallu modifier le printf.

*/
