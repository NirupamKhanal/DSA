#include <cstdlib>
#include <iostream>
#include <string>

#include "myhash.h"

using namespace std; 

my_hash::my_hash() {
    for(int i = 0; i < tableSize; i++) {
        HashTable[i] = new item;
        HashTable[i] -> name = "empty";
        HashTable[i] -> drink = "empty";
        HashTable[i] -> next = NULL;
    }
}

void my_hash::AddItem(string name, string drink){
    int index = doHash(name);

    if(HashTable[index] -> name == "empty") {
        HashTable[index] -> name = name;
        HashTable[index] -> drink = drink;
    }
    else {
        item* Ptr = HashTable[index];
        item* n = new item;
        n -> name = name; 
        n -> drink = drink; 
        n -> next = NULL;
        while(Ptr -> next != NULL) {
            Ptr = Ptr -> next;
        }
        Ptr -> next = n;
    }
}

int my_hash::NumberOfItemsInIndex(int index) {
    int count = 0;

    if(HashTable[index] -> name == "empty") {
        return count;
    }
    else {
        count++;
        item* Ptr = HashTable[index]; 
        while(Ptr -> next != NULL) {
            count++;
            Ptr = Ptr -> next;
        }
    }
    return count;
}

void my_hash::PrintTable() {
    int number; 
    for(int i = 0; i < tableSize; i++) {
        number = NumberOfItemsInIndex(i);
        cout << "-----------------------\n";
        cout << "index = " << i << endl;
        cout << HashTable[i] -> name << endl;
        cout << HashTable[i] -> drink << endl;
        cout << "Number of items = " << number << endl;
        cout << "-----------------------\n";
    }
}

void my_hash::PrintItemsInIndex(int index) {
    item* Ptr = HashTable[index];
    if(Ptr -> name == "empty") {
        cout << "index = " << index << " is empty.\n";
    }
    else {
        cout << "index " << index << " contains the following items: \n"; 
        while(Ptr != NULL) {
            cout << "----------------\n";
            cout << Ptr -> name << endl;
            cout << Ptr -> drink << endl;
            Ptr = Ptr -> next;
        }
    }
}

int my_hash::doHash(string key) {
    int hash = 0; 
    int index;

    for(int i = 0; i < key.length(); i++) {
        hash = hash + (int) key[i]; //Give a more sophisticated hashing formula.
        cout << "hash = " << hash << endl;
    }

    index = hash % tableSize;

    return index;
}

void my_hash::FindDrink(string name) {
    int index = doHash(name);
    bool foundName = false; 
    string drink; 
    item* Ptr = HashTable[index];
    while(Ptr != NULL) {
        if(Ptr -> name == name) {
            foundName = true; 
            drink = Ptr -> drink;
        }
        Ptr = Ptr -> next;
    }
    if(foundName == true) {
        cout << name << "'s favorite drink is " << drink << endl;
    }
    else {
        cout << name << "'s information was not found.\n";
    }
}

void my_hash::RemoveItem(string name) {
    int index = doHash(name);

    item* delPtr; 
    item* P1; 
    item* P2; 

    if(HashTable[index] -> name == "empty" && HashTable[index] -> drink == "empty") {
        cout << name << " was not found in the table.";
    }
    else if(HashTable[index] -> name == name && HashTable[index] -> next == NULL) {
        HashTable[index] -> name = "empty";
        HashTable[index] -> drink = "empty";

        cout << name << "was removed from the table.\n";
    }
    else if(HashTable[index] -> name == name) {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index] -> next;
        delete delPtr;

        cout << name << "was removed from the table.\n";
    }
    else {
        P1 = HashTable[index] -> next;
        P2 = HashTable[index];

        while(P1 != NULL && P1 -> name != name) {
            P2 = P1; 
            P1 = P1 -> next;
        }
        if(P1 == NULL) {
            cout << name << "'s information was not found.\n";
        }
        else {
            delPtr = P1; 
            P1 = P1 -> next; 
            P2 -> next = P1;

            delete delPtr;

            cout << name << "was removed from the table.\n";
        }
    }
}