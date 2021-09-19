#include <iostream>
using namespace std;
int main()
{
	int numb = 0;
	cout << "type in a 4-digit number" << endl;
	cin >> numb;
	if ((numb % 10 == numb / 1000) and ((numb / 100) % 10 == (numb / 10) % 10))
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "0" << endl;
	}
	return 0;
}
