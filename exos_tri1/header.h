#ifndef LOL
#define LOL

typedef struct {
	int id;
	char nom[50];
	int skillLevel;
	char role[50];
}Player;

Player** creerTableau(int taille);

void triRole(Player** T, int taille);
void triCompetence(Player** T, int taille);

void afficher(Player** tableau, int taille);
void swap(Player* i, Player* j);

void definirMedianes(Player** tableau, int taille, int medianes[5]);
Player** definirTableauRole(Player** tableau, int taille, int* compteur, char role[50]);

#endif