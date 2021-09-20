#include <iostream>
using namespace std;

void hanoi_towers(int q, int from, int to, int buf_peg)
{  
    if (q > 0)
    {
        hanoi_towers(q - 1, from, buf_peg, to);
        cout << "Move disk " << q << " from peg " << from << " to peg " << to << endl;
        hanoi_towers(q - 1, buf_peg, to, from);
    }
}

int main()
{
    int quantity;
    cout << "Amount of disks:" << endl;
    cin >> quantity;
    hanoi_towers(quantity, 1, 2, 3);
    return 0;
}