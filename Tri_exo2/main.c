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

	tri_insertion(tableau, taille);

	printf("\n\nPar ordre alphabetique :\n");
	afficher(tableau, taille);

	libererMemoire(tableau, taille);

	return 0;
}