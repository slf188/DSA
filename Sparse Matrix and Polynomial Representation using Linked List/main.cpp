//
//  main.cpp
//  Polynomial Representation using Linked List
//
//  Created by Felipe Vallejo on 6/10/21.
//

#include <iostream>
#include <cmath>
using namespace std;

struct PolynomialNode {
    int coefficient;
    int exponent;
    PolynomialNode *nextNode;
} *poly = nullptr;

void create(){
    PolynomialNode *nodeCreator, *lastNode = NULL;
    int num, i;
    cout << "Enter number of terms\n";
    cin >> num;
    cout << "Enter each term with coeff and exp\n";
    
    for (int i = 0; i < num; i++){
        nodeCreator = new PolynomialNode;
        cin >> nodeCreator->coefficient >> nodeCreator->exponent;
        nodeCreator->nextNode = NULL;
        if (poly == nullptr)
            poly = lastNode = nodeCreator;
        else {
            lastNode->nextNode = nodeCreator;
            lastNode = nodeCreator;
        }
    }
}

void display(PolynomialNode *p){
    while(p){
        cout << p->coefficient << " " << p->exponent << " " << endl;
        p = p->nextNode;
    }
}

void eval(PolynomialNode *p, int x){
    double sum = 0.0;
    PolynomialNode *q = p;
    while(q){
        sum += q->coefficient * pow(x, q->exponent);
        q = q->nextNode;
    }
    cout << sum << endl;
}

int main() {
    
    create();
    display(poly);
    eval(poly, 1);
    
    return 0;
}

//» Enter number of terms
//3
//Enter each term with coeff and exp
//1 2
//2 3
//4 4
//1 2
//2 3
//4 4
//7
