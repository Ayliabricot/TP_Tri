#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Medicament** creerTableau(int taille) {
	Medicament** tableau = malloc(taille * sizeof(Medicament*));
	for (int i = 0; i < taille; i++) {
		tableau[i] = NULL;
	}

	return tableau;
}

Medicament* creerMedicament(void) {
	char nom[50];
	char code[50];
	int fabrication;
	int peremption;
	float prix;
	int vendus;
	int stock;

	printf("\n\nVeuillez saisir le nom : ");
	scanf_s("%s", &nom, sizeof(nom));

	printf("Veuillez saisir le code : ");
	scanf_s("%s", &code, sizeof(code));

	printf("Veuillez saisir la date de fabrication : ");
	scanf_s("%d", &fabrication);

	printf("Veuillez saisir la date de peremption : ");
	scanf_s("%d", &peremption);

	printf("Veuillez saisir le prix : ");
	scanf_s("%f", &prix);

	printf("Veuillez saisir le nombre d'articles vendus : ");
	scanf_s("%d", &vendus);

	printf("Veuillez saisir le nombre d'articles en stock : ");
	scanf_s("%d", &stock);

	Medicament* medicament = malloc(sizeof(Medicament));
	
	if (medicament == NULL) {
		return;
	}

	strcpy_s(medicament->nom, 50, nom);
	strcpy_s(medicament->code, 50, code);
	medicament->fabrication = fabrication;
	medicament->peremption = peremption;
	medicament->prix = prix;
	medicament->vendus = vendus;
	medicament->stock = stock;

	return medicament;
}

void afficher(Medicament** tableau, int taille) {
	for (int i = 0; i < taille; i++) {
		printf("\nNom : %s | Code : %s | Fabrication : %d | Peremption : %d | Prix : %.2f | Vendus : %d | Stock : %d", tableau[i]->nom, tableau[i]->code, tableau[i]->fabrication, tableau[i]->peremption, tableau[i]->prix, tableau[i]->vendus, tableau[i]->stock);
	}
}


void tri_a_bulles_optimise(Medicament** T, int taille) {
	int i, j;
	int n1;
	int n2;
	int swapped;
	for (i = 0; i < taille - 1; i++) {
		swapped = 1;
		for (j = 0; j < taille - 1; j++) {
			n1 = T[j + 1]->peremption % 10000;
			n2 = T[j]->peremption % 10000;
			if (n1 < n2) {
				swap(&T[j], &T[j + 1]);
				swapped = 1;
			}
			else if (n1 == n2) {
				n1 = (T[j + 1]->peremption / 10000)%100;
				n2 = (T[j]->peremption / 10000) % 100;
				if (n1 < n2) {
					swap(&T[j], &T[j + 1]);
					swapped = 1;
				}
				else if (n1 == n2) {
					n1 = (T[j + 1]->peremption / 10000) / 100;
					n2 = (T[j]->peremption / 10000) / 100;
					if (n1 < n2) {
						swap(&T[j], &T[j + 1]);
						swapped = 1;
					}
				}
			}
			afficher(T, taille);
		}
		printf("\n");
		if (swapped == 0) {
			break;
		}
	}
}

void swap(Medicament* i, Medicament* j) {
	Medicament temp = *i;
	*i = *j;
	*j = temp;
}