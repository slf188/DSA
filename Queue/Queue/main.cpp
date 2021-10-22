//
//  main.cpp
//  Queue
//
//  Created by Felipe Vallejo on 19/10/21.
//

#include <iostream>
using namespace std;

struct Dequeue{
    int size;
    int rear;
    int front;
    int *array;
};

void createD(Dequeue *d, int size){
    d->size = size;
    d->array = new int[d->size];
    d->front = d->rear = -1;
}

void enqueueF(Dequeue *d, int x){
    if (d->front == -1)
        cout << "Queue Overflow" << endl;
    d->array[d->front] = x;
    d->front--;
}

void enqueueR(Dequeue *d, int x){
    if (d->rear == d->size - 1)
        cout << "Queue Overflow\n";
    d->rear++;
    d->array[d->rear] = x;
}

int dequeueF(Dequeue *d){
    int x = -1;
    if (d->front == d->rear)
        cout << "Queue underflow\n";
    x = d->array[d->front];
    d->front++;
    return x;
}

int dequeueR(Dequeue *d){
    int x = -1;
    if (d->rear == -1)
        cout << "Queue underflow\n";
    x = d->array[d->rear];
    d->rear--;
    return x;
}

void display(Dequeue *d){
    for(int i = d->front + 1; i <= d->rear; i++)
        cout << d->array[i] << " ";
    cout << endl;
}

int main() {
    
    Dequeue d;
    
    createD(&d, 5);
    enqueueR(&d, 4);
    enqueueR(&d, 6);
    enqueueR(&d, 9);
    enqueueR(&d, 10);
    dequeueR(&d);
    display(&d);
    
    return 0;
}
