#include <iostream>
#include <string>
using namespace std;
int main()
{
	string mm_str, ss_str = "";
	int h = 0, mm = 0, ss = 0, totals = 0;
	cout << "type in amount of seconds" << endl;
	cin >> totals;
	h = totals / 3600;
	mm = (totals - 3600 * h) / 60; 
	ss = (totals - 3600 * h) % 60;
	if (mm < 10)
	{
		mm_str = to_string(mm);
		mm_str.insert(0, "0");
	}
	else
	{
		mm_str = to_string(mm);
	}
	if (ss < 10)
	{
		ss_str = to_string(ss);
		ss_str.insert(0, "0");
	}
	else
	{
		ss_str = to_string(ss);
	}
	cout << h << ":" << mm_str << ":" << ss_str << endl;
	return 0;
}
