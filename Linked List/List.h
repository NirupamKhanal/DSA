#ifndef LIST_H
#define LIST_H

class List{
private: //This is where the data goes.

        typedef struct node{
            int data;
            node* next; 
        }* nodePtr;

        nodePtr head; 
        nodePtr curr; 
        nodePtr temp; 

public: //This is where the functions go.
    List();
    void AddNode(int addData);
    void DeleteNode(int delData); 
    void PrintList();
};

#endif
