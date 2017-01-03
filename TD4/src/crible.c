#include <stdio.h>
#include <crible.h>
#include <utils.h>

/*
 * initialiserCrible
 * Initialise le crible à 1 pour tous les entiers. 0 et 1 sont initiliasés à 0.
 * aTailleCrible et aMax doivent être supérieur à 3.
 * @param aCrible crible
 * @param aTailleCrible taille du crible
 */
void initialiserCrible(int *aCrible, int aTailleCrible){
	int wI;

	/* Initialise le crible à 1 */
	if(aTailleCrible > 2 ){
		aCrible[0] = 0;
		aCrible[1] = 0;
		for(wI = 2; wI < aTailleCrible; wI++){
			aCrible[wI] = 1;
		}
	}else{
		fprintf(stderr, "Impossible d'initialiser le crible si il a une taille inférieur à 3.");
	}
}

/*
 * construit_crible
 * remplit le crible c de taille aTaille de façon à caractériser les nombres premiers inférieur à aMax
 * @param aCrible crible
 * @param aTailleCrible taille du crible
 * @param aMax majorant des premiers
 */
void construit_crible(int *aCrible, int aTailleCrible, int aMax){
	int wI;
	int wX;
	int wY;
	/* On n'effectue pas l'algorithme si la taille du crible n'est pas suffisament grande¨*/
	if (aMax > aTailleCrible){
		fprintf(stderr, "impossible de trouver les premiers entiers supérieurs à %d\n", aTailleCrible);
		return;
	}

	/* Initialise le crible à 1 */
	for(wI = 2; wI < aMax; wI++){
		aCrible[wI] = 1;
	}

	aCrible[0] = 0; /* 0 n'est pas premier */
	aCrible[1] = 0; /* 1 n'est pas premier */

	wX = 2;
	while(wX < aMax){
		if(aCrible[wX] == 1){
			/* retirer tous les multiples de x à partir de x^2*/
			wY = wX * wX;
			while(wY < aMax){
				/* On part du carré de l'entier (puisque les multiples précédent ont forcément déja été retirés) et on
				retire tous les multiples suivants */
				suppression(wY, aCrible);
				wY += wX;
			}
		}
		wX++;
	}
}

/**
 * afficherCrible
 * afficher les entiers premier selon le crible aCrible jusqu'a aMax
 * @param aCrible crible
 * @param aTailleCrible taille du crible
 * @param aMax majorant des premiers à afficher
 */
void afficherCrible(int *aCrible, int aTailleCrible, int aMax){
	int wI;

	if (aMax > aTailleCrible){
		fprintf(stderr, "Impossible d'afficher les premiers entiers jusqu'a %d avec ce crible\n", aMax);
		return;
	}

	printf("Voici les nombres premiers jusqu'a %d :\n", aMax);

	/* Affichage du premier premier*/
	for(wI = 0; wI < aMax; wI++){
		if(present(wI, aCrible)){
			printf("%d", wI);
			break;
		}
	}
	/* Affichage des autres */
	for(wI++; wI < aMax; wI++){
		if(present(wI, aCrible)){
			printf(", %d", wI);
		}
	}
	printf("\n");
}
