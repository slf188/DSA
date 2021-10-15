//
//  LinkedList.h
//  Stack
//
//  Created by Felipe Vallejo on 12/10/21.
//

#ifndef LinkedList_h
#define LinkedList_h
using namespace std;

struct Node {
    int data;
    Node *nextNode;
}*top = nullptr;

void push(int x){
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow\n";
    else{
        t->data = x;
        t->nextNode = top;
        top = t;
    }
}

void pop(){
    int x = -1;
    Node *p;
    if (top == nullptr)
        cout << "Stack Underflow\n";
    else {
        p = top;
        top = top->nextNode;
        x = p->data;
        delete p;
    }
}

void peek(int position){
    int x = -1;
    Node *p = top;
    for(int i = 0; p != NULL && i < position - 1; i++)
        p = p->nextNode;
    if (p != NULL)
        x = p->data;
    cout << "The value at that particular position is " << x << endl;
}

void stackTop(){
    if (top != nullptr)
        cout << "The top value is " << top->data << endl;
    else
        cout << "The top value is -1\n";
}

void isEmpty(){
    cout << (top != nullptr ? "It is empty\n" : "Not empty\n");
}

void isFull(){
    Node *t = new Node;
    cout << (t != nullptr ? "It is full\n" : "Not full\n");
    delete t;
}

void display(){
    Node *p;
    p = top;
    while(p != nullptr){
        printf("%d\n", p->data);
        p = p->nextNode;
    }
}

#endif /* LinkedList_h */
