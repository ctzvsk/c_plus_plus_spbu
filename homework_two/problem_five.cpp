#include <iostream>
#include <string>
using namespace std;

void shortening(string str, int start_p, int end_p)
{
	if (start_p < str.length())
	{
		if ((str[start_p] == str[end_p]) and (start_p != end_p))
		{
			shortening(str, start_p + 1, end_p - 1);
		}
		else if ((str[start_p] != str[end_p]) or (start_p = end_p))
		{
			cout << str[start_p];
				shortening(str, start_p + 1, end_p - 1);
		}
	}
}

int main()
{
	string str_input;
	cout << "type in the string" << endl;
	cin >> str_input;
	shortening(str_input, 0, str_input.length()-1);
	return 0;
}
