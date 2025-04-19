// #include <iostream>
// #include <string>

// using namespace std;

// int main()
// {
//     bool spectra_01;
//     unsigned short spectra_02;
//     unsigned int spectra_03;
//     float spectra_04;
//     double spectra_05;
//     char spectra_06;
//     string spectra_07;

//     spectra_01 = true;
//     spectra_02 = 123;
//     spectra_03 = 59;
//     spectra_04 = 45.678;
//     spectra_05 = 0.0007;
//     spectra_06 = 'A';
//     spectra_07 = "Hello";

//     cout << "spectra_01: " << spectra_01 << endl;
//     cout << "size of spectra_01: " << sizeof(spectra_01) << endl;

//     cout << "-----------------------------------------------------------------" << endl;

//     cout << "spectra_02: " << spectra_02 << endl;
//     cout << "size of spectra_02: " << sizeof(spectra_02) << endl;

//     cout << "-----------------------------------------------------------------" << endl;

//     cout << "spectra_03: " << spectra_03 << endl;
//     cout << "size of spectra_03: " << sizeof(spectra_03) << endl;

//     cout << "-----------------------------------------------------------------" << endl;

//     cout << "spectra_04: " << spectra_04 << endl;
//     cout << "size of spectra_04: " << sizeof(spectra_04) << endl;

//     cout << "-----------------------------------------------------------------" << endl;

//     cout << "spectra_05: " << spectra_05 << endl;
//     cout << "size of spectra_05: " << sizeof(spectra_05) << endl;

//     cout << "-----------------------------------------------------------------" << endl;

//     cout << "spectra_06: " << spectra_06 << endl;
//     cout << "size of spectra_06: " << sizeof(spectra_06) << endl;

//     cout << "-----------------------------------------------------------------" << endl;

//     cout << "spectra_07: " << spectra_07 << endl;
//     cout << "size of spectra_07: " << sizeof(spectra_07) << endl;

//     cout << "-----------------------------------------------------------------" << endl;

//     return 0;
// }

/*

    g++ --std=c++11 temp.cpp -o temp

*/
// #include <iostream>
// using namespace std;

// int main()
// {
//     unsigned short i = 65537;
//     unsigned a{4};
//     signed long b{45};

//     cout << "The size of 'unsigned short' is: " << sizeof(unsigned short) << endl;
//     cout << "i contains: " << i << endl;
//     cout << "The size of 'unsigned' is: " << sizeof(unsigned) << endl;
//     cout << "The size of 'signed long' is: " << sizeof(signed long) << endl;

//     return 0;
// }

/*
    g++ -Wall --std=c++11 temp.cpp -o temp

*/

// #include <iostream>
// #include <string>
// using namespace std;

// enum class Colours{red, blue, white};

// int main()
// {
//     string s = "Hello";

//     // float f = 1.5; // it would be double if 'f' was not added to end of numbers!
//     float f = 1.5f; // 32 bits - 4 bytes

//     double d = 1.5; // it normal double 64 bits - 8 bytes

//     cout << "size of float: " << sizeof(float) << endl;
//     cout << "size of double: " << sizeof(double) << endl;

//     return 0;
// }

/*
    concepts of class

*/

#include <iostream>
#include<vector>
using namespace std;

class Vec3D
{
    private:
        int x;
        int y;
        int z;
};

Vec3D vec1;

int main()
{  

    vec1.x = 23;
    vec1.y = 12;
    vec1.z = 13;

    return 0;
}
