#include <iostream>
#include <vector>
#include <cmath>

class Vec3D
{
public:
    int getLength();
    int x;
    int y;
    int z;
};

int Vec3D::getLength()
{
    return std::sqrt(x*x + y*y + z*z);
}

int main()
{
    Vec3D vec1;
    vec1.x = 10;
    vec1.y = 12;
    vec1.z = 25;

    int len = vec1.getLength();
    std::cout << "Length: " << len << std::endl;


    return 0;
}