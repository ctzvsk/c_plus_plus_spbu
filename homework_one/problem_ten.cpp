#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	int d = 0;
	cout << "type in three integers" << endl;
	cin >> a >> b >> c;
	while (!((a >= b) and (b >= c) and (a >= c)))
	{
		if (a < b)
		{
			d = b;
			b = a;
			a = d;
		}
		if (b < c)
		{
			d = c;
			c = b;
			b = d;
		}
		if (a < c)
		{
			d = c;
			c = a;
			a = d;
		}
	}
	cout << a << ">=" << b << ">=" << c << endl;
	return 0;
}