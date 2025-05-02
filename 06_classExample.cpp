#include <iostream>


class Vec3D{

public:
    int x;
    int y;
    int z;
};

Vec3D vec1;

void doSomething()
{
    vec1.x = 2;
    vec1.y = 3;
    vec1.z = 4;
}



int main()
{
    doSomething();

    return 0;
}