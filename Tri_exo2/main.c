#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {

	int taille = 100;

	Etudiant** tableau = creerTableau(taille);

	for (int i = 0; i < taille; i++) {
		tableau[i] = creerEtudiant();
		printf("\n\n");
	}

	afficher(tableau,taille);

	qsort(tableau, taille, sizeof(Etudiant*), comp_moyenne);

	printf("\n\nPar ordre de mérite :\n");
	afficher(tableau, taille);

	return 0;
}