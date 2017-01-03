#include <stdio.h>

void g(void){
	int n;
	n = 22;
}

void f(void){
	int compteur;
	compteur ++;
	printf("f --> %d\n", compteur);
}

int main(void){
	f();
	g();
	f();
	return 0;
}
/*
	En lançant le programme, on obtient toujours le résultat suivant :
	f --> 1
	f --> 23

	Dans la fonction f, le compteur n'est pas initialisé. La valeur de compteur est donc la valeur qui se
	situait à ce qui est maintenant &compteur dans la mémoire.

	Au premier appel de f, un entier est crée. Il a été placé en haut de la pile du programme et semble
	toujours valoir 0. Après avoir incrémenté compteur, la fonction effectue alors l'affichage "f --> 1".

	Lors de l'appel de g, une variable va la aussi être crée et placé en haut de la pile. Cette variable va
	être initialisé à 22 puis libéré en fin de fonction. Cette variable n'est donc plus considéré comme
	utile au programme et l'espace mémoire va être réutilisé. Cependant, elle n'a pas été effacé. Cela
	signifie que même si elle n'est plus référencée, la valeur de la variable existe toujours en mémoire.

	Puis, dans le second appel de f, la création de la variable compteur va reprendre le haut de la pile.
	Et sur le haut de la pile se trouve toujours la valeur de la variable n puisqu'elle n'a pas encoré été
	écrasée. On a donc compteur=22. Une fois incrémenté, la fonction effectue donc l'affichage "f --> 23".


*/
