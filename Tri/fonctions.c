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

	printf("Veuillez saisir le nom : ");
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
	medicament->precedent = NULL;
	medicament->suivant = NULL;

	return medicament;
}

void ajouter(Medicament** medicaments, Medicament* nouveau) {
	if (nouveau==NULL) {
		return;
	}
	if (*medicaments == NULL) {
		*medicaments = nouveau;
		return;
	}
	else if ((*medicaments)->suivant == NULL) {
		nouveau->precedent = *medicaments;
		(*medicaments)->suivant = nouveau;
	}
	else {
		ajouter(&(*medicaments)->suivant, nouveau);
	}
}

void afficher(Medicament* med) {
	if (med == NULL) {
		return;
	}
	else{
		printf("\nNom : %s | Code : %s | Fabrication : %d | Peremption : %d | Prix : %.2f | Vendus : %d | Stock : %d", med->nom, med->code, med->fabrication, med->peremption, med->prix, med->vendus, med->stock);
		afficher(med->suivant);
	}
}

void tri_a_bulles_code(Medicament** medicament, int taille, int* swapped) {
	
	

	if (medicament == NULL || *medicament == NULL || (*medicament)->suivant==NULL) {
		return;
	}
	
	for (int i = 0; i < taille - 1; i++) {
		printf("\n");
		*swapped = 0;
		*medicament = comparer(&(*medicament), &(*medicament)->suivant, swapped);
		if (swapped == 0) {
			break;
		}
	}
}

Medicament* comparer(Medicament** med1, Medicament** med2, int* swapped) {
	if (*med1 == NULL || *med2 == NULL) {
		return NULL;
	}
	if (strcmp((*med2)->code, (*med1)->code) < 0) {
		*swapped = 1;
		swap(*med1, *med2);
		*med1 = (*med1)->precedent;
		comparer(&(*med1)->suivant, &(*med2), swapped);
	}
	else {
		comparer(&(*med2), &(*med2)->suivant, swapped);
	}
	return *med1;
}

void swap(Medicament* i, Medicament* j) {
	if (i == NULL) {
		return;
	}
	if (j == NULL) {
		return;
	}
	i->suivant = j->suivant;
	j->precedent = i->precedent;
	j->suivant = i;
	i->precedent = j;
	Medicament temp = *i;
	i = j;
	j = &temp;
}

void libererMemoire(Medicament* medicament) {
	if (medicament != NULL) {
		libererMemoire(medicament->suivant);
		free(medicament);
		medicament = NULL;
	}
	return;
}