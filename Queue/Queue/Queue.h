//
//  Queue.h
//  Queue
//
//  Created by Felipe Vallejo on 20/10/21.
//

#ifndef Queue_h
#define Queue_h

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


#endif /* Queue_h */
