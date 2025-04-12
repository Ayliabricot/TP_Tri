#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {

	int T1[] = {2,8,16,32,36};
	int T2[] = {1,10,20,37};

	int taille1 = sizeof(T1) / sizeof(T1[0]);
	int taille2 = sizeof(T2) / sizeof(T2[0]);
	int taille3 = taille1 + taille2;

	int* T3 = malloc((taille1 + taille2) * sizeof(int));
	tableauTrie(T1, T2, T3, taille1, taille2);

	for (int i = 0; i < 8; i++) {
		printf("%d ", T3[i]);
	}

	free(T3);
	T3 = NULL;

	return 0;
}