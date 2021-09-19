#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	int odd = 0, even = 0;
	cout << "type in three integers" << endl;
	cin >> a >> b >> c;
	if (a % 2 == 0)
	{
		even += 1;
	}
	else
	{
		odd += 1;
	}
	if (b % 2 == 0)
	{
		even += 1;
	}
	else
	{
		odd += 1;
	}
	if (c % 2 == 0)
	{
		even += 1;
	}
	else
	{
		odd += 1;
	}
	if ((odd > 0) and (even > 0))
	{
		cout << "there is at least one even and one odd integers" << endl;
	}
	else
	{
		cout << "there isn't at least one even and one odd integers" << endl;
	}
	return 0;
}
