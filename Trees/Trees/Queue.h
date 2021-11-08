//
//  Queue.h
//  Trees
//
//  Created by Felipe Vallejo on 8/11/21.
//

#ifndef Queue_h
#define Queue_h
using namespace std;

struct Node {
    Node *lChild;
    int data;
    Node *rChild;
};

struct Queue {
    int size;
    int rear;
    int front;
    Node **array;
};

void createQueue(Queue *q, int size){
    q->size = size;
    q->array = new Node*[q->size];
    q->front = -1; q->rear = -1;
}

void enqueue(Queue *q, Node *x){
    if (q->rear == q->size - 1)
        cout << "Queue is full\n";
    else {
        q->rear++;
        q->array[q->rear] = x;
    }
}

Node * dequeue(Queue *q){
    Node *x = NULL;
//    int x = -1;
    if (q->front == q->rear)
        cout << "Queue is empty\n";
    else {
        q->front++;
        x = q->array[q->front];
    }
    return x;
}

int isEmpty(Queue q){
    return q.front==q.rear;
}

#endif /* Queue_h */
