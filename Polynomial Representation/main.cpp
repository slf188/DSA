//
//  main.cpp
//  Polynomial Representation
//
//  Created by Felipe Vallejo on 4/8/21.
//

#include <iostream>
#include <cmath>
using namespace std;

struct Term{
    int coefficient;
    int exponent;
};

struct Polynomial{
    int numOfElements;
    Term *terms;
};

void create(struct Polynomial *p){
    cout << "Enter the number of non-zero elements\n";
    scanf("%d", &p->numOfElements);
    p->terms = new Term[p->numOfElements];
    cout << "Enter the terms\n";
    for(int i = 0; i < p->numOfElements; i++)
        scanf("%d%d", &p->terms[i].coefficient, &p->terms[i].exponent);
}

void display(struct Polynomial p){
    for(int i = 0; i < p.numOfElements; i++)
        printf("%dx%d+\n", p.terms[i].coefficient, p.terms[i].exponent);
}

Polynomial *add(struct Polynomial *p1, struct Polynomial *p2){
    int i {0}, j {0}, k {0};
    
    Polynomial *sum = new Polynomial;
    
    sum->terms = new Term[p1->numOfElements + p2->numOfElements];
    
    while(i < p1->numOfElements && j < p2->numOfElements){
        if (p1->terms[i].exponent > p2->terms[j].exponent)
            sum->terms[k++] = p1->terms[i++];
        else if (p1->terms[i].exponent < p2->terms[j].exponent)
            sum->terms[k++] = p2->terms[j++];
        else{
            sum->terms[k].exponent = p1->terms[i].exponent;
            sum->terms[k++].coefficient = p1->terms[i++].coefficient + p2->terms[j++].coefficient;
        }
    }
    
    for(; i < p1->numOfElements; i++)
        sum->terms[k++] = p1->terms[i];
    
    for(; j < p2->numOfElements; j++)
        sum->terms[k++] = p2->terms[j];
    
    sum->numOfElements = k;
    
    return sum;
}

int main() {
    
    Polynomial p1, p2, *p3;
    
    create(&p1);
    create(&p2);
    
    
    display(p1);
    cout << endl;
    
    create(&p2);
    display(p2);
    cout << endl;
    
    p3 = add(&p1, &p2);
    
    display(*p3);
    
    return 0;
}
