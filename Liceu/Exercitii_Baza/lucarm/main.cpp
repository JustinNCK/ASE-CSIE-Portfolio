#include <iostream>
using namespace std;

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
	for (i = 0; i < dim; i++)
	{
		a = 0;
		while (v[i] >= 0)
			a++;
		if (a > b)
			b = a;
	}
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
		if (nr == v[i])
			cout << v[i] << ", ";
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
int main()
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
			cout << [i];
	}
	return 0;
}