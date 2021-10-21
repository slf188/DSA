//
//  main.cpp
//  Queue
//
//  Created by Felipe Vallejo on 19/10/21.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *nextNode;
} *front = nullptr, *rear = nullptr;

void create(Node *q){
    
}

void enqueue(Node *q, int x){
    Node *t = new Node;
    if (t == NULL)
        cout << "The queue is full\n";
    else{
        t->data = x;
        t->nextNode = nullptr;
        // If this is the first node:
        if(front == nullptr)
            front = rear = t;
        else {
            rear->nextNode = t;
            rear = t;
        }
    }
}

void dequeue(Node *q){
    
}

void display(Node *q){
    
}

int main() {
    
    return 0;
}
