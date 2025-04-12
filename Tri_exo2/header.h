#ifndef EXO2
#define EXO2

typedef struct {
	char nom[50];
	char prenom[50];
	char matricule[50];
	float moyenne;
}Etudiant;

Etudiant** creerTableau(int taille);
Etudiant* creerEtudiant(void);

void afficher(Etudiant** tableau, int taille);

int comp_moyenne(const void* a, const void* b);
void tri_insertion(Etudiant** tableau, int taille);

void libererMemoire(Etudiant** tableau, int taille);

#endif