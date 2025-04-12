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
	struct Medicament* precedent;
	struct Medicament* suivant;
}Medicament;

Medicament** creerTableau(int taille);
Medicament* creerMedicament(void);

void ajouter(Medicament** medicaments, Medicament* nouveau);
void afficher(Medicament* tableau);

void tri_a_bulles_code(Medicament** medicament, int taille, int* swap);
Medicament* comparer(Medicament** med1, Medicament** med2, int* swapped);
void swap(Medicament* i, Medicament* j);

#endif
