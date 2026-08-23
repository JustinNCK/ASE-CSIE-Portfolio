#include <iostream>
using namespace std;


//buble sort
/*int main()
{
	int v[50];
	int n, i, a, s;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "v[" << i << "] = ";
		cin >> v[i];
	}
	s = 1;
	while (s == 1)
	{
		s = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (v[i] > v[i + 1])   //buble sort-ul este crescatorul daca vreau sa fie descresactor schimb " > " cu " < "
			{
				a = v[i + 1];
				v[i + 1] = v[i];
				v[i] = a;
				s = 1;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
}*/


/*int main()
{
	int v[20];
	int dim;
	int i, n, a;
	cout << "dati numarul de elemente: ";
	cin >> dim;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	for (i = 0; i < dim; i++)
	{
		a = 0;
		for (n = 2; n <= v[i] / 2; n++)
		{
			if (v[i] % n == 0)
			{
				a = 1;
				break;
			}
		}
		if (a == 0)
			cout << v[i] << " ";
	}
	return 0;
}*/



/*int main()
{
	int v[20];
	int dim;
	int i;
	cout << "dati numarul de elemente: ";
	cin >> dim;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	for (i = dim - 1; i >= 0; i--)
		cout << v[i] << " ";
	return 0;
}*/



//problema 1
/*int main()
{
	int v[50];
	int dim, s, i;
	cout << "dati numarul de elemente: ";
	cin >> dim;
	s = 0;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
		s = s + v[i];
	}
	cout << s;
	return 0;
}*/



//problema 2
/*int main()
{
	int v[50];
	int dim, p, i;
	cout << "dati numarul de elemente: ";
	cin >> dim;
	p = 1;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
		p = p * v[i];
	}
	cout << p;
	return 0;
}*/



//problema 3
/*int main()
{
	int v[50];
	int dim, i, a;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	a = v[0];
	for (i = 1; i < dim; i++)
	{
		if (a < v[i])
			a = v[i];
	}
	cout << a;
	return 0;
}*/



//problema 4
/*int main()
{
	int v[50];
	int dim, i, a;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	a = v[0];
	for (i = 1; i < dim; i++)
	{
		if (a > v[i])
			a = v[i];
	}
	cout << a;
	return 0;
}*/



//problema 5
/*int main()
{
	int v[50];
	int dim, i, a;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	a = 0;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
		if (v[i] >= 0)
			a++;
	}
	cout << a;
	return 0;
}*/



//problema 6
/*int main()
{
	int v[50];
	int dim, i, p;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	p = 1;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
		if (v[i] % 2 == 1)
			p = p * v[i];
	}
	cout << p;
	return 0;
}*/



//problema 7
/*int main()
{
	int v[50];
	int dim, i, a, nr;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	nr = 0;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	a = v[0];
	for (i = 1; i < dim; i++)
	{
		if (a < v[i])
			a = v[i];
	}
	for (i = 0; i < dim; i++)
	{
		if (v[i] == a)
			nr++;
	}
	cout << nr;
	return 0;
}*/



//problema 8
/*int main()
{
	int v[50];
	int dim, i;
	float s, ma;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	s = 0;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
		s = s + v[i];
	}
	ma = s / dim;
	cout << ma;
	return 0;
}*/



//problema 9
/*int main()
{
	int v[50];
	int dim, i;
	float nr, s, ma;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	s = 0;
	nr = 0;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
		if(v[i] >= 0)
		{
			s = s + v[i];
			nr++;
		}
	}
	ma = s / nr;
	cout << ma;
	return 0;
}*/



//problema 10
/*int main()
{
	int v[50];
	int dim, i, a, b;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	b = 0;
	a = 0;
	for (i = 0; i < dim; i++)
	{
		if (v[i] >= 0)
		{
			a++;
		}
		else
		{
			if (a > b)
				b = a;
			a = 0;
		}
	}
	if (a > b)
		b = a;
	cout << b;
	return 0;
}*/



//problrma 13
/*int main()
{
	int v[50];
	int dim, i, a, nr;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	for (i = 0; i < dim; i++)
	{
		a = 0;
		nr = v[i];
		while (nr != 0)
		{
			a = a * 10 + nr % 10;
			nr = nr / 10;
		}
		if (a == v[i])
			cout << a << ", ";
	}
	return 0;
}*/



//problema 14
/*int main()
{
	int v[50];
	int dim, i, a, nr, s;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	s = 0;
	for (i = 0; i < dim; i++)
	{
		a = 0;
		nr = v[i];
		while (nr != 0)
		{
			a = a * 10 + nr % 10;
			nr = nr / 10;
		}
		if (a == v[i])
			s++;
	}
	cout << s;
	return 0;
}*/



//problema 15
/*int main()
{
	int v[50];
	int dim, i, a, nr;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	for (i = 0; i < dim; i++)
	{
		nr = 0;
		for (a = 1; a < v[i]; a++)
		{
			if (v[i] % a == 0)
				nr = nr + a;
		}
		if (nr == v[i])
			cout << v[i] << ", ";
	}
	return 0;
}*/



//problema 16
/*int main()
{
	int v[50];
	int dim, i, a, b, c;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	c = -1;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	for (i = 0; i < dim; i++)
	{
		b = 0;
		for (a = 2; a < v[i] / 2; a++)
		{
			if (v[i] % a == 0)
			{
				b = 1;
				break;
			}
		}
		if (b == 0)
			if (c == -1)
			{
				cout << v[i];
				c = 0;
			}
			else
				cout << ", " << v[i];
	}
	return 0;
}*/



//problema 17
/*int main()
{
	int v[50];
	int dim, i, a, b, nr, nr2, uc, c;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	c = 0;
	for (i = 0; i < dim; i++)
	{
		b = 0;
		for (a = 2; a < v[i] / 2; a++)
		{
			if (v[i] % a == 0)
			{
				b = 1;
				break;
			}
		}
		if (b == 0)
		{
			nr = v[i];
			nr2 = 0;
			while (nr != 0)
			{
				uc = nr % 10;
				if (uc > nr2)
					nr2 = uc;
				nr = nr / 10;
			}
			c = c * 10 + nr2;
		}
	}
	cout << c;
	return 0;
}*/



//problema 18
/*int main()
{
	int v[50];
	int dim, i, nr, rs, cm;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	cm = 0;
	for (i = 0; i < dim; i++)
	{
		nr = v[i];
		rs = 0;
		while (nr != 0)
		{
			rs = rs * 10 + nr % 10;
			nr = nr / 10;
		}
		if (rs > cm)
			cm = rs;
	}
	cout << cm;
	return 0;
}*/



//problema 19
/*int main()
{
	int v[50];
	int dim, i, nr, cc, a;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	a = -1;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	for (i = 0; i < dim; i++)
	{
		nr = v[i];
		cc = 10;
		while (cc >= 10)
		{
			cc = 0;
			while (nr != 0)
			{
				cc = cc + nr % 10;
				nr = nr / 10;
			}
			nr = cc;
		}
		if (a == -1)
		{
			cout << cc;
			a = 0;
		}
		else
			cout << ", " << cc;
	}
	return 0;
}*/



//problema 20
/*int main()
{
	int v[50];
	int dim, i, nr, cc, a, m;
	cout << "dati numarul de elmente: ";
	cin >> dim;
	a = -1;
	m = 10;
	for (i = 0; i < dim; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}
	for (i = 0; i < dim; i++)
	{
		nr = v[i];
		cc = 10;
		while (cc >= 10)
		{
			cc = 0;
			while (nr != 0)
			{
				cc = cc + nr % 10;
				nr = nr / 10;
			}
			nr = cc;
		}
		if (cc < m)
			m = cc;
	}
	cout << m;
	return 0;
}*/



//problema 40
/*int main()
{
	int v[100];
	int dim, i, s;
	dim = 0;
	s = 0;
	do
	{
		cout << "v[" << dim << "]=";
		cin >> v[dim];
		dim++;
	} while (v[dim-1] != 0);
	for (i = 0; i < dim; i++)
	{
		s = s + v[i];
	}
	cout << s;
	return 0;
}*/



//vector de frecventa
//problema 73
/*int main()
{
	int v[10] = { 0 };
	int n, cifra, i;
	cin >> n;
	while (n != 0)
	{
		cifra = n % 10;
		v[cifra]++;
		n /= 10;
	}
	for (i = 0; i <= 9; i++)
	{
		if (v[i] > 1)
		{
			cout << "Numarul nu are toate cifrele distincte";
			return 0;
		}
	}
	cout << "Numarul are toate cifrele distincte";
	return 0;
}*/