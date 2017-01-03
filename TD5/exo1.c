#include <stdio.h>
#include <stdlib.h>

#define N 20

char lesw[]="wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";

/* Retourne un tableau de stockage pour une chaine de N caracteres */
void allouer (char **tableau) {
  /* Ancienne version de la fonction :
   * char t[N+1];
   * *tableau = t;
   */

  /*
   * CHANGED:
   * Les variables locales sont libérés à la fin de la fonction. L'espace
   * mémoire du tableau qui était déclaré dans la version précédente de la
   * fonction était donc réutilisé.
   * Pour allouer un tableau, on va donc préférer utiliser un malloc.
   * On va aussi créer un fonction libérer qui permettra de libérer la mémoire
   * allouée
   */
   *tableau = malloc(sizeof(char)*(N+1));
}

void liberer(char *tableau){
  free(tableau);
}

/* Retourne la longueur du debut de chaine identique dans les deux chaines */
/* Si dans est lesw, compte le nombre de w dans rechercher                 */
unsigned int longueur_debut_commun(const char *rechercher, const char *dans) {
  unsigned int resultat = 0; /*CHANGED: il fallait initialiser le compteur à 0*/
  while (*rechercher != 0 && *rechercher==*dans) {
    rechercher ++; dans++; resultat++;
  }
  return resultat;
}


void affiche(char *t){
  int j;
  printf("Voici le tableau rempli : \n [ ");
  for (j=0; j < N; j++) { printf("%c ", t[j]);}
  printf(" ] \n");
}

/* alloue un tableau et en remplit les p premieres cases avec c */
char *tableau_rempli (int p, char c) {
  char *tabl;
  int i;
  allouer(&tabl);
  for (i=0; i < p; i++) { tabl[i] = c; }
  tabl[i] = '\0';
  #ifdef DEBUG
    affiche(tabl);
  #endif
  return tabl;
}

void usage (void) {
  fprintf(stderr, "Usage : ./exo1 nb caractere \n");
  fprintf(stderr, "        avec nb <= %u\n",N);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  unsigned int nb;
  char x;
  char *t;
  if (argc != 3 || sscanf (argv[1],"%u",&nb) != 1) usage();
  x = argv[2][0];
  t = tableau_rempli(nb,x);
  nb = longueur_debut_commun(t,lesw);
  printf ("t contient %u 'w'\n",nb);
  liberer(t);
  return 0;
}
