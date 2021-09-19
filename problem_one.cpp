#include <iostream>
using namespace std;
int main()
{
	int point = 0;
	int V, T;
	cout << "Type in speed and time: " << endl;
	cin >> V >> T;
	point = T * V % 109;
	cout << point << endl;
	return 0
}
