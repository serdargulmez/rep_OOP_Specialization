#include "06_classExampleHeader.h"
#include <cmath>

int Vec3D::getLength()
{
    return std::sqrt(x*x + y*y + z*z);
}