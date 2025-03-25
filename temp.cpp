#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool spectra_01;
    unsigned short spectra_02;
    unsigned int spectra_03;
    float spectra_04;
    double spectra_05;
    char spectra_06;
    string spectra_07;

    spectra_01 = true;
    spectra_02 = 123;
    spectra_03 = 59;
    spectra_04 = 45.678;
    spectra_05 = 0.0007;
    spectra_06 = 'A';
    spectra_07 = "Hello";

    cout << "spectra_01: " << spectra_01 << endl;
    cout << "size of spectra_01: " << sizeof(spectra_01) << endl;

    cout << "-----------------------------------------------------------------" << endl;

    cout << "spectra_02: " << spectra_02 << endl;
    cout << "size of spectra_02: " << sizeof(spectra_02) << endl;

    cout << "-----------------------------------------------------------------" << endl;

    cout << "spectra_03: " << spectra_03 << endl;
    cout << "size of spectra_03: " << sizeof(spectra_03) << endl;

    cout << "-----------------------------------------------------------------" << endl;
    
    cout << "spectra_04: " << spectra_04 << endl;
    cout << "size of spectra_04: " << sizeof(spectra_04) << endl;

    cout << "-----------------------------------------------------------------" << endl;

    cout << "spectra_05: " << spectra_05 << endl;
    cout << "size of spectra_05: " << sizeof(spectra_05) << endl;

    cout << "-----------------------------------------------------------------" << endl;

    cout << "spectra_06: " << spectra_06 << endl;
    cout << "size of spectra_06: " << sizeof(spectra_06) << endl;

    cout << "-----------------------------------------------------------------" << endl;

    cout << "spectra_07: " << spectra_07 << endl;
    cout << "size of spectra_07: " << sizeof(spectra_07) << endl;

    cout << "-----------------------------------------------------------------" << endl;

    
    return 0;
}