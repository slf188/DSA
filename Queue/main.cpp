//
//  main.cpp
//  Queue
//
//  Created by Felipe Vallejo on 19/10/21.
//

#include <iostream>
using namespace std;

struct Queue {
    int size;
    int rear;
    int front;
    int *array;
};

void createQueue(Queue *q, int size){
    q->size = size;
    q->array = new int[q->size];
    q->front = -1; q->rear = -1;
}

void enqueue(Queue *q, int x){
    if (q->rear == q->size - 1)
        cout << "Queue is full\n";
    else {
        q->rear++;
        q->array[q->rear] = x;
    }
}

int dequeue(Queue *q){
    int x = -1;
    if (q->front == q->rear)
        cout << "Queue is empty\n";
    else {
        q->front++;
        x = q->array[q->front];
    }
    return x;
}

void display(Queue *q){
    for(int i = q->front + 1; i <= q->rear; i++)
        cout << q->array[i] << " ";
}

int main() {
    Queue myQueue;
    
    createQueue(&myQueue, 7);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 6);
    enqueue(&myQueue, 8);
    enqueue(&myQueue, 15);
    enqueue(&myQueue, 7);
    enqueue(&myQueue, 5);
    dequeue(&myQueue);
    display(&myQueue);
    
    return 0;
}
