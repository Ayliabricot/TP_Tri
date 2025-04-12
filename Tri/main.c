#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	
	int taille = 80;
	int* swapped = malloc(sizeof(int));
	*swapped = 0;

	Medicament** L = creerTableau(taille);
	
	for (int i = 0; i < taille; i++) {
		ajouter(L, creerMedicament());
		printf("\n\n");
	}

	afficher(*L);
	
	tri_a_bulles_code(L, taille,swapped);

	afficher(*L);

	for (int i = 0; i < taille; i++) {
		free(L[i]);
		L[i] = NULL;
	}
	free(L);
	L = NULL;

	return 0;
}