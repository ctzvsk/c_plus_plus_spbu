#include <iostream>
using namespace std;

void parentheses(string str, int start_p)
{
    if (start_p < str.length() / 2)
    {
        cout << '(' << str[start_p];
        parentheses(str, start_p + 1);
    }
    else if ((str.length() % 2 == 1) and (start_p == str.length() / 2))
    {
        cout << '(' << str[start_p] << ')';
        parentheses(str, start_p + 1);
    }
    else if (start_p <= str.length() - 1)
    {
        cout << str[start_p] << ')';
        parentheses(str, start_p + 1);
    }
}

int main()
{
    string str_arg;
    cout << "type in a string" << endl;
    cin >> str_arg;
    parentheses(str_arg, 0);
    return EXIT_SUCCESS();
}
