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

char popC(){
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
    return x;
}

int isEmptyC() {
    return topC ? false : true;
}

int isBalanced(char *exp){
    for(int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')'){
            if (topC == NULL){
                break;
            }
            else
                popC();
        }
    }
    return isEmptyC() ? true : false;
}

#endif /* CharLL_h */
