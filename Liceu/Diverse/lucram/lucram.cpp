// Exemplu de program care citeste doua numere dintr-un fisier si apoi le afiseaza

#include <iostream>
#include <fstream>

using namespace std;

/*int main() {
     int a, b;

     ifstream f_in("f.txt");

     f_in >> a >> b;

     cout << a << " " << b;

     return 0;
}*/

/*int main() 
{
     int x;

     ifstream f_in("f_in.txt");

     if (f_in == NULL) {
         cout << "Fisierul nu a fost gasit";
         return -1;
     }

     ofstream f_out("f_out.txt", fstream::app);

     while(f_in >> x) {
         f_out << x100 << " ";
     }

     f_in.close();
     f_out.close();

     return 0;
}*/


/*int main()
{
    int a, b;
    b = 0;
    ifstream f_in("f_in.txt");
    if (!f_in) 
    {
        cout << "Fisierul nu a fost gasit";
        return -1;
    }
    while (f_in >> a)
    {
    b = b + a;    
    }
    f_in.close();
    cout << b;
    return 0;
}*/

/*int main()
{
    int a, b, c, i;
    b = 0;
    ifstream f_in("f_in.txt");
    if (!f_in)
    {
        cout << "Fisierul nu a fost gasit";
        return -1;
    }
    f_in >> a;
    for(i = 0; i < a; i++)
    {
        f_in >> c;
        b = b + c;
    }
    f_in.close();
    cout << b;
    return 0;
}*/


/*int main()
{
    int a, b, c, i;
    ifstream f_in("f_in.txt");
    if (!f_in)
    {
        cout << "Fisierul nu a fost gasit";
        return -1;
    }
    while(f_in >> a && a != 0)
    {
        b = 0;
        for (i = 2; i <= a / 2; i++)
        {
            if (a % i == 0)
            {
                b = 1;
                break;
            }
        }
        if (b == 0)
            cout << a << ", ";
    }
    f_in.close();
    return 0;
}*/