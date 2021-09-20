#include <iostream>
#include <string>
using namespace std;

void shortening(string str)
{
	int a = str.length(), i=0;
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] == str[str.length() - i - 1])
		{
			str[i] = ' ';
			str[str.length() - i - 1] = ' ';
		}
	}
	for (int i = 0; i < str.length(); i++)
		if (str[i] != ' ')
		{
			cout << str[i];
		}
}

int main()
{
	string str_input;
	cout << "type in the string" << endl;
	cin >> str_input;
	shortening(str_input);
	return 0;
}