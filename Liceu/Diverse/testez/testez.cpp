#include <iostream>
using namespace std;


//test 1
/*int main()
{
	char n, m, c;
	cin >> n;
	m = 10;
	if (n == 0)
		m = 0;
	else
	{
		do
		{
			c = n % 10;
			n = n / 10;
			if (c <= m)
				m = c;
			else
				m = -1;
		} while (n == 0);
	}
	cout << m;
	return 0;
}*/


//test 2
/*int main()
{
	int n, s, c1, c2;
	cin >> n;
	s = 1;
	c1 = n % 10;
	n = n / 10;
	c2 = n % 10;
	if (c1 == c2)
		s = 0;
	else
	{
		if (c1 < c2)
			s = -1;
	}
	while ((c1 - c2) * s < 0 && n > 9)
	{
		c1 = n % 10;
		n = n / 10;
		c2 = n % 10;
	}
	cout << s << " " << n;
	return 0;
}*/



/*int main()
{
	int n, nr;
	cin >> n;
	nr = 0;
	while (n > 0)
	{
		nr = nr * 10 + n % 10;
		n = n / 10;
	}
	cout << nr;
	return 0;
}*/


/*int main()
{
	int n, x;
	cin >> n;
	x = 0;
	while (n > 0)
	{
		n = n / 10;
		x++;
	}
	cout << x;
	return 0;
}*/


/*int main()
{
	unsigned int n, u, x;
	cin >> n;
	x = 0;
	while(n > 0)
	{
		u = n % 10;
		n = n / 10;
		if (u % 2 == 0)
			x++;
	}
	cout << x;
	return 0;
}*/


///problema 34
/*int main()
{
	int a, ca, b, cb, c, d;
	cin >> a >> b;
	cout << "cifre comune: ";
	while (a > 0)
	{
		ca = a % 10;
		cb = b;
		while (cb > 0)
		{
			c = cb % 10;
			if (c == ca)
				cout << c << ", ";
			cb = cb / 10;
		}
		a = a / 10;
	}
	return 0;
}*/


///problema 35
/*int main()
{
	int n, i, nr;
	cin >> n;
	nr = 1;
	for (i = 1; i <=
		n; i++)
		nr = nr * i;
	cout << nr;
	return 0;
}*/


///problema 36
/*int main()
{
	int n, i, nr;
	cin >> n;
	nr = 1;
	for (i = 0; i < n; i++)
		nr = nr * 2;
	cout << nr;
	return 0;
}*/


///problema 37
/*int main()
{
	int n, cn1, cn2, a, b, c;
	cin >> n;
	cn1 = n;
	while (cn1 > 0)
	{
		a = cn1 % 10;
		cn2 = n;
		c = 0;
		while (cn2 > 0)
		{
			b = cn2 % 10;
			if (a == b)
				c = c + 1;
			if (c >= 2)
				break;
			cn2 = cn2 / 10;
		}
		cn1 = cn1 / 10;
		if (c == 1)
			c = 1;
		else
			break;
	}
	if (c == 1)
		cout << n << " are cifre distincte";
	else
		cout << n << " nu are cifre distncte";
}*/


///problema 38
/*int main()
{
	int x, y, a, b, c, d;
	for (x = 100; x <= 999; x = x+1)
	{
		d = x;
		y = x;
		while (x > 0)
		{
			a = x % 10;
			c = 0;
			while (y > 0)
			{
				b = y % 10;
				if (a == b)
					c = c + 1;
				if (c >= 2)
					break;
				y = y / 10;
			}
			x = x / 10;
			if (c == 1)
				c = 1;
			else
				break;
		}
		if (c == 1)
			cout << d << ", ";
	}
}*/



///problema 39
/*int main()
{
	int n, a;
	a = 0;
	cin >> n;
	while (n != 0)
	{
		cin >> n;
		a++;
	}
	cout << a;
	return 0;
}*/



///problema 40
/*int main()
{
	int n, a;
	a = 0;
	cin >> n;
	a = a + n;
	while (n != 0)
	{
		cin >> n;
		a = a + n;
	}
	cout << a;
	return 0;
}*/



///problema 41
/*int main()
{
	int n, a;
	a = 1;
	cin >> n;
	a = a * n;
	while (n != 0)
	{
		cin >> n;
		a = a * n;
	}
	cout << a;
	return 0;
}*/



///problema 42
/*int main()
{
	int n, a;
	cin >> a;
	while (n != 0)
	{
		cin >> n;
		if (n > a)
			a = n;
	}
	cout << a;
	return 0;
}*/



///problema 43
/*int main()
{
	int n, a;
	cin >> a;
	n = a;
	while (n != 0)
	{
		cin >> n;
		if (n == 0)
			break;
		if (n < a)
			a = n;
	}
	cout << a;
	return 0;
}*/


///problema 44
/*int main()
{
	int n, a, cn;
	cn = 0;
	cin >> n;
	a = n;
	do
	{
		cin >> n;
		if (n == 0)
			break;
		else
		{
			if (n < a)
				a = n;
		}
	} while (n != 0);
	while (a > 0)
	{
		cn = cn * 10 + a % 10;
		a = a / 10;
	}
	cout << cn;
	return 0;
}*/


///problema 46
/*int main()
{
	int n, a, b, cn;
	cin >> cn;
	n = cn;
	do
	{
		a = 0;
		for (b = 2; b <= n / 2; b++)
		{
			if (n % b == 0)
			{
				a = 1;
				break;
			}
		}
		if (a == 0)
			cout << n << ", ";
		cin >> n;
	}while (n != 0);
	return 0;
}*/


///problema 47
/*int main()
{
	int x, b;
	cin >> x >> b;
	while (b != 0)
	{
		if (b <= x)
			cout << b << ", ";
		cin >> b;
	}
	return 0;
}*/



///problema 48
/*int main()
{
	int a, b, c;
	float ma, d, e;
	cin >> a >> b >> c;
	e = 0;
	d = 0;
	if (a > b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	while (c != 0)
	{
		if (c == 0)
			break;
		if (c >= a && c <= b)
		{
			d = d + c;
			e++;
		}
		cin >> c;
	}
	if (e > 0)
	{
		ma = d / e;
		cout << ma;
	}
	else
		cout << "nu sunt numsere in interval";
	return 0;
}*/


///problema 49
/*int main()
{
	int a, b, c, d;
	cin >> a;
	while (a != 0)
	{
		if (a == 0)
			break;
		if (a % 2 == 0)
			cout << a - 2 << ", ";
		else
			cout << a - 1 << ", ";
		cin >> a;
	}
	return 0;
}*/



///problema 50
/*int main()
{
	int a, ca, b, c;
	cin >> a;
	while (a != 0)
	{
		if (a == 0)
			break;
		c = 0;
		ca = a;
		while (a > 0)
		{
			b = a % 10;
			if (b % 2 == 1)
				c = 1;
			a = a / 10;
		}
		if (c == 0)
			cout << ca << ", ";
		cin >> a;
	}
	return 0;
}*/


///problema 51
/*int main() {
	int a, b, c, n = -1;

	while (n != 0) {
		cin >> n;
		if (n == 0) {
			break;
		}

		a = 0;
		b = 1;
		do {
			c = a + b;
			if (c == n) {
				cout << c << " ";
			}
			a = b;
			b = c;
		} while (c < n);
	}
	return 0;
}*/



///problema 52
/*int main()
{
	int a, c;
	cin >> a;
	while (a != 0)
	{
		c = a % 10;
		cout << c;
		a = a / 10;
	}
	return 0;
}*/



///problema 53
/*int main()
{
	int a;
	cin >> a;
	while (a > 10)
	{
		a = a / 10;
	}
	cout << a;
	return 0;
}*/



///problema 54
/*int main()
{
	int a, c;
	cin >> a;
	c = 0;
	while (a != 0)
	{
		d = a % 10;
		c = c + d;
		a = a / 10;
	}
	cout << c;
	return 0;
}*/



///problema 55
/*int main()
{
	int a, c;
	cin >> a;
	c = 1;
	while (a != 0)
	{
		d = a % 10;
		c = c * d;
		a = a / 10;
	}
	cout << c;
	return 0;
}*/



///problema 56
/*int main()
{
	int a, c, d;
	cin >> a;
	d = 0;
	while (a != 0)
	{
		c = a % 10;
		if (c > d)
			d = c;
		a = a / 10;
	}
	cout << d;
	return 0;
}*/




///problema 57
/*int main()
{
	int a, c, d;
	cin >> a;
	d = 10;
	while (a != 0)
	{
		c = a % 10;
		if (c < d)
			d = c;
		a = a / 10;
	}
	cout << d;
	return 0;
}*/



///problema 58
/*int main()
{
	int a, c;
	cin >> a;
	c = 0;
	while (a != 0)
	{
		c = c + 1;
		a = a / 10;
	}
	cout << c;
	return 0;
}*/


///problema 59
/*int main()
{
	int a, c;
	cin >> a;
	while (a != 0)
	{
		c = a % 10;
		if (c % 2 == 0)
			cout << c;
		a = a / 10;
	}
	return 0;
}*/



///problema 60
/*int main()
{
	int a, c;
	float b, d, e;
	cin >> a;
	d = 0;
	b = 0;
	while (a != 0)
	{
		c = a % 10;
		d = d + c;
		b = b + 1;
		a = a / 10;
	}
	e = d / b;
	cout << e;
	return 0;
}*/