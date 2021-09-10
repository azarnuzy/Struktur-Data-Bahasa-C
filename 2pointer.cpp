#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 5;
    //pointer
    int *aPtr = &a;

    //int a mempunyai nilai dan address (alamat)
    cout << "nilai dari a: " << a << endl;
    cout << "alamat dari a: " << aPtr << endl;

    //mengambil data dari sebuah pointer, deferencing
    a = 10;
    cout << "mengambil nilai daari pointer aPtr: " << *aPtr << endl;
    return 0;
}
