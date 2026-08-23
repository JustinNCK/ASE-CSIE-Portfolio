#include <cstdio>

using namespace std;

const int BUFSIZE = 160;

char buf[BUFSIZE];
int pbeg, len;
FILE* fin = stdin;
FILE* fout = stdout;

int f()
{
	static int state = 0;
	int ch;
	int i;
	int lastspc;

	switch (state) {
	case 0: while (1) {
// AVETI VOIE SA MODIFICATI DE AICI
		pbeg = len = 0;
	case 1:		// NU AVETI VOIE SA STERGETI
		state = 1;
		if (len == BUFSIZE) {
			state = 2;
			break;
		}
		ch = fgetc(fin);
		if (ch == EOF || ch == '\n') {
			state = 2;
		} else {
			len++;
			buf[(pbeg + len) % BUFSIZE] = (char)ch;
		}
		break;
	case 2:		// NU AVETI VOIE SA STERGETI
		if (len != BUFSIZE) {
			state = 1;
			break;
		}
	case 4:		// NU AVETI VOIE SA STERGETI
		if (len < 81) {
			lastspc = len;
			len++;
		} else {
			lastspc = -1;
			for (i = 0; i < 81; i++) {
				ch = buf[(pbeg + i) % BUFSIZE];
				if (ch == ' ')
					lastspc = i;
			}
		}
		buf[(pbeg + lastspc) % BUFSIZE] = '\n';
		for (i = 0; i < lastspc + 1; i++) {
			ch = buf[pbeg];
			pbeg = (pbeg + 1) % BUFSIZE;
			len--;
			fputc(ch, fout);
		}
		if (state == 4 && len == 0)
			state = 3;
	case 3:		// NU AVETI VOIE SA STERGETI
		break;
	}}
	return state;
// AVETI VOIE SA MODIFICATI PANA AICI
}

int main()
{
	while (!f())
		;

	return 0;
}
