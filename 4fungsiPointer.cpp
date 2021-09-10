#include <iostream>

using namespace std;

void fungsi(int *b) {
    cout << "address b: " << b << endl;
    cout << "  nilai dari b: " << *b << endl << endl; //dereferencing
}

void kuadrat(int *valPtr) {
    *valPtr = *valPtr * *valPtr;
}

int main(int argc, char const *argv[])
{
    int a = 5;
    cout << "address a: " << &a << endl;
    cout << "  nilai dari a: " << a << endl << endl;

    fungsi(&a); //fungsi dengan input pointer
    kuadrat(&a);

    cout << "  nilai dari a: " << a << endl << endl;
    return 0;
}
