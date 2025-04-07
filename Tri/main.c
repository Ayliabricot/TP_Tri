#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	
	int taille = 3;
	Medicament** tableau = creerTableau(taille);
	
	for (int i = 0; i < taille; i++) {
		tableau[i] = creerMedicament();
		printf("\n\n");
	}

	afficher(tableau,taille);
	
	tri_a_bulles_nom(tableau, taille);

	afficher(tableau, taille);

	return 0;
}