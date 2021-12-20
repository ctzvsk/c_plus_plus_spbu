#define VECTOR3D

struct Vector3D
{
    Vector3D(); /*default constr*/
    Vector3D(double x, double y, double z); /*parameterized constr*/
    Vector3D(const Vector3D& m); /*copy constr*/
    ~Vector3D(); /*destructor*/

    double x;
    double y;
    double z;

    Vector3D add(Vector3D m);
    Vector3D multiply(double scalar);
    double scalar_product(Vector3D m);
    Vector3D vector_product(Vector3D m);

    void Print();
};
