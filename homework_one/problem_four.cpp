#include <iostream>
using namespace std;
int main()
{
	int numb = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	cout << "type in a 4-digit number" << endl;
	cin >> numb;
	a = numb / 1000;
	b = (numb / 100) % 10;
	c = (numb / 10) % 10;
	d = numb % 10;
	cout << a - b + c - d << endl;
	return 0;
}
