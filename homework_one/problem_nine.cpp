#include <iostream>
using namespace std;
int main()
{
	int ronumb;
	cout << "type in integer number" << endl;
	cin >> ronumb;
	while (ronumb > 1000)
	{
		ronumb -= 1000;
		cout << "M";
	}
	while (ronumb > 500)
	{
		ronumb -= 500;
		cout << "D";
	}
	while (ronumb > 100)
	{
		ronumb -= 100;
		cout << "C";
	}
	while (ronumb > 50)
	{
		ronumb -= 50;
		cout << "L";
	}
	while (ronumb > 10)
	{
		ronumb -= 10;
		cout << "X";
	}
	switch (ronumb)
	{
		case 1:
			cout << "I" << endl;
			break;
		case 2:
			cout << "II" << endl;
			break;
		case 3:
			cout << "III" << endl;
			break;
		case 4:
			cout << "IV" << endl;
			break;
		case 5:
			cout << "V" << endl;
			break;
		case 6:
			cout << "VI" << endl;
			break;
		case 7:
			cout << "VII" << endl;
			break;
		case 8:
			cout << "VIII" << endl;
			break;
		case 9:
			cout << "IX" << endl;
			break;
	}
	return 0;
}