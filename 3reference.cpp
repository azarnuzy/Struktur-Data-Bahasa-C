#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 5;
    cout << "address dari a: " << &a << endl;
    cout << "  nilai dari a: " << a << endl;

    int &b = a;

    cout << "  nilai dari b: " << b << endl;
    cout << "address dari b: " << &b <<endl <<endl;

    b = 10;
    cout << "  nilai dari b: " << b << endl;
    cout << "  nilai dari a: " << a << endl <<endl;
    
    a = 20;
    cout << "  nilai dari b: " << b << endl;
    cout << "  nilai dari a: " << a << endl <<endl;
    return 0;
}
