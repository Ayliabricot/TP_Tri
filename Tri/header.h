#ifndef TRI
#define TRI

typedef struct {
	char nom[50];
	char code[50];
	int fabrication;
	int peremption;
	float prix;
	int vendus;
	int stock;
}Medicament;

Medicament** creerTableau(int taille);
Medicament* creerMedicament(void);
void afficher(Medicament** tableau, int taille);

void tri_a_bulles_nom(Medicament** T, int taille);
void tri_a_bulles_optimise(Medicament** T, int taille);
void swap(Medicament* i, Medicament* j);

void dichotomie(Medicament** tableau, int taille, char nom[50]);

#endif
