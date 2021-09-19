#include <iostream>
using namespace std;
int main()
{
	int a = 1, b = 1, c, d, i = 0;
	cout << "type in the number of element of Fibonacci sequence" << endl;
	cin >> d;
	if (d == 0)
	{
		cout << '0' << endl;
	}
	else if ((d == 1) or (d == 2))
	{
		cout << '1' << endl;
	}
	else
	{
		for (i = 1; i <= d-2; i++)
		{
			c = a + b;
			b = a;
			a = c;
		}
		cout << a << endl;
	}
	return 0;
}