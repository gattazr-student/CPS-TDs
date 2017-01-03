#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BORNEINF 1
#define BORNESUP 1000
#define N 100

/**
 * random
 * retourne un entier aléatoire entre aBorneInf et aBorneMax
 * @param aBorneInf
 * @param aBorneMax
 * @return entier aléatoire entre aBorneInf et aBorneMax
 */
int getRandom(int aBorneInf, int aBorneMax){
	return rand() % (aBorneMax-aBorneInf+1) + aBorneInf;
}

/**
 * init
 * remplit le tableau *aTab de taille aTaille de nombre aléatoire entre BORNEINF
 * et BORNESUP
 * @param *aTab tableau
 * @param aTaille taille du tableau aTab
 */
/*
void init(int *aTab, int aTaille){
	int wI ;
	for(wI=0; wI < aTaille; wI++){
		aTab[wI] = getRandom(BORNEINF, BORNESUP);
	}
}
*/


int* init(int aTaille){
	int wI;
	int* wTab = malloc(sizeof(int)*aTaille+1);
	for(wI=0; wI < aTaille; wI++){
		wTab[wI] = getRandom(BORNEINF, BORNESUP);
	}
	return wTab;
}

/**
 * recherche
 * recherche la valeur aValue dans le tableau aTab de taille aTab
 * @param
 * @param
 * @param
 * @return -1 si la valeur n'est pas dans le tableau. l'indice ou se trouve la
 *         valeur sinon
 */
int recherche(int aValue, int *aTab, int aTaille){
	int wI;
	for(wI = 0; wI < aTaille; wI++){
		if(aTab[wI] == aValue){
			return wI;
		}
	}
	return -1;
}

int main(void){
	int wSearch;
	int wResult;
	/* int wTab[N];*/
	int* wTab;

	srand(time(NULL)); /* Mise en place du seed pour l'aléatoire */

	/* Initialise le tableau wTab */
	/* init(wTab, N); */
	wTab = init(N);

	wSearch = getRandom(BORNEINF, BORNESUP); /* Valeur à rechercher */

	wResult = recherche(wSearch, wTab, N);
	if(wResult != -1){
		printf("La valeur %d se trouve à l'indice %d du tableau\n", wSearch, wResult);
	}else{
		printf("La valeur %d ne se trouve pas dans le tableau\n", wSearch);
	}

	return 0;
}