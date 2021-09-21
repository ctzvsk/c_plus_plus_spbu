#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int h = 0;
	int mm = 0; 
	int ss = 0; 
	int totals = 0;
	cout << "type in amount of seconds" << endl;
	cin >> totals;
	h = totals / 3600;
	mm = (totals - 3600 * h) / 60;
	ss = (totals - 3600 * h) % 60;
	cout << h << ":";
	cout << setfill('0') << setw(2) << mm << ':';
	cout << setfill('0') << setw(2) << ss << endl;
	cout << mm;
	if (ss < 10)
	{
		cout << "0";
	}
	cout << ss << endl;
	return 0;
}
