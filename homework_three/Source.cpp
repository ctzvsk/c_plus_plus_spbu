#include <iostream>
#include "Vector3D.h"
using namespace std;

int main(void)
{
    Vector3D v1(1, 1, 2);
    Vector3D v2(3, 5, 8);
    double b = 10;

    Vector3D sum = v1.add(v2);
    Vector3D mult = v1.multiply(b);
    double scalar = v1.scalar_product(v2);
    Vector3D vector = v1.vector_product(v2);

    sum.Print();
    mult.Print();
    cout << scalar << endl;
    vector.Print();

    return EXIT_SUCCESS;
}
