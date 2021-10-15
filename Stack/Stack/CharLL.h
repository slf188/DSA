//
//  CharLL.h
//  Stack
//
//  Created by Felipe Vallejo on 13/10/21.
//

#ifndef CharLL_h
#define CharLL_h

struct NodeC {
    char data;
    NodeC *nextNode;
}*topC = nullptr;

void push(char x){
    NodeC *t = new NodeC;
    if (t == NULL)
        cout << "Stack Overflow\n";
    else{
        t->data = x;
        t->nextNode = topC;
        topC = t;
    }
}

void popC(){
    char x = -1;
    NodeC *p;
    if (topC == nullptr)
        cout << "Stack Underflow\n";
    else {
        p = topC;
        topC = topC->nextNode;
        x = p->data;
        delete p;
    }
}

int isBalanced(char const *exp){
    for(int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if (topC == NULL){
                return 0;
            }
            else
                popC();
        }
    }
    return (top == NULL ? 1 : 0);
}

#endif /* CharLL_h */
