#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {

	int taille = 3;

	Etudiant** tableau = creerTableau(taille);

	for (int i = 0; i < taille; i++) {
		tableau[i] = creerEtudiant();
		printf("\n\n");
	}

	afficher(tableau,taille);

	return 0;
}