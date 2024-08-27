#include <cstdlib>
#include "List.h"

using namespace std; 

int main(int argc, char** argv) {
    
    List list; 
    list.AddNode(3); 
    list.AddNode(5); 
    list.AddNode(7);
    list.PrintList();

    list.DeleteNode(5);
    list.PrintList();
    return 0;
}
