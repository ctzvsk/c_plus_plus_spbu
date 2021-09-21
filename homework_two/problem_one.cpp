#include <iostream>
using namespace std;

 int FibNum(int numb)
{
	int a = 0;

	if (numb == 0)
	{
		return 0;
	}
	else if ((numb == 1) or (numb == 2))
	{
		return 1;
	}
	else
	{
		a = FibNum(numb-2) + FibNum(numb-1);
		return a;
	}
}
int main()
{
	int d = 0;
	cout << "type in the number of element of Fibonacci sequence" << endl;
	cin >> d;
	cout << FibNum(d) << endl;
}
