# 9 - Queue

### What is queue?

- Queue is a logical data strucure.
- It works on the discipline **FIFO - First in First out.**
- We find queue in daily life when people are standing in a queue to submit an application, cars standing in a tollbooth.

Example:

- We have people standing in a queue waiting for their turn, and we have a person in a counter.
- The queue has two ends front and rear.
    - Insertion is done at the rear end.
    - Deletion is done in the front end.

![Untitled](9%20-%20Queue%20f7244/Untitled.png)

### Queue ADT

- Queue can be implemented using two physical data structures.
    - Array
    - Linked List

**Data**

- We need a property that can be used to store data.
- A front pointer that will be used for deleting elements.
- A rear pointer that will be used for inserting elements.

**Operations**

- enqueue(x)
    - Inserting an element in a queue
- dequeue()
    - Delete an element in a queue
- isEmpty()
    - Check whether the queue is empty or not
- isFull()
    - Check if the queue is full or not

### Queue using array

**Queue using a single pointer**

- We need to take an array of fixed size
- We need one pointer that is the rear pointer.
- When there is nothing in the queue then the rear pointer should point to -1.
- To insert an elemente we move rear to the next position and insert an element.
- To delete an element i.e. the first inserted element. We delete it and we fill the blank space by moving all the elements to the left which means when we reach the last element the rear pointer should also move to its previous location.
- This is a huge drawback, the delete operation should also take constant time.

![Untitled](9%20-%20Queue%20f7244/Untitled%201.png)

**Queue using two pointers**

- So we start out with a fixed size array
- We have two pointers rear and front
- Both should initially be at -1 when the queue is empty
- To insert an element we should move rear to the next location and insert and element.
- To delete an element we move front to the index 0 and take out the element.
- This procedure will now take both constant time to insert and delete. This means our queue has become faster.
- We say the queue is empty when the position of front and rear are equal.
- We say the queue is full when rear is greater then the size - 1

```cpp
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

» 6 8 15 7 5
```

**Drawback of queue using array**

- We cannot reuse the spaces of deleted elements

![Untitled](9%20-%20Queue%20f7244/Untitled%202.png)

- We can only use each space only one time

![Untitled](9%20-%20Queue%20f7244/Untitled%203.png)

- There might be a situation where the queue is full as well as empty

![Untitled](9%20-%20Queue%20f7244/Untitled%204.png)

**Solutions**

- To reuse the space we can reset the pointers
    - If the queue is becoming empty at any place we bring front and rear to the beginning.
    - Anywhere in between whenever front and rear are becoming equal we bring them to minus one at once. In order to reuse the empty places.
    - Although this method doesn't guarantee that these spaces will be reused, because if a queue is not becoming empty at any time then we cannot reset it and insert any more elements.
    - We have a solution for this problem, the solution is called Circular Queue.

### Circular Queue

- Initially front and rear will be at 0, not -1 anymore.
- Using rear we will insert and move to the next location.
- Wherever front is pointing that location should be empty. Using front we will delete we move it to the next location and remove the element.
- If the array is size 7 and rear is at index 6, then if we want to insert a new element then we bring rear at 0 and insert the element there. And this will until a certain condition is reached.

![Untitled](9%20-%20Queue%20f7244/Untitled%205.png)

- We can continue inserting for sure, but if rear and front meet we should stop. Front and rear will move circularly.

![Untitled](9%20-%20Queue%20f7244/Untitled%206.png)

- We can implement a circular queue using the modulo operator by using the following equation
    - **rear = rear + 1 % n**
    - n is the size of the queue
    - This guarantees all the spaces will be reused.
    - By moving the modulo operator we will move front and rear.
    
    ![Untitled](9%20-%20Queue%20f7244/Untitled%207.png)
    
- A better illustration of a circular queue is the following:

![Untitled](9%20-%20Queue%20f7244/Untitled%208.png)

```cpp
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

» Queue is full
20 30 40
```

### Queue using linked list

- For implementing a queue using a linked list we can take the following graph as an example of how it might work.
- For insertion we will use the rear side.
- For deletion we will use the front side.
- When the queue is initially empty front and rear shall be null.
- An empty queue in this case happens when front == null
- When we create the first node we should make both front and rear point on it.
- A full condition happens when the heap is full i.e.
    
    ```cpp
    Node *t = new Node;
    if (t == null)
    ```
    
- Because there is no size we can go on adding nodes.

![Untitled](9%20-%20Queue%20f7244/Untitled%209.png)

```cpp
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
}

int main() {
    
    enqueue(4);
    enqueue(9);
    enqueue(3);
    enqueue(8);
    display();
    
    return 0;
}

» 4 9 3 8
```

### DEQUEUE

- Also known as double-ended queue.
- If we implemet a queue in array and linked list we need two pointers.
- rear is used for insertion and front is used for deletion.
- In deuque we are not following the FIFO discipline.
- In dequeue we can use both pointers for both operations, insertion and deletion.
- In dequeue we must use an array, both front and rear should be positioned at index -1.

![Screen Shot 2021-10-21 at 18.44.03.png](9%20-%20Queue%20f7244/Screen_Shot_2021-10-21_at_18.44.03.png)

![Screen Shot 2021-10-21 at 18.44.19.png](9%20-%20Queue%20f7244/Screen_Shot_2021-10-21_at_18.44.19.png)

- If we insert with rear then we increment the rear pointer and insert a value.
- If we delete with rear we should delete the current value and decrement it.
- If we want to insert in front we should check if there is space available to do so. Like in this case.
    
    ![Screen Shot 2021-10-21 at 18.48.58.png](9%20-%20Queue%20f7244/Screen_Shot_2021-10-21_at_18.48.58.png)
    
- But we can delete in a situation like this by moving it to the next location and delete the value.
- When the current element of front's location is empty then we can insert. We insert the value and then decrement it.

```cpp
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

» 4 6 9
```

### Priority Queues

- There are two methods of implementing priority queues
1. Limited Set of Priorities
    1. We can set any number of priorities and group the elements according to which category they belong to.
    2. Whenever I have to insert an element, I will take its priority and insert it to the belonging priority queue:
        
        ![Screen Shot 2021-10-22 at 20.06.15.png](9%20-%20Queue%20f7244/Screen_Shot_2021-10-22_at_20.06.15.png)
        
    3. To delete we must delete an element from the highest priority queue. In this case it should be A from Q1. We must strictly follow the FIFO fashion. And when Q1 is completely empty we can proceed on deleting Q2 and so forth.
2. Element Priority
    1. In this case every element is a priority.
    2. We don't follow FIFO for this case.
    3. We have to take an array and store the elements inside this newly created array.
    4. The method of inserting elements is as follows:
        1. We insert an element at index 0.
        2. We insert another element and compare which is smaller, the smaller element should be positioned at index 1.
        3. Continue the loop until we finish the array elements.
        4. The array should have elements ordered in decreasing order.
    5. The method of deleting elements is as follows:
        1. Check which is the smallest element in the queue and delete it.

### Queue using two stacks

- If we have two stacks we can make the work just like a queue.
- If we have insert elements to the first stack we should push them to the first stack if LIFO order.
- If we want to delete the elements we should take out the elements and move them to the other stack. And to get the elements in FIFO discipline we should then delete them once again:
- If the stack two is empty we should first transfer the elements from stack one to stack two.

![Untitled](9%20-%20Queue%20f7244/Untitled%2010.png)

```cpp
class Queue{
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    Queue(){};
    ~Queue(){};
    void enqueue(int x);
    int dequeue();
};

void Queue::enqueue(int x) {
    stack1.push(x);
}

int Queue::dequeue() {
    int x = -1;
    if (stack2.empty()){
        if (stack1.empty()){
            cout << "Queue Underflow" << endl;
            return x;
        } else {
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }
    x = stack2.top();
    stack2.pop();
    return x;
}

int main() {
    int A[] = {6, 3, 9, 5, 4, 2, 8, 12, 10};
    Queue q;
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
        cout << A[i] << endl;
    }
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << q.dequeue() << " ";
    }
    cout << endl;
    return 0;
}

» 6
3
9
5
4
2
8
12
10
6 3 9 5 4 2 8 12 10
```