#include <iostream>
using namespace std;
int main()
{
	int n, m = 0;
	cout << "type in two integer numbers" << endl;
	cin >> n >> m;
	if ((n % m == 0) or (m % n == 0))
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "2" << endl;
	}
	return 0;
}
