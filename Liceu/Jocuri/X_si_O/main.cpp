#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

void joc(char p1[100], char p2[100]);
void tabela(int v[9]);
void nume(char p1[30], char p2[30]);
void p(char p0[30]);
void jocX(int v[9]);
void jocO(int v[9]);
int verf(int v[9], char p1[30], char p2[30]);
void smily(int v[9], char p1[100], char p2[100]);


//88 - X
//79 - O

int main()
{
    char p1[100], p2[100];

    nume(p1, p2);

    joc(p1, p2);
}

void joc(char p1[100], char p2[100])
{
    int v[9], i;

    for(i = 0; i < 9; i++)
        v[i] = i + 1;

    i = 0;
    while(i == 0){
        tabela(v);
        jocX(v);
        i = verf(v, p1, p2);

        if(i != 0)
            break;

        tabela(v);
        jocO(v);
        i = verf(v, p1, p2);
    }
}

void nume(char p1[100], char p2[100])
{
    cout << "(primul este Player 1 si are X)" << endl;
    cout << "(numele unui jucator poate avea maxim 20 de caractere)" << endl;

    cout << "Player 1: ";
    p(p1);

    cout << endl;

    cout << "Player 2: ";
    p(p2);
}


void p(char p0[100])
{
    cin.getline(p0, 100);
    if(strlen(p0) > 20){
        cout << endl << "Numele ales este prea lung!" << endl;
        p(p0);
    }
}

void jocX(int v[9])
{
    int x;
    cout << endl << "pozitie lui X: ";
    cin >> x;

    if(x < 1 || x > 9){
        cout << endl << "pozitia nu este valida" << endl;
        jocX(v);
    }

    if(x != v[x - 1]){
        cout << "pozitia este deja ocupata!";
        //cout << x << " " << v[x];
        jocX(v);
    }
    else
        v[x - 1] = 88;
}

void jocO(int v[9])
{
    int o;
    cout << "pozitie lui O: ";
    cin >> o;

    if(o < 1 || o > 9){
        cout << endl << "pozitia nu este valida" << endl;
        jocO(v);
    }

    if(o != v[o - 1]){
        cout << "pozitia este deja ocupata!";
        //cout << o << " " << v[o];
        jocX(v);
    }
    else
        v[o - 1] = 79;
}

int verf(int v[9], char p1[30], char p2[30])
{
    /*int j;
    cout << endl;
    for(j = 0; j < 9; j++)
        cout << v[j] << " ";
    cout << endl;*/

    if(v[0] == v[1] && v[1] == v[2]){
        if(v[0] == 88){
            cout << p1 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }
        else{
            cout << p2 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }
    }

    if(v[3] == v[4] && v[4] == v[5])
        if(v[3] == 88){
            cout << p1 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }
        else{
            cout << p2 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }

    if(v[6] == v[7] && v[7] == v[8])
        if(v[6] == 88){
            cout << p1 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }
        else{
            cout << p2 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }

    if(v[0] == v[3] && v[3] == v[6])
        if(v[0] == 88){
            cout << p1 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }
        else{
            cout << p2 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }

    if(v[1] == v[4] && v[4] == v[7])
        if(v[1] == 88){
            cout << p1 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }
        else{
            cout << p2 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }

    if(v[2] == v[5] && v[5] == v[8])
        if(v[2] == 88){
            cout << p1 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }
        else{
            cout << p2 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }

    if(v[0] == v[4] && v[4] == v[8])
        if(v[0] == 88){
            cout << p1 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }
        else{
            cout << p2 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }

    if(v[1] == v[4] && v[4] == v[6])
        if(v[1] == 88){
            cout << p1 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }
        else{
            cout << p2 << " A CASTIGAT!!!";
            smily(v, p1, p2);
            return 1;
        }
    return 0;
}

/*
1 2 3
4 5 6
7 8 9

1 4 7
2 5 8
3 6 9

1 5 9
3 5 7
*/

void tabela(int v[9])
{
    cout << endl << endl << endl << "       |       |       " << endl;

    cout << "   ";
    if(v[0] != 1){
        cout << char (v[0]);
    }
    else
        cout << v[0];
    cout <<"   |   ";

    if(v[1] != 2){
        cout << char (v[1]);
    }
    else
        cout << v[1];
    cout<< "   |   ";

    if(v[2] != 3){
        cout << char (v[2]);
    }
    else
        cout << v[2];

    cout<< "   " << endl;

    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;

    cout << "   ";
    if(v[3] != 4){
        cout << char (v[3]);
    }
    else
        cout << v[3];
    cout <<"   |   ";

    if(v[4] != 5){
        cout << char (v[4]);
    }
    else
        cout << v[4];
    cout<< "   |   ";

    if(v[5] != 6){
        cout << char (v[5]);
    }
    else
        cout << v[5];
    cout << endl;

    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;

    cout << "   ";
    if(v[6] != 7){
        cout << char (v[6]);
    }
    else
        cout << v[6];
    cout <<"   |   ";

    if(v[7] != 8){
        cout << char (v[7]);
    }
    else
        cout << v[7];

    cout<< "   |   ";
    if(v[8] != 9){
        cout << char (v[8]);
    }
    else
        cout << v[8];

    cout << endl;
    cout << "       |       |       " << endl;
}

void smily(int v[9], char p1[100], char p2[100])
{
    int i;

    tabela(v);

    cout << endl;
    cout << "  _______   " << endl;
    cout << " /       \\  " << endl;
    cout << "/   ^   ^ \\ " << endl;
    cout << "\\   \\__/  / " << endl;
    cout << " \\_______/  " << endl;

    cout << "Mai vreti sa jucati?" << endl;
    cout << "1)DA       2)NU" << endl;
    cin >> i;
    if(i == 1)
        joc(p1, p2);
    else
        return;
}
