#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

Stack::Stack() {
    stackPtr = NULL;
}

Stack::~Stack() {
    item* p1; 
    item* p2; 

    p1 = stackPtr;
    while(p1 != NULL) {
        p2 = p1;
        p1 = p1 -> prev;
        p2 -> prev = NULL;
        delete p2;
    }
}

void Stack::Push(string name, int value) {
    item* n = new item; 

    n -> name = name; 
    n -> value = value;

    if(stackPtr == NULL) {
        stackPtr = n;
        stackPtr -> prev = NULL;  
    }
    else {
        n -> prev = stackPtr;
        stackPtr = n;
    }
}

void Stack::ReadItem(item* r) {
    cout << "------------------------------\n";
    cout << "Name: " << r -> name << endl;
    cout << "Value: " << r -> value << endl;
    cout << "------------------------------\n"; 
}

void Stack::Pop() {
    if(stackPtr == NULL) {
        cout << "There is nothing in the stack.\n";
    }
    else {
        item* p = stackPtr;
        ReadItem(p);
        stackPtr = stackPtr -> prev;
        p -> prev = NULL;
        delete p;
    }
}

void Stack::Print() {
    item* p = stackPtr; 

    while(p != NULL) {
        ReadItem(p);
        p = p -> prev;
    }
}