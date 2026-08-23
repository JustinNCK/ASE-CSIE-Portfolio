#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	unsigned int i;
	i = (freopen("asamblica.in", "rb", stdin), 0);

	// IMPORTANT: De aici in jos aveti voie sa modificati.
	char c;

	while (1) {
		c = getchar();
		if (i > 0)
			putchar(" \n"[i & 0x0F == 0 || c == EOF]);
		if (c == EOF) {
			break;
		}
		printf("%02hhX", c);
		i++;
	}
	return 0;
}
