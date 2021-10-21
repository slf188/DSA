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

void enqueue(int x){
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

int dequeue(){
    int x = -1;
    Node *p;
    if(front == NULL)
        cout << "The queue is empty\n";
    else {
        p = front;
        front = front->nextNode;
        x = p->data;
        delete p;
    }
    return x;
}

void display(){
    Node *p = front;
    while(p != nullptr){
        cout << p->data << " ";
        p = p->nextNode;
    }
    cout << endl;
}

int main() {
    
    enqueue(4);
    enqueue(9);
    enqueue(3);
    enqueue(8);
    display();
    
    return 0;
}
