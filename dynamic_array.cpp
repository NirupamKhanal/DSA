#include <iostream>
#include <cstdlib>

using namespace std; 

void set_all_elements(int * & d_arr, int value, int length);

int main(int argc, char * argv[]) {
    int * dynamic_array; 

    if(argc != 2) {
        cout << "Usage: " << argv[0] << " <num elements\n";
        return 1; 
    }

    int num_elements = atoi(argv[1]);
    dynamic_array = new int[num_elements]; 

    set_all_elements(dynamic_array, 13, num_elements);
    
    cout << "Printing a dynamically allocated array " 
        << "with " << argv[1] << " elements.\n";
    
    for(int i = 0; i < num_elements; ++i) {
        cout << "index[" << i << "]: " << dynamic_array[i] << endl;
    }
    cout << endl;

    delete[] dynamic_array; 

    return 0;
}

void set_all_elements(int * & d_arr, int value, int length) {
    d_arr[0] = -1; 
    for(int i = 1; i < length - 1; ++i) {
        d_arr[i] = value; 
        value++;
    }
    d_arr[length - 1] = -10;
}