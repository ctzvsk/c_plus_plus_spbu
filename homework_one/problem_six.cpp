#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cout << "type in two integer numbers" << endl;
	cin >> a >> b;
	cout << (a / b * a + b / a * b) / (a / b  + b / a) << endl;
	return 0;
}
