//
//  main.cpp
//  Stack
//
//  Created by Felipe Vallejo on 11/10/21.
//

#include <iostream>
#include "Array.h"
#include "LinkedList.h"
#include "CharLL.h"
#include <cstring>
using namespace std;

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

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')
        return 0; // false
    else
        return 1; // true
}

int outPrecedence(char x){
    if (x == '+' || x == '-')
        return 1; //2
    else if (x == '*' || x == '/')
        return 3; // 4
    else if (x == '^')
        return 6; // 5
    else if (x == '(')
        return 7; // 0
    else if (x == ')')
        return 0;
    else
        return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else
        return -1;
}

void convertToPosfixC(char const *infix){
    int i = 0, j = 0;
    char *postfix = new char[strlen(infix) + 1];
    while(infix[i] != '\0'){
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if (!topC || outPrecedence(infix[i]) > inPrecedence(topC->data))
                push(infix[i++]);
            else
                if (outPrecedence(infix[i]) == inPrecedence(topC->data)){
                    popC();
                    i++;
                } else
                    postfix[j++] = popC();
        }
    }
    while(topC != nullptr){
        postfix[j++] = popC();
    }
    postfix[j] = '\0';
    cout << postfix;
}

int main() {
    char const *infix = "((a+b)*c)-d^e^f";
    
    convertToPosfixC(infix);
    
    return 0;
}
