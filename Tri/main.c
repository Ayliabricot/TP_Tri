#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	
	int taille = 80;
	Medicament** tableau = creerTableau(taille);
	
	for (int i = 0; i < taille; i++) {
		tableau[i] = creerMedicament();
	}

	afficher(tableau,taille);
	

	return 0;
}