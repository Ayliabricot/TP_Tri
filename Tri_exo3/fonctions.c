#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void tableauTrie(int* T1, int* T2, int* T3,int taille1, int taille2) {
	if (T1 == NULL || T2 == NULL || T3 == NULL || taille1<=0 || taille2<=0) {
		return;
	}
	int taille3 = 0;
	int i=0;
	int j = 0;
	
	for (i = 0; i < taille1; i++) {
		while (T2[j]<=T1[i]) {
			T3[taille3] = T2[j];
			j=j + 1;
			taille3++;
		}
		T3[taille3] = T1[i];
		taille3++;
	}
	if (j < taille2) {
		for (j; j < taille2;j++) {
			T3[taille3] = T2[j];
			taille3++;
		}
	}
}

void afficher(int* T, int taille) {
	if (T == NULL) {
		return;
	}
	for (int i = 0; i < taille; i++) {
		printf("%d ", T[i]);
	}
}