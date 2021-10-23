//
//  main.cpp
//  Queue
//
//  Created by Felipe Vallejo on 19/10/21.
//

#include <iostream>
#include <stack>
using namespace std;

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
