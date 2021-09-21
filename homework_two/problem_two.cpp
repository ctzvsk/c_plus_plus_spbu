#include <iostream>
using namespace std;

int BinCo(int n, int k)
{
	int a = 0;

	if ((k == 0) or (n == k))
	{
		return 1;
	}
	else
	{
		a = BinCo(n - 1, k - 1) + BinCo(n - 1, k);
		return a;
	}
}
int main()
{
	int a = 0;
	int b = 0;
	cout << "type in n and k" << endl;
	cin >> a >> b;
	cout << BinCo(a, b) << endl;
	return 0;
}
