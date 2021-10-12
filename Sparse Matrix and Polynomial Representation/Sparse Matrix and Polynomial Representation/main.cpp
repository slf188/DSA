//
//  main.cpp
//  Sparse Matrix and Polynomial Representation
//
//  Created by Felipe Vallejo on 3/8/21.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int row;
    int col;
    int numOfElements;
    Element *e;
};

void create(struct Sparse *s){
    cout << "Enter dimensions" << endl;
    scanf("%d%d", &s->row, &s->col);
    cout << "Enter the number of non-zero elements" << endl;
    scanf("%d", &s->numOfElements);
    s->e = new Element[s->numOfElements];
    cout << "Enter non-zero elements" << endl;
    for(int i = 0; i < s->numOfElements; i++){
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void display(struct Sparse s){
    int k = 0;
    for(int i = 0; i < s.row; i++){
        for(int j = 0; j < s.col; j++){
            if(i == s.e[k].i && j == s.e[k].j)
                cout << s.e[k++].x;
            else
                cout << 0;
        }
        cout << endl;
    }
}

struct Sparse * add(struct Sparse *s1,struct Sparse *s2)
{
    struct Sparse *sum;
    int i,j,k;
    i=j=k=0;
    // If aCol is not equal to bCol and aRow is not equal to bRow return nothing
    if(s1->col != s2->col && s1->row != s2->row)
        return NULL;
    
    sum = new Sparse;
    sum->e = new Element[s1->numOfElements + s2->numOfElements];
    
    while(i < s1->numOfElements && j < s2->numOfElements){
        // If aRow < bRow then add the element a and i++
        if(s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        // If aRow > bRow then add the element b and j++
        else if(s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else {
            // If aCol < bCol then add the element a and i++
            if(s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            // If aCol > bCol then add the element b and j++
            else if(s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            // If aRow, aCol == bRow, bCol then add both elements and i++, j++
            else {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    
    for(;i < s1->numOfElements; i++)
        sum->e[k++]=s1->e[i];
    for(;j < s2->numOfElements; j++)
        sum->e[k++]=s2->e[j];
    
    sum->row = s1->row;
    sum->col = s1->col;
    sum->numOfElements = k;
    
    return sum;
}

int main() {
    
    
    
    return 0;
}
