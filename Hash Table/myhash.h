#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef MY_HASH_H
#define MY_HASH_H

class my_hash{
    private: 
        static const int tableSize = 4;

        struct item{
            string name; 
            string drink; 
            item* next;
        }; 

        item* HashTable[tableSize];

    public: 
        my_hash();
        int doHash(string key);
        void AddItem(string name, string drink);
        int NumberOfItemsInIndex(int index);
        void PrintTable();
        void PrintItemsInIndex(int index);
        void FindDrink(string name);
        void RemoveItem(string name);
};

#endif