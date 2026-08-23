#include <iostream>
#include <fstream>
using namespace std;
// puctul a/d
// introduc 240107 si iese 0
/*int main()
{
	int a, b, c, x;
	cin >> a;
	c = 0;
	do
	{
		b = a;
		x = 0;
		do
		{
			if (b % 10 == c)
				x = 1;
			b = b / 10;
		} while (b == 0 || x == 1);
		cout << x << " ";
		c = c + 2;
	} while (c < 9);
	return 0;
}*/

/*int main()
{
	int a, b, c, x;
	cin >> a;
	c = 0;
	do
	{
		b = a;
		x = 0;
		while (b != 0 || x != 1)
		{
			if (b % 10 == c)
				x = 1;
			b = b / 10;
		}
		cout << x << " ";
		c = c + 2;
	} while (c < 9);
	return 0;
}*/


/*int main()
{
	int j, i, y, z;
	y = 0;
	z = 5;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			if (i < 6)
				cout << ">" << " ";
			else
			{
				if (j < z - y || j > z + y)
				{
					cout << "<" << " ";
				}
				else
					cout << ">" << " ";
			}
		}
		if (i >= 6)
			y = y + 1;
		cout << endl;
	}
	return 0;
}*/