#include <iostream>
using namespace std;
int main()
{
	int h = 0, mm = 0, ss = 0, totals = 0;
	cout << "type in amount of seconds" << endl;
	cin >> totals;
	h = totals / 3600;
	mm = (totals - 3600 * h) / 60; 
	ss = (totals - 3600 * h) % 60;
	cout << h << ":";
	if (mm < 10)
	{
		cout << "0";
	}
	cout << mm;
	if (ss < 10)
	{
		cout << "0";
	}
	cout << ss << endl;
	return 0;
}
