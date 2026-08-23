/* 
    Se da un fisier de intrare cu marci de masini (scrise in diferite moduri)
    Stocati in memorie (si afisati) fiecare marca, o singura data, intr-un mod standard.
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("test.in");

int find_index(char results[100][20], char s[], int numberElements);
char *standard_string(char s[]); // Functioneaza corect
void print(char results[100][20], int numberElements);

int main()
{
    char s[20], results[100][20];
    int numberElements = 0;

    while(fin.getline(s, 20)) {
        if (find_index(results, s, numberElements) == -1) {
            // Hint: Foloseste functia standard_string pentru a stoca formatul corect
            strcpy(results[numberElements++], standard_string(s));
        }
    }

    print(results, numberElements);
    fin.close();
}

int find_index(char results[100][20], char s[], int numberElements) {
    for (int i = 0; i < numberElements; ++i) {
        if (strcmp(standard_string(s), results[i]) == 0)
            return i;
    }

    return -1;
}

char *standard_string(char s[]) {
    for (int i = 0; i < strlen(s); ++i) {
        s[i] = tolower(s[i]);
    }

    s[0] = toupper(s[0]);

    return s;
}

void print(char results[100][20], int numberElements) {
    for (int i = 0; i < numberElements; ++i) {
        cout << results[i] << endl;
    }
}