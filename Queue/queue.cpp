#include <iostream>

using namespace std; 

const int i = 10;
int A[i]; 
int front = -1; 
int rear = -1; 

bool isempty() {
    if(front == -1 && rear == -1){
        return true;
    }
    else {
        return false;
    }
}

void enqueue(int value) {
    if(rear == i - 1) {
        cout << "Queue is full.\n";
    }
    else {
        if(front == -1) {
            front = 0;
        }
        rear++;
        A[rear] = value;
    }
}

void dequeue() {
    if(isempty()) {
        cout << "Queue is empty.\n";
    }
    else {
        if(front == rear) {
            front = rear = -1;
        }
        else 
        {front++;}
    }
}

void showFront() {
    if(isempty()) {
        cout << "Queue is empty.\n";
    }
    else {
        cout << "Element at the front is: " << A[front] << endl;
    }
}

void displayQueue() {
    if(isempty()) {
        cout << "Queue is empty.\n";
    }
    else {
        int j = 0;
        for(int j = front; j <= rear; j++) {
            cout << A[j] << endl;
        }
    }
}

int main() {
    
    enqueue(2);
    enqueue(3);
    enqueue(88);
    enqueue(29);
    displayQueue();
    return 0;
}
