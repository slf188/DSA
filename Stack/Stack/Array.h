//
//  Array.h
//  Stack
//
//  Created by Felipe Vallejo on 12/10/21.
//

#ifndef Array_h
#define Array_h
using namespace std;

struct Stack {
    int size;
    int top;
    int *array;
};

void create(Stack *st){
    cout << "Enter the desired size of the stack\n";
    cin >> st->size;
    st->array = new int[st->size];
    st->top = -1;
}

void push(Stack *st, int x){
    if (st->top == st->size - 1)
        cout << "Stack overflow\n";
    else {
        st->top++;
        st->array[st->top] = x;
    }
}

void pop(Stack *st){
    int x = -1;
    if (st->top == -1)
        cout << "Stack underflow\n";
    else{
        x = st->array[st->top];
        st->top--;
    }
    cout << "The deleted value is " << x << endl;
}

void peek(Stack *st, int position){
    int index = -1;
    if (st->top - position + 1 < 0)
        cout << "Invalid position\n";
    else {
        index = st->array[st->top - position + 1];
        printf("The value at %d is %d", position, index);
    }
}

void stackTop(Stack *st){
    if (st->top == -1)
        cout << "Stack underflow\n";
    else
        cout << st->array[st->top] << endl;
}

void isEmpty(Stack *st){
    if (st->top == -1)
        cout << "The stack is empty\n";
    else
        cout << "The stack is not empty\n";
}

void isFull(Stack *st){
    if (st->top == st->size - 1)
        cout << "The stack is full\n";
    else
        cout << "The stack is not full\n";
}

void displayStack(Stack *st){
    cout << "The stack looks as follows:\n";
    for(int i = st->top; i >= 0; i--)
        cout << st->array[i] << endl;
}

#endif /* Array_h */
