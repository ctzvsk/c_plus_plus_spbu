#include <iostream>
using namespace std;
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int max, min, mid;
	cout << "type in lengths of 3 sides of triangle" << endl;
	cin >> a >> b >> c;
	if ((a >= b) and (a >= c))
	{
		max = a;
		if (b >= c)
		{
			mid = b;
			min = c;
		}
		else
		{
			mid = c;
			min = b;
		}
	}
	else if ((b >= c) and (b >= a))
	{
		max = b;
			if (a >= c)
			{
				mid = a;
				min = c;
			}
			else
			{
				mid = c;
				min = a;
			}
	}
	else
	{
		max = c;
		if (a >= b)
		{
			mid = a;
			min = b;
		}
		else
		{
			mid = b;
			min = a;
		}
	}
	if ((a + b > c) and (a + c > b) and (b + c > a))
	{
		if (min * min + mid * mid == max * max)
		{
			cout << "triangle is rectangular" << endl;
		}
		else if (min * min + mid * mid > max * max)
		{
			cout << "triangle is acute" << endl;
		}
		else
		{
			cout << "triangle is obtuse" << endl;
		}
	}
	else
	{
		cout << "these are not valid values" << endl;
	}
	return 0;
}
