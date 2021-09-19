#include <iostream>
using namespace std;

void FibNum(int numb)
{
	int a = 1, b = 1, c, i = 0;

	if (numb == 0)
	{
		cout << '0' << endl;
	}
	else if ((numb == 1) or (numb == 2))
	{
		cout << '1' << endl;
	}
	else
	{
		for (i = 1; i <= numb-2; i++)
		{
			c = a + b;
			b = a;
			a = c;
		}
		cout << a << endl;
	}
}
int main()
{
	int d;
	cout << "type in the number of element of Fibonacci sequence" << endl;
	cin >> d;
	FibNum(d);
}
