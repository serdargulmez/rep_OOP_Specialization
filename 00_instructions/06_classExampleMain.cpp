#include <iostream>
#include <vector>
#include "06_classExampleHeader.h"

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