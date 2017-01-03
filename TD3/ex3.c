#include <stdio.h>

int main(void) {

	int t[7];
	int x = 5;
	int y = 36;
	int wI;
	int *p;
	/*
	1.
		t est un tableau d'entier. "t+1" correspond donc à l'adresse du second élement du tableau (à
		 l'indice 1) et "t+2" à l'adresse du troisième élement du tableau (à l'indice 2).

		"*(t+i)" avec i un entier est équivalent à t[i]. "*(t+1)" et "*(t+2)" correspondent alors
		respectivement aux valeurs situés aux indices 1 et 2 du tableau T.

		"&t[1]" correspont à l'adresse du premier élement du tableau. Cela correspont donc à la même chose
		 que "t+1". Et "&t[2]" est donc équivalent à "t+2"
	2.
		int *p = t; -> le pointeur p est déclaré et pointe sur le premier élement de t
		p = &x;     -> p pointe sur l'adresse de x
		*p = 371;   -> la variable pointé par t est affecté à 371. On a donc x = 371;
		t = p;      -> illégal. t est un tableau. Il n'est pas possible de changer sa référence
		t = &y;     -> illégal pour la même raison.
	*/

	/* Pour effectuer les tests sur le tableau, on initialise ses valeurs */
	for(wI=0; wI<7; wI++){
		t[wI] = wI;
	}

	printf("Vérification des prévisions : \n");
	for(wI=0; wI<7; wI++){
		printf("Adresse de t+%d : %p = %p\t Contenu à t+%d : %d = %d\n",
		wI, (void *)(t+wI), (void *)(&t[wI]), wI, *(t+wI), t[wI]);
	}

	p = t;
	printf("\nAdresse pointée par p : %p\tAdresse de t : %p\n", (void*)(p), (void*)(t));

	p = &x;
	printf("Adresse pointée par p : %p\tAdresse de x : %p\n", (void*)(p), (void*)(&x));

	*p = 371;
	printf("Valeur  pointée par p : %d\t\tValeur  de x : %d\n",*p, x);

	return 0;
}
