#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/*
void quick(int* v, int st, int dr);

void main() {
	FILE* f;

	f = fopen("vec.txt", "r");

	int* v, i, n;

	if (!f)
		printf("Fisierul nu s-a dschis!");
	else {
		fscanf(f, "%d", &n);

		v = (int*)malloc(n * sizeof(int));
		for (i = 0; i < n; i++) {
			fscanf(f, "%d", &v[i]);
		}

		quick(v, 0, n - 1);

		for (i = 0; i < n; i++)
			printf("v[%d] = %d\n", i + 1, v[i]);

		free(v);
	}
}

void quick(int* v, int st, int dr) {
	int m, aux;

	if (st < dr) {
		m = (st + dr) / 2;
		aux = v[st];
		v[st] = v[m];
		v[m] = aux;

		int i = st, j = dr, d = 0;
		while (i < j) {
			if (v[i] > v[j]) {
				aux = v[i];
				v[j] = v[i];
				v[i] = aux;
				d = 1 - d;
			}

			i += d;
			j -= 1 - d;
		}

		quick(v, st, i - 1);
		quick(v, i + 1, dr);
	}
}
*/

int prob1(int* v, int st, int dr);
int prob2(int* v, int st, int dr);
int prob3(int* v, int st, int dr);

void main() {
	FILE* f;
	//f = fopen("prob1.txt", "r");
	//f = fopen("prob2.txt", "r");
	f = fopen("prob3.txt", "r");

	int* v, n, i;

	if (!f)
		printf("Fiseryl text nu s-a deschis");
	else {
		fscanf(f, "%d", &n);

		v = (int*)malloc(n * sizeof(int));
		for (i = 0; i < n; i++)
			fscanf(f, "%d", &v[i]);

		//printf("%d", prob1(v, 0, n - 1));
		//printf("%d", prob2(v, 0, n - 1));
		printf("%d", prob3(v, 0, n - 1));

		fclose(f);
	}
}


int prob1(int* v, int st, int dr) {
	int s;
	if (st == dr) {
		if (v[st] % 100 / 10 == 3)
			s = v[st];
		else
			s = 0;
	}
	else{
		s = prob1(v, st, (st + dr) / 2) + prob1(v, (st + dr) / 2 + 1, dr);
	}

	return s;
}

int prob2(int* v, int st, int dr) {
	int min = v[0], a, b;
	if (st == dr) {
		if (min > v[st])
			min = v[st];
	}
	else {
		a = prob2(v, st, (st + dr) / 2);
		b = prob2(v, (st + dr) / 2 + 1, dr);

		if (a < b)
			min = a;
		else
			min = b;
	}

	return min;
}

int prob3(int* v, int st, int dr) {
	int max = v[0], a , b;
	if (st == dr) {
		if (st % 2 == 0 && max < v[st])
			max = v[st];
	}
	else {
		a = prob3(v, st, (st + dr) / 2);
		b = prob3(v, (st + dr) / 2 + 1, dr);

		if (a > b)
			max = a;
		else
			max = b;
	}

	return max;
}