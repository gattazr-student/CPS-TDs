#include <utils.h>

/**
 * present
 * retourne 1 si la clé aKey est présent dans le crible aCrible. 0 sinon
 * @param aKey clé
 * @param aCrible crible
 * @return 1 si la clé aKey est dans le crible aCrible. 0 sinon
 */
int present(int aKey, int *aCrible){
	return aCrible[aKey];
}

/**
 * suppression
 * supprimer la clé aKey dans le crible aCrible.
 * @param aKey clé
 * @param aCrible crible
 */
void suppression(int aKey, int *aCrible){
	aCrible[aKey] = 0;
}
