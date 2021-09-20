#include <iostream>
using namespace std;

void parentheses(string str)
{
    if (str.length() % 2 == 1)
    {
        for (int i=0; i < str.length(); i++)
        {
            if (i < (float)str.length() / 2)
            {
                cout << "(" << str[i]; 
            }
            if (i > (float)str.length() / 2)
            {
                cout << str[i] << ")"; 
            }
            if ((float)i + 0.5 == (float)str.length() / 2)
            {
                cout << ")";
            }
        }
    }
    else
    {
        for (int i=0; i < str.length(); i++)
        {
            if (i < (float)str.length() / 2)
            { 
                cout << "(" << str[i];
            }
            if (i >= (float)str.length() / 2)
            {
                cout << str[i] << ")"; 
            }
        }
    }
}

int main()
{
    string str_arg;
    cout << "type in a string" << endl;
    cin >> str_arg;
    parentheses(str_arg);
}
