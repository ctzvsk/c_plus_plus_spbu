#include <iostream>
using namespace std;
int main()
{
	int d, h, a, b = 0;
	cout << "type in height of the pole, amount of meters rising each day and amount of meters descending each day" << endl;
	cin >> h >> a >> b;
	if (b < a)
	{
		d = h / (a - b);
		cout << "The snail will rise to the top of the pole in " << d << " days" << endl;
	}
	else
	{
		cout << "The snail will never rise to the top of the pole" << endl;
	}
	return 0;
}
