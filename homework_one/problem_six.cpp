#include <iostream>
using namespace std;
int main()
{
	int a = 0;
	int b = 0;
	cout << "type in two integer numbers" << endl;
	cin >> a >> b;
	cout << (a / b * a + b / a * b) / (a / b  + b / a) << endl;
	return 0;
}
