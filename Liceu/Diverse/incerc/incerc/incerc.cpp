#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int nr_mat;
	char nume[30];
	char an;
	int grupa;
	char tip;
	struct {
		char zi, luna;
		int an;
	} data;
	struct {
		char ora, min;
	} intrare;
	struct {
		char ora, min;
	} iesire;
} stud;

void sortare(stud* studenti, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (studenti[i].an > studenti[j].an || (studenti[i].an == studenti[j].an && studenti[i].grupa > studenti[j].grupa)) {
				stud temp = studenti[i];
				studenti[i] = studenti[j];
				studenti[j] = temp;
			}
		}
	}
}

void genereazaLista(stud* studenti, int n, const char* numeFisierText) {
	FILE* fisierText = fopen(numeFisierText, "w");
	if (!fisierText) {
		printf("Eroare la deschiderea fisierului text!\n");
		return;
	}

	fprintf(fisierText, "Nr. matricol  Nume                         An  Grupa   Tip   Data         Ora intrare   Ora iesire\n");
	for (int i = 0; i < n; i++) {
		fprintf(fisierText, "%-12d  %-27s  %d   %-5d   %c     %02d/%02d/%04d   %02d:%02d         %02d:%02d       \n", studenti[i].nr_mat, studenti[i].nume, studenti[i].an, studenti[i].grupa, studenti[i].tip, studenti[i].data.zi, studenti[i].data.luna, studenti[i].data.an, studenti[i].intrare.ora, studenti[i].intrare.min, studenti[i].iesire.ora, studenti[i].iesire.min);
	}
	
	fclose(fisierText);
}

int main() {
	const char* numeFisierBin = "SecvStud.dat";
	const char* numeFisierText = "lista_studenti.txt";
	FILE* fisierBin = fopen(numeFisierBin, "rb");
	if (!fisierBin) {
		printf("Eroare la deschiderea fisierului binar!\n");
		return 1;
	}

	fseek(fisierBin, 0, SEEK_END);
	int n = ftell(fisierBin) / sizeof(stud);
	fseek(fisierBin, 0, SEEK_SET);

	stud* studenti = (stud*)malloc(n * sizeof(stud));
	if (!studenti) {
		printf("Eroare de memorie!\n");
		fclose(fisierBin);
		return 1;
	}

	fread(studenti, sizeof(stud), n, fisierBin);
	fclose(fisierBin);

	sortare(studenti, n);

	fisierBin = fopen(numeFisierBin, "wb");
	if (!fisierBin) {
		printf("Eroare la rescrierea fisierului binar!\n");
		free(studenti);
		return 1;
	}

	fwrite(studenti, sizeof(stud), n, fisierBin);
	fclose(fisierBin);

	genereazaLista(studenti, n, numeFisierText);

	free(studenti);

	printf("Program finalizat cu succes!\n");
	return 0;
}

/*
typedef struct {
	int nr_mat;
	char nume[30];
	char an;
	int grupa;
	char tip;
	struct {
		char zi, luna;
		int an;
	}data;
	struct{
		char ora, min;
	}intrare;
	struct {
		char ora, min;
	}iesire;
}stud;

void afisare(char const* BinNume);
void inserare(char const* BinNume);
void bin_txt(char const* BinNume, char const* TxtNume);
void sortare(char const* BinNume, char const* TxtNume);

int main() {
	//inserare("SecvStud.dat");
	//afisare("SecvStud.dat");
	//bin_txt("SecvStud.dat", "Studenti.txt");
	sortare("SecvStud.dat", "Studenti_sortati.txt");
}


void afisare(char const* BinNume) {
	stud s;

	FILE *f;

	f = fopen(BinNume, "rb");

	if (!f)
		printf("Fisieru binar nu s-a deschis");
	else {
		fread(&s, 1, sizeof(stud), f);
		while (!feof(f)) {
			printf("%d  %s %d %d %c  %d.%d.%d  %d:%d %d:%d", s.nr_mat, s.nume, s.an, s.grupa, s.tip, s.data.zi, s.data.luna, s.data.an, s.intrare.ora, s.intrare.min, s.iesire.ora, s.iesire.min);
			printf("\n \n");
			fread(&s, 1, sizeof(stud), f);
		}
	}

	fclose(f);
}

void inserare(char const* BinNume) {
	stud s;

	FILE* f;

	f = fopen(BinNume, "rb+");

	if (!f)
		printf("Fisieru bnar nu s-a deschis");
	else {
		fread(&s, 1, sizeof(stud), f);
		while (!feof(f)) {
			fread(&s, 1, sizeof(stud), f);
		}

		scanf("%d %s %d %d %c %d %d %d %d %d", &s.nr_mat, &s.nume, &s.an, &s.grupa, &s.tip, &s.data.zi, &s.data.luna, &s.data.an, &s.intrare.ora, &s.intrare.min);
		
		s.iesire.ora = -1;
		s.iesire.min = -1;

		fwrite(&s, sizeof(stud), 1, f);
	}

	fclose(f);
}

void bin_txt(char const* BinNume, char const* TxtNume) {
	stud s;
	FILE* f, * g;
	f = fopen(BinNume, "rb");
	g = fopen(TxtNume, "w+");

	if (!f)
		printf("Fisierul binar nu s-a decshis");
	else if (!g)
		printf("Fisierul text nu s-a deschis");
	else {
		fprintf(g, "Nr.  Nume%26s An Grupa Tip zi.luna.an min:ora min:ora\n", "");

		fread(&s, 1, sizeof(stud), f);
		while (!feof(f)) {
			fprintf(g, "%-4d %-30s %-2d %-5d %-3c %02d.%02d.%d %02d:%02d   %02d:%02d \n", s.nr_mat, s.nume, s.an, s.grupa, s.tip, s.data.zi, s.data.luna, s.data.an, s.intrare.ora, s.intrare.min, s.iesire.ora, s.iesire.min, "");

			fread(&s, 1, sizeof(stud), f);
		}
	}
	fclose(f);
	fclose(g);
}

void sortare(char const* BinNume, char const* TxtNume) {
	FILE* f, * g;
	
	f = fopen(BinNume, "rb");
	g = fopen(TxtNume, "w");

	stud s;
	int nr = 1, min, poz;

	if (!f)
		printf("Fiserul binar nu s-a deschis\n");
	else if (!g)
		printf("Fisierul text nu s-a deschis\n");
	else {
		fread(&s, sizeof(stud), 1, f);
		while (nr != 6) {
			min = 20000;
			while (!feof(f)) {
				if (s.an == nr) {
					if (min > s.grupa) {
						min = s.grupa;
						poz = ftell(f) - sizeof(stud);
					}
				}
				else
					fread(&s, sizeof(stud), 1, f);	
			}
			nr++;
		}
	}
}
*/
/*
typedef struct {
	char is;
	int nr_mat;
	char nume[25];
	int grupa;
	char an;
	struct absente{
		char c, s;
	}abs[15];
}stud;

void afisare(char const* BinNume);
void recuperare(char const* BinNume);
void afisare_txt(char const* BinNume, char const *Txtnume);

int main() {
	//afisare("Fis_relativ_abs.dat");
	recuperare("Fis_relativ_abs.dat");
	//afisare("Fis_relativ_abs.dat");
	afisare_txt("Fis_relativ_abs.dat", "Fis_relativ_abs.txt");
}

void recuperare(char const* BinNume) {
	FILE* f;
	
	f = fopen(BinNume, "rb+");

	stud s;
	int nr, val, sapt;
	char x[2];

	if (!f)
		printf("Fisierul binar nu s-a deschis");
	else {
		printf("Nr. matricol al studentului: ");
		scanf("%d", &nr);
		printf("Tipul absentei (C/S): ");
		scanf("%s", &x);
		fseek(f, nr * sizeof(stud), 0);
		fread(&s, sizeof(stud), 1, f);
		if (s.is == 0)
			printf("Studentul nu exista");
		else{
			fseek(f, nr * sizeof(stud), 0);
			printf("Saptaman: ");
			scanf("%d", &sapt);
			sapt--;
			printf("Noua valoare: ");
			scanf("%d", &val);
			if (x[0] == 'c') {
				s.abs[sapt].c = val;
				fwrite(&s, sizeof(stud), 1, f);
			}
			else if (x[0] == 's') {
				s.abs[sapt].s = val;
				fwrite(&s, sizeof(stud), 1, f);
			}
			else
				printf("Tipul absentei nu este corect");
		}
		fclose(f);
	}
}

void afisare_txt(char const* BinNume, char const* Txtnume) {
	FILE* f, *g;

	stud s;

	f = fopen(BinNume, "rb");
	g = fopen(Txtnume, "w+");

	if (!f)
		printf("Fiserul binar nu s-a deschis");
	else {
		fprintf(g, "Nr. matricol Nume si Prenume%10s Grupa An Absente(C/S)\n", "");
		fread(&s, sizeof(stud), 1, f);
		while (!feof(f)) {
			if (s.is == 1) {
				fprintf(g, "%-12d %-25s %-5d %-2d ", s.nr_mat, s.nume, s.grupa, s.an);
				for (int i = 0; i < 15; i++)
					fprintf(g, "%2d ", s.abs[i].c);

				fprintf(g, "\n");
				fprintf(g, "%48s", "");
				for (int i = 0; i < 15; i++)
					fprintf(g, "%2d ", s.abs[i].s);

				fprintf(g, "\n\n");
			}

			fread(&s, sizeof(stud), 1, f);
		}

		fclose(f);
	}

}

void afisare(char const* BinNume) {
	FILE *f;

	stud s;

	f = fopen(BinNume, "rb");

	if (!f)
		printf("Fiserul binar nu s-a deschis");
	else {
		printf("Nr. matricol Nume si Prenume%10s Grupa An Absente(C/S)\n", "");
		fread(&s, sizeof(stud), 1, f);
		while (!feof(f)) {
			if (s.is == 1) {
				printf("%-12d %-25s %-5d %-2d ", s.nr_mat, s.nume, s.grupa, s.an);
				for (int i = 0; i < 15; i++)
					printf("%2d ", s.abs[i].c);

					printf("\n");
					printf("%48s", "");
				for (int i = 0; i < 15; i++)
					printf("%2d ", s.abs[i].s);

				printf("\n\n");
			}

			fread(&s, sizeof(stud), 1, f);
		}

		fclose(f);
	}

}
*/
/*
typedef struct {
	int nr_mat;
	char nume[30];
	int grupa;
	char puncte_proba;
	char puncte_teme[10];
	char puncte_examen[60];
}stud;

void fis_bin(char const *numeBin);
void afis_txt(char const* numeBin, char const* numeTxt);

int main() {
	//fis_bin("fisBin.dat");
	afis_txt("fisBin.dat", "fisTxt.txt");
}

void fis_bin(char const* numeBin) {
	FILE* f;
	f = fopen(numeBin, "ab");

	stud s;
	int i, du = 1;

	if (!f)
		printf("Fiserul binar nu s-a deschis");
	else {
		fflush(stdin);
		while (du == 1) {
			printf("Nr. matricol: ");
			scanf("%d", &s.nr_mat);

			printf("Nume: ");
			scanf("%s", &s.nume);

			printf("Grupa: ");
			scanf("%d", &s.grupa);

			printf("Puncte proba practica: ");
			scanf("%d", &s.puncte_proba);
			
			for (i = 0; i < 10; i++) {
				printf("Puncte tema %d: ", i);
				scanf("%d", &s.puncte_teme[i]);
			}

			printf("Puncte examen: ");
			scanf("%d", &s.puncte_examen);

			fwrite(&s, sizeof(stud), 1, f);

			printf("Se mai introduc studenti?(1/0): ");
			scanf("%d", &du);
		}
		fclose(f);
	}
}

void afis_txt(char const* numeBin, char const* numeTxt) {
	FILE* f, * g;
	f = fopen(numeBin, "rb");
	g = fopen(numeTxt, "w+");

	stud s;
	int i;

	if (!f)
		printf("Fisierul binar nu s-a deschis");
	else if(!g)
		printf("Fisierul text nu s-a deschis");
	else {
		fprintf(g, "Nr. matricol  Nume si prenume%15s  Pucte proba practica  Puncte teme%9s Puncte examen\n", "");

		fread(&s, sizeof(stud), 1, f);
		while (!feof(f)) {
			fprintf(g, "%-12d  %-30s  %-20d  ", s.nr_mat, s.nume, s.puncte_proba);
			for (i = 0; i < 10; i++)
				fprintf(g, "%d ", s.puncte_teme[i]);

			fprintf(g, " %-13d\n", &s.puncte_examen);

			fread(&s, sizeof(stud), 1, f);
		}

		fclose(f);
		fclose(g);
	}
}
*/
/*
typedef struct {
	char is;
	int cod;
	char den[30];
	int pret;
	int cant[12];
}produs;

void fis_bin(char const* numeBin);

int main() {
	fis_bin("fisBin.dat");
}

void fis_bin(char const* numeBin) {
	FILE* f;
	
	f = fopen(numeBin, "wb+");

	produs p;

	if(!f)
		printf("Fisierul binar nu s-a deschis");
	else {
		fflush(stdin);
		printf("Introduceti cod produs: ");
		scanf("%s", &p.cod);
		printf("Introduceti denumire produs: ");
		scanf("%s", &p.den);
		printf("Introduceti pret produs: ");
		scanf("%d", &p.pret);
		for (int i = 0; i < 12; i++) {
			printf("Introduceti cantitate pentru luna %d: ", i + 1);
			scanf("%d", &p.cant[i]);
		}
		p.is = 1;

		fseek(f, p.cod * sizeof(produs), 0);

		fwrite(&p, sizeof(produs), 1, f);
		while (!feof(stdin)) {
			printf("Introduceti cod produs: ");
			scanf("%s", &p.cod);

			printf("Introduceti denumire produs: ");
			scanf("%s", &p.den);

			printf("Introduceti pret produs: ");
			scanf("%d", &p.pret);

			for (int i = 0; i < 12; i++) {
				printf("Introduceti cantitate pentru luna %d: ", i + 1);
				scanf("%d", &p.cant[i]);
			}
			p.is = 1;

			fseek(f, p.cod * sizeof(produs), 0);

			fwrite(&p, sizeof(produs), 1, f);
		}
	}
}
*/
/*
typedef struct {
	char denumire[20];
	float pret;
	int cant[12];
	char is;
} PRODUS;

int nrart(FILE* f, int l)
{
	long p;
	int n;
	p = ftell(f);
	fseek(f, 0, 2);
	n = ftell(f) / l;
	fseek(f, p, 0);
	return n;
}

int main()
{
	FILE* f;
	char nume[20];
	PRODUS p;
	int i, cod;


	f = fopen("Produse.dat", "wb+");
	//deschide pentru citire si scriere. daca fis exista, este suprascris, altfel este creat

	printf("\n Cod produs: ");
	scanf("%d", &cod);
	while (!feof(stdin))
	{
		if (cod >= nrart(f, sizeof(PRODUS)))
		{
			p.is = 0;
			fseek(f, 0, 2);
			for (i = nrart(f, sizeof(PRODUS));i <= cod;i++)
				fwrite(&p, sizeof(PRODUS), 1, f);
		}
		fseek(f, cod * sizeof(PRODUS), 0);
		fread(&p, sizeof(PRODUS), 1, f);

		if (p.is) printf("\nExista deja un produs cu acest cod");
		else
		{
			fseek(f, cod * sizeof(PRODUS), 0);
			printf("Denumire: ");
			fflush(stdin);
			scanf("%s", &p.denumire);

			printf("pret:");
			scanf("%f", &p.pret);

			for (i = 0;i < 12;i++)
			{
				printf("Cant %d: ", i + 1);
				scanf("%d", &p.cant[i]);
			}

			p.is = 1;
			fwrite(&p, sizeof(PRODUS), 1, f);
		}

		printf("\nCod nou: ");
		scanf("%d", &cod);
	}
	fclose(f);
}
*/