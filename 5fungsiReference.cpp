#include <iostream>
using namespace std;

void fungsi(int &b)
{
    cout << "address b " << &b << endl;
    cout << "  nilai b " << b << endl
         << endl;
}

void kuadrat(int &valRef)
{
    valRef = valRef * valRef;
}

int main(int argc, char const *argv[])
{
    int a = 5;
    cout << "address a " << &a << endl;
    cout << "  nilai a " << a << endl
         << endl;

    int &b = a;
    fungsi(a);
    kuadrat(a);

    cout << "address a " << &a << endl;
    cout << "  nilai a " << a << endl
         << endl;
    return 0;
}
