#include <iostream>
using namespace std;
int main()
{
	int d  = 0;
	int h = 0;
	int a = 0;
	int b = 0;
	cout << "type in height of the pole, amount of meters rising each day and amount of meters descending each day" << endl;
	cin >> h >> a >> b;
	d = (h - 2 * b + a - 1) / (a - b);
	cout << "The snail will rise to the top of the pole in " << d << " days" << endl;
	return 0;
}
