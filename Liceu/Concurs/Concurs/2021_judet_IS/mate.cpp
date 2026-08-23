#include <fstream>
#include <sstream>
using namespace std;
/// Clasa memoreaza un nr complex
class complex
{
private:
    int r, i;   // r - partea reala, i - partea imaginara
public:
    complex();  // creeaza numarul imaginar nul
    complex(int pr, int pi); // pr - valoarea termenului real, pi - val. term. imaginar
    string afisare(); // pregateste un sir pentru a fi afisat
    int real();     // returneaza partea reala
    int imaginar(); // returneaza partea imaginara
    void set(int pr, int pi); // stabileste valoarea partii reale si a celei imaginare
};
// aici va fi scris codul tau

int main()
{
    ifstream fin("date.in");
    ofstream fout("date.out");
    int a, b, c, d;
    while(fin >> a >> b >> c >> d)
    {
        complex x(a,b), y(c,d), z;
        z = x + y;
        fout << z.afisare() <<"\n";
        z = x - y;
        fout << z.afisare() <<"\n";
        z = x * y;
        fout << z.afisare() <<"\n";
    }
    return 0;
}

