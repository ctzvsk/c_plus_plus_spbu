#include <iostream>
#include "Vector3D.h"

Vector3D::Vector3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3D::Vector3D(double x, double y = 0, double z = 0)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::Vector3D(const Vector3D& m)
{
    this->x = m.x;
    this->y = m.y;
    this->z = m.z;
}

Vector3D::~Vector3D()
{

}

Vector3D Vector3D::add(Vector3D m)
{
    Vector3D result;

    result.x = x + m.x;
    result.y = y + m.y;
    result.z = z + m.z;

    return result;
}

Vector3D Vector3D::multiply(double scalar)
{
    Vector3D result;

    result.x = x * scalar;
    result.y = y * scalar;
    result.z = z * scalar;

    return result;
}

double Vector3D::scalar_product(Vector3D m)
{
    return m.x * x + m.y * y + m.z * z;
}

Vector3D Vector3D::vector_product(Vector3D m)
{
    Vector3D result;

    result.x = m.z * y - m.y * z;
    result.y = m.x * z - m.z * x;
    result.z = m.y * x - m.x * y;

    return result;
}

void Vector3D::Print()
{
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}
