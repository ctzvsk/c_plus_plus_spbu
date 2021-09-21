#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	int m = 0;
	cout << "type in two integer numbers" << endl;
	cin >> n >> m;
	cout << m % n % m + n % m % n + 1 << endl;
	return 0;
}
