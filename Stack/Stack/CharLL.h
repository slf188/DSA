//
//  CharLL.h
//  Stack
//
//  Created by Felipe Vallejo on 13/10/21.
//

#ifndef CharLL_h
#define CharLL_h

//struct NodeC {
//    char data;
//    NodeC *nextNode;
//}*topC = nullptr;
//
//void push(char x){
//    NodeC *t = new NodeC;
//    if (t == NULL)
//        cout << "Stack Overflow\n";
//    else{
//        t->data = x;
//        t->nextNode = topC;
//        topC = t;
//    }
//}
//
//char popC(){
//    char x = -1;
//    NodeC *p;
//    if (topC == nullptr)
//        cout << "Stack Underflow\n";
//    else {
//        p = topC;
//        topC = topC->nextNode;
//        x = p->data;
//        delete p;
//    }
//    return x;
//}
//
//int isBalanced(char const *exp){
//    for(int i = 0; exp[i] != '\0'; i++){
//        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
//            push(exp[i]);
//        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
//            if (topC == NULL){
//                return 0;
//            }
//            else
//                popC();
//        }
//    }
//    return (top == NULL ? 1 : 0);
//}
//
//int isOperand(char x){
//    if (x == '+' || x == '-' || x == '*' || x == '/')
//        return 0; // false
//    else
//        return 1; // true
//}
//
//int precedence(char x){
//    if (x == '+' || x == '-')
//        return 1;
//    else if (x == '*' || x == '/')
//        return 2;
//    else
//        return 0;
//}
//
//void convertToPosfix(char const *infix){
//    int i, j;
//    i = j = 0;
//    char *postfix = new char[strlen(infix) + 1];
//    while(infix[i] != '\0'){
//        if (isOperand(infix[i]))
//            postfix[j++] = infix[i++];
//        else {
//            if (precedence(infix[i]) > precedence(topC->data))
//                push(infix[i++]);
//            else
//                postfix[j++] = popC();
//        }
//    }
//    while(top != nullptr){
//        postfix[j++] = popC();
//    }
//    postfix[j] = '\0';
//    cout << postfix;
//}

//int isBalanced(char const *exp){
//    for(int i = 0; exp[i] != '\0'; i++){
//        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
//            push(exp[i]);
//        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
//            if (topC == NULL){
//                return 0;
//            }
//            else
//                popC();
//        }
//    }
//    return (topC == NULL ? 1 : 0);
//}

//int precedence(char x){
//    if (x == '+' || x == '-')
//        return 1;
//    else if (x == '*' || x == '/')
//        return 2;
//    else
//        return 0;
//}

//void convertToPosfixS(char const *infix){
//    int i = 0, j = 0;
//    char *postfix = new char[strlen(infix) + 1];
//    while(infix[i] != '\0'){
//        if (isOperand(infix[i]))
//            postfix[j++] = infix[i++];
//        else {
//            if (!topC || precedence(infix[i]) > precedence(topC->data))
//                push(infix[i++]);
//            else
//                postfix[j++] = popC();
//        }
//    }
//    while(topC != nullptr){
//        postfix[j++] = popC();
//    }
//    postfix[j] = '\0';
//    cout << postfix;
//}

#endif /* CharLL_h */
