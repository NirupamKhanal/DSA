#include <iostream>
#include <cstdlib>

using namespace std; 

int main() {
    int box = 5; 
    int * ptr = &box;
    int ** dPtr = &ptr; 

    cout << "Value at box: " << box << endl; 
    cout << "Address of box: " << &box << endl;
    cout << "ptr points to address: " << ptr << endl;
    cout << "Value at the address ptr points to: " << *ptr << endl;
    cout << "Address of ptr: " << &ptr << endl;
    cout << "dPtr point to address: " << dPtr << endl;
    cout << "Value at the address dPtr points to: " << *dPtr << endl;
    cout << "The prt that dPtr points to, points to an int with the value: " << **dPtr << endl;
    cout << "Address of dPtr: " << &dPtr << endl;

    cout << "\n\nThing:         dPtr                ptr             Box\n";
    cout << "Values: [" << dPtr << "] -----> [" << ptr << "] -----> [" << box << "]\n";
    cout << "Addresses: " << &dPtr << "         " << &ptr << "          " << &box << endl;

    return 0;
}