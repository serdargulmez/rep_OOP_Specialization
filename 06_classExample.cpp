#include <iostream>
#include <vector>
class Vec3D
{
public:
    int x;
    int y;
    int z;
};

int main()
{
    Vec3D vec1;
    vec1.x = 2;
    vec1.y = 3;
    vec1.z = 4;

    std::vector<Vec3D> coords;
    coords.push_back(vec1);
    coords[0].x = 5;

    std::cout << coords[0].x << std::endl;
    return 0;
}