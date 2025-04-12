#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

Player** creerTableau(int taille) {
	Player** tableau = malloc(taille * sizeof(Player*));

	for (int i = 0; i < taille; i++) {
		tableau[i] = NULL;
	}

	return tableau;
}

void triRole(Player** T, int taille) {
	int i, j;
	int swapped;

	if (T == NULL) {
		return;
	}
	for (int i = 0; i < taille; i++) {
		if (T[i] == NULL) {
			return;
		}
	}
	for (i = 0; i < taille - 1; i++) {
		swapped = 0;
		for (j = 0; j < taille - 1; j++) {
			if (strcmp(T[j + 1]->role, T[j]->role) < 0) {
				swap(T[j], T[j + 1]);
				swapped = 1;
			}
		}
		if (swapped == 0) {
			break;
		}
	}
}

void triCompetence(Player** T, int taille) {
	int i, j;
	int swapped;

	if (T == NULL) {
		return;
	}
	for (int i = 0; i < taille; i++) {
		if (T[i] == NULL) {
			return;
		}
	}
	for (i = 0; i < taille - 1; i++) {
		swapped = 0;
		for (j = 0; j < taille - 1; j++) {
			if (strcmp(T[j + 1]->role, T[j]->role) == 0 && T[j+1]->skillLevel>T[j]->skillLevel) {
				swap(T[j], T[j + 1]);
				swapped = 1;
			}
		}
		if (swapped == 0) {
			break;
		}
	}
}

void afficher(Player** tableau, int taille) {
	if (tableau == NULL) {
		return;
	}
	for (int i = 0; i < taille; i++) {
		if (tableau[i] == NULL) {
			return;
		}
	}
	for (int i = 0; i < taille; i++) {
		printf("\nNom : %s | ID : %d | Role : %s | Competence : %d", tableau[i]->nom, tableau[i]->id, tableau[i]->role, tableau[i]->skillLevel);
	}
}

void swap(Player* i, Player* j) {
	if (i == NULL) {
		return;
	}
	if (j == NULL) {
		return;
	}
	Player temp = *i;
	*i = *j;
	*j = temp;
}

void definirMedianes(Player** tableau, int taille, int medianes[5]) {
	int debut=0;
	int fin=0;
	int position=0;
	char role[50];
	strcpy_s(role, 50, tableau[0]->role);

	for (int i = 1; i < taille; i++) {
		if (strcmp(tableau[i]->role, role) == 0) {
			fin++;
		}
		else {
			if (debut != fin) {
				medianes[position] = tableau[debut+(fin - debut) / 2]->skillLevel;
			}
			else {
				medianes[position] = tableau[(fin)]->skillLevel;
			}
			position++;
			debut = i;
			fin = i;
			strcpy_s(role, 50, tableau[i]->role);
		}
		if (i == taille-1) {
			if (debut != fin) {
				medianes[position] = tableau[debut + (fin - debut) / 2]->skillLevel;
			}
			else {
				medianes[position] = tableau[(fin)]->skillLevel;
			}
		}
	}
}

Player** definirTableauRole(Player** tableau, int taille, int* compteur, char role[50]) {
	Player** tableauRole = creerTableau(1);
	*compteur = 0;

	for (int i = 0; i < taille; i++) {
		if (strcmp(tableau[i]->role, role) == 0) {
			*compteur++;
			tableauRole = realloc(tableauRole, *compteur * sizeof(Player*));
			tableauRole[*compteur - 1] = tableau[i];
		}
	}
	return tableauRole;
}

Player* choisirMembreEquipe(Player** tableau, int taille, int mediane) {
	int id[20] = { 0 };
	int compteur = 0;

	for (int i = 0; i < taille; i++) {
		if (mediane - 50 <= tableau[i]->skillLevel && tableau[i]->skillLevel >= mediane + 50) {
			id[compteur] = i;
			compteur++;
		}
	}
	if (compteur < 2) {

	}
}