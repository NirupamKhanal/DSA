#include <iostream>

using namespace std; 

void display(const int *start, const int *end);

int main()
{
    int numbers[] = {11,22,33,44,55,66,77,88,99}; //instantiate array 
    //printing ranges numbers+i
    display(numbers+3, numbers+9); 

    return 0;
}

void display(const int *start, const int *end) {
    
    const int *ptr;
    for(ptr = start; ptr != end; ptr++){
        cout << *ptr << endl;
    }
}
