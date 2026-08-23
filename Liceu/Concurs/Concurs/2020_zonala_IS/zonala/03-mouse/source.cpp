#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("soarece.in");
ofstream fout;

int a[14][14], is, js, ib, jb, n, m;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

void citire()
{
    fin>>n>>m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            fin>>a[i][j];
    }
    fin >> is >> js >> ib >> jb;
}

void afis()
{
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            if (a[i][j] == 1 || a[i][j] == 0)
                fout << 0 << " ";
            else
                fout << a[i][j] - 1 << " ";
        fout<<endl;
    }
}

int valid (int x, int y)
{
    if (x>n || x<1 || y>m || y<1)
        return 0;
    return !a[x][y];
}

void bktr(int i, int j, int pas)
{
    for (int dir=0; dir<=3; dir++) {
        int l,c;
        l=i+dy[dir];
        c=j+dx[dir];
        if (valid (l,c)==1) {
            a[l][c]=pas;
            if(l==ib && c==jb) {
                afis();
            }
            else
                bktr(l,c,pas+1);
            a[l][c]=0;
        }
    }
}

int main()
{
    fout.open("soarece.out");
    citire();
    a[is][js]=1;
    bktr(is,js,2);
    fout.close();
    return 0;
}
