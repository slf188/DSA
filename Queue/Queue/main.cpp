//
//  main.cpp
//  Queue
//
//  Created by Felipe Vallejo on 19/10/21.
//

#include <iostream>
using namespace std;

struct CircularQueue {
    int size;
    int rear;
    int front;
    int *array;
};

void createQueueC(CircularQueue *q, int size){
    q->size = size;
    q->array = new int[q->size];
    q->front = 0; q->rear = 0;
}

void enqueueC(CircularQueue *q, int x){
    if ((q->rear + 1) % q->size == q->front)
        cout << "Queue is full\n";
    else {
        q->rear = (q->rear + 1) % q->size;
        q->array[q->rear] = x;
    }
}

int dequeueC(CircularQueue *q){
    int x = -1;
    if (q->front == q->rear)
        cout << "Queue is empty\n";
    else {
        q->front = (q->front + 1) % q->size;
        x = q->array[q->front];
    }
    return x;
}

void displayC(CircularQueue *q){
    for(int i = q->front + 1; i <= q->rear; i++)
        cout << q->array[i] << " ";
}

int main() {
    CircularQueue q;
    createQueueC(&q, 5);
    enqueueC(&q,10);
    enqueueC(&q,20);
    enqueueC(&q,30);
    enqueueC(&q,40);
    enqueueC(&q,50);
    // We can only occupy size -1 in a circular queue
    dequeueC(&q);
    displayC(&q);
    return 0;
}
