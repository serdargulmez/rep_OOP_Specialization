#include <iostream>

using namespace std;

int main()
{
    bool spectra_01;
    unsigned short spectra_02;
    unsigned int spectra_03;


    spectra_01 = true;
    spectra_02 = 123;
    spectra_03 = 59;

    cout << "spectra_01: " << spectra_01 << endl;
    cout << "size of spectra_01: " << sizeof(spectra_01) << endl;

    cout << "spectra_02: " << spectra_02 << endl;
    cout << "size of spectra_02: " << sizeof(spectra_02) << endl;

    cout << "spectra_03: " << spectra_03 << endl;
    cout << "size of spectra_03: " << sizeof(spectra_03) << endl;
    
    return 0;
}