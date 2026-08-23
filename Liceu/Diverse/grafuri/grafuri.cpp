#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cmath>

//BFS (in latime)

void graf(int** mat, int* adc, int* coada, int m);

int main() {
	FILE* f;
	
	f = fopen("graf.txt", "r");

	int** mat, * coada, * adc, m, i, j, a, b;

	if (!f)
		printf("fisierul nu s-a deschis");
	else {
		fscanf(f, "%d", &m);
		mat = (int**)malloc(m * sizeof(int*));

		for (i = 0; i < m; i++) {
			mat[i] = (int*)calloc(m, sizeof(int));
			mat[i][i] = 1;
		}

		while (!feof(f)) {
			fscanf(f, "%d %d", &a, &b);

			mat[a - 1][b - 1] = 1;
			mat[b - 1][a - 1] = 1;
		}

		fclose(f);

		coada = (int*)malloc(m * sizeof(int));
		adc = (int*)calloc(m, sizeof(int));

		graf(mat, adc, coada, m);

		free(coada);
		free(adc);
		for (i = 0; i < m; i++)
			free(mat[i]);
		free(mat);

	}
}


void graf(int** mat, int* adc, int* coada, int m) {
	int a, b, i, j, x;

	printf("Nodul de start: ");
	scanf("%d", &x);

	
	coada[0] = x;
	adc[x - 1] = 1;

	a = 0;
	b = 1;
	while(a <= b) {
		for (j = 0; j < m && a <= b; j++) {
			if (adc[j] == 0 && mat[coada[a]][j] != 0) {
				coada[b] = j;
				b++;
				adc[j] = 1;
			}
		}
		coada[a]++;
		printf("coada[%d] = %d\n", a, coada[a]);

		a++;
	}
}