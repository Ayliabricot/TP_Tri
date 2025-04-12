#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main() {
	int taille = 20;

	Player** tableau = creerTableau(taille);

    tableau[0] = malloc(sizeof(Player));
    tableau[0]->id = 1;
    strcpy(tableau[0]->nom, "Caps");
    tableau[0]->skillLevel = 93;
    strcpy(tableau[0]->role, "Mid");

    tableau[1] = malloc(sizeof(Player));
    tableau[1]->id = 2;
    strcpy(tableau[1]->nom, "Keria");
    tableau[1]->skillLevel = 95;
    strcpy(tableau[1]->role, "Support");

    tableau[2] = malloc(sizeof(Player));
    tableau[2]->id = 3;
    strcpy(tableau[2]->nom, "Cabochard");
    tableau[2]->skillLevel = 90;
    strcpy(tableau[2]->role, "Top");

    tableau[3] = malloc(sizeof(Player));
    tableau[3]->id = 4;
    strcpy(tableau[3]->nom, "Peanut");
    tableau[3]->skillLevel = 93;
    strcpy(tableau[3]->role, "Jungle");

    tableau[4] = malloc(sizeof(Player));
    tableau[4]->id = 5;
    strcpy(tableau[4]->nom, "Chovy");
    tableau[4]->skillLevel = 97;
    strcpy(tableau[4]->role, "Mid");

    tableau[5] = malloc(sizeof(Player));
    tableau[5]->id = 6;
    strcpy(tableau[5]->nom, "Hans Sama");
    tableau[5]->skillLevel = 91;
    strcpy(tableau[5]->role, "ADC");

    tableau[6] = malloc(sizeof(Player));
    tableau[6]->id = 7;
    strcpy(tableau[6]->nom, "Targamas");
    tableau[6]->skillLevel = 88;
    strcpy(tableau[6]->role, "Support");

    tableau[7] = malloc(sizeof(Player));
    tableau[7]->id = 8;
    strcpy(tableau[7]->nom, "Bin");
    tableau[7]->skillLevel = 94;
    strcpy(tableau[7]->role, "Top");

    tableau[8] = malloc(sizeof(Player));
    tableau[8]->id = 9;
    strcpy(tableau[8]->nom, "Viper");
    tableau[8]->skillLevel = 95;
    strcpy(tableau[8]->role, "ADC");

    tableau[9] = malloc(sizeof(Player));
    tableau[9]->id = 10;
    strcpy(tableau[9]->nom, "Canyon");
    tableau[9]->skillLevel = 97;
    strcpy(tableau[9]->role, "Jungle");

    tableau[10] = malloc(sizeof(Player));
    tableau[10]->id = 11;
    strcpy(tableau[10]->nom, "Knight");
    tableau[10]->skillLevel = 96;
    strcpy(tableau[10]->role, "Mid");

    tableau[11] = malloc(sizeof(Player));
    tableau[11]->id = 12;
    strcpy(tableau[11]->nom, "Zeus");
    tableau[11]->skillLevel = 96;
    strcpy(tableau[11]->role, "Top");

    tableau[12] = malloc(sizeof(Player));
    tableau[12]->id = 13;
    strcpy(tableau[12]->nom, "Lehends");
    tableau[12]->skillLevel = 93;
    strcpy(tableau[12]->role, "Support");

    tableau[13] = malloc(sizeof(Player));
    tableau[13]->id = 14;
    strcpy(tableau[13]->nom, "Gumayusi");
    tableau[13]->skillLevel = 94;
    strcpy(tableau[13]->role, "ADC");

    tableau[14] = malloc(sizeof(Player));
    tableau[14]->id = 15;
    strcpy(tableau[14]->nom, "Ruler");
    tableau[14]->skillLevel = 96;
    strcpy(tableau[14]->role, "ADC");

    tableau[15] = malloc(sizeof(Player));
    tableau[15]->id = 16;
    strcpy(tableau[15]->nom, "Ming");
    tableau[15]->skillLevel = 94;
    strcpy(tableau[15]->role, "Support");

    tableau[16] = malloc(sizeof(Player));
    tableau[16]->id = 17;
    strcpy(tableau[16]->nom, "Oner");
    tableau[16]->skillLevel = 95;
    strcpy(tableau[16]->role, "Jungle");

    tableau[17] = malloc(sizeof(Player));
    tableau[17]->id = 18;
    strcpy(tableau[17]->nom, "Faker");
    tableau[17]->skillLevel = 99;
    strcpy(tableau[17]->role, "Mid");

    tableau[18] = malloc(sizeof(Player));
    tableau[18]->id = 19;
    strcpy(tableau[18]->nom, "BrokenBlade");
    tableau[18]->skillLevel = 90;
    strcpy(tableau[18]->role, "Top");

    tableau[19] = malloc(sizeof(Player));
    tableau[19]->id = 20;
    strcpy(tableau[19]->nom, "Inspired");
    tableau[19]->skillLevel = 89;
    strcpy(tableau[19]->role, "Jungle");
   
    afficher(tableau, taille);

    triRole(tableau, taille);
    triCompetence(tableau, taille);

    printf("\n");
    afficher(tableau, taille);

    int medianes[5] = {0,0,0,0,0};
    definirMedianes(tableau, taille, medianes);

    for (int i = 0; i < 5; i++) {
        printf("\n%d", medianes[i]);
    }


	return 0;
}