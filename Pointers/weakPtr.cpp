#include <iostream>
#include <memory>
#include <cstdlib>

using namespace std; 

struct B; 
struct C; 

struct A {
    shared_ptr<C> ptrC; 
    ~A() {cout << "A destroyed!\n";}
};

struct B {
    shared_ptr<A> ptrA; 
    ~B() {cout << "B destroyed!\n";}
}; 

struct C {
    weak_ptr<B> ptrB; 
    ~C() {cout << "C destroyed!\n";}
}; 

int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    shared_ptr<C> c = make_shared<C>();
    cin.get();
    a -> ptrC = c;
    cin.get(); 
    b -> ptrA = a; 
    cin.get();
    c -> ptrB = b;
    cin.get();
}