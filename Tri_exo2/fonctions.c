#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Etudiant** creerTableau(int taille) {
    Etudiant** tableau = malloc(taille * sizeof(Etudiant*));
    for (int i = 0; i < taille; i++) {
        tableau[i] = NULL;
    }

    return tableau;
}

Etudiant* creerEtudiant(void) {
    char nom[50];
    char prenom[50];
    char matricule[50];
    float moyenne;

    printf("Veuillez saisir le nom de l'etudiant : ");
    scanf_s("%s", &nom, sizeof(nom));

    printf("Veuillez saisir son prenom : ");
    scanf_s("%s", &prenom, sizeof(prenom));

    printf("Veuillez saisir son matricule : ");
    scanf_s("%s", &matricule, sizeof(matricule));

    printf("Veuillez saisir sa moyenne : ");
    scanf_s("%f", &moyenne);

    Etudiant* etudiant = malloc(sizeof(Etudiant));

    if (etudiant == NULL) {
        return;
    }

    strcpy_s(etudiant->nom, 50, nom);
    strcpy_s(etudiant->prenom, 50, prenom);
    strcpy_s(etudiant->matricule, 50, matricule);
    etudiant->moyenne = moyenne;

    return etudiant;
}

void afficher(Etudiant** tableau, int taille) {
    printf("\nListe d'eleves:\n");
    if (tableau == NULL || taille == 0) {
        return;
    }
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == NULL) {
            return;
        }
    }
    for (int i = 0; i < taille; i++) {
        printf("\nNom : %s | Prenom : %s | Matricule : %s | Moyenne : %.2f", tableau[i]->nom, tableau[i]->prenom, tableau[i]->matricule, tableau[i]->moyenne);
    }
}

int comp_moyenne(const void* a, const void* b) {
    Etudiant* etudiantA = *(Etudiant**)a;
    Etudiant* etudiantB = *(Etudiant**)b;

    if (etudiantA->moyenne > etudiantB->moyenne) {
        return -1;
    }
    if (etudiantA->moyenne < etudiantB->moyenne) {
        return 1;
    }
}

void tri_insertion(Etudiant** tableau, int taille) {
    if (tableau == NULL) {
        return;
    }
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == NULL) {
            return;
        }
    }
    Etudiant* x=NULL;
    int j;
    for (int i = 1; i < taille; i++) {
        x = tableau[i];
        j = i;
        while (j > 0 && strcmp(tableau[j - 1]->nom, x->nom)>0) {
            tableau[j] = tableau[j - 1];
            j = j - 1;
        }
        tableau[j] = x;
    }
}

void libererMemoire(Etudiant** tableau, int taille) {
    for (int i = 0; i < taille; i++) {
        free(tableau[i]);
        tableau[i] = NULL;
    }
    free(tableau);
    tableau = NULL;
}