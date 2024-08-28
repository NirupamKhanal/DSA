#include <cstdlib>
#include <iostream>

#include "List.h"

using namespace std; 

List::List() {
    head = NULL; 
    curr = NULL; 
    temp = NULL; 
}

void List::AddNode(int addData) {
    nodePtr n = new node; 
    n -> next = NULL; 
    n -> data = addData; 

    if (head != NULL) {
        curr = head; 
        while(curr -> next != NULL) {
            curr = curr -> next; 
        }
        curr -> next = n; 
    }
    else
    {
        head = n; 
    }
}

void List::DeleteNode(int delData) {
    nodePtr delPtr = NULL; 
    temp = head; 
    curr = head; 
    while(curr != NULL && curr -> data != delData) {
        temp = curr; 
        curr = curr -> next; 
    }
    if(curr == NULL) {
        cout << delData << "was not in the list.\n";
        delete delPtr; 
    }
    else {
        delPtr = curr; 
        curr = curr ->  next; 
        temp -> next = curr; 
        delete delPtr; 
        cout << "The value " << delData << "was deleted.\n"; 
    }
}

void List::PrintList() {
    curr = head; 
    while(curr != NULL) {
        cout << curr -> data << endl; 
        curr = curr -> next;
    }
}

void List::SearchRecursive(node* Ptr, int SearchValue) {
    if(Ptr == NULL) {
        cout << SearchValue << " was not found.\n";
    }
    else if(Ptr -> data == SearchValue) {
        cout << SearchValue << " is in the list.\n";
    }
    else {
        SearchRecursive(Ptr -> next, SearchValue);
    }
}
