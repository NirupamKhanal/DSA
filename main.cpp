#include <cstdlib>
#include <iostream>
#include <string>

#include "myhash.h"

using namespace std; 

int main() {
    
    my_hash H1; 
    string name = "";

    H1.AddItem("Niv", "water");
    H1.PrintTable();
    H1.PrintItemsInIndex(0);

    while(name != "exit"){
        cout << "Search for: "; 
        cin >> name; 
        if(name != "exit") {
            H1.FindDrink(name);
        }
    }

    while(name != "exit"){
        cout << "Remove: "; 
        cin >> name; 
        if(name != "exit") {
            H1.RemoveItem(name);
        }
    }
    return 0;
}