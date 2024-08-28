#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std; 

int main(int argc, char** argv) {
    Stack stack; 
    stack.Push("One", 3);
    stack.Push("Two", 0);
    stack.Push("Three", 2);
    stack.Push("Four", 5);
    stack.Push("Five", 1);
    stack.Print();

    cout << "Popping\n";
    stack.Pop();
    cout << "Popping\n";
    stack.Pop();
    cout << "Popping\n";
    stack.Pop();
    cout << "Popping\n";
    stack.Pop();
    cout << "Popping\n";
    stack.Pop();
    cout << "Popping\n";
    stack.Pop();

    cout << "\n\nNew stack\n";

    stack.Push("Books", 100);
    stack.Push("Phones", 1);
    stack.Print();
    
    return 0;
}