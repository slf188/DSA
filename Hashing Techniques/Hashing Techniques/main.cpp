//
//  main.cpp
//  Hashing Techniques
//
//  Created by Felipe Vallejo on 14/1/22.
//

#include <iostream>
#include "Node.h"
#define SIZE 10
using namespace std;

int hashFunction(int key){
    return key % 10;
}

void insert(struct Node *H[], int key){
    int index = hashFunction(key);
    SortedInsert(&H[index],key);
}

int hashing(int key){
    return key%SIZE;
}

int probe(int H[],int key){
    int index=hashing(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
        i++;
    return (index+i)%SIZE;
}

void Insert(int H[],int key){
    int index=hashing(key);
    
    if(H[index]!=0)
        index=probe(H,key);
    H[index]=key;
}

int Search(int H[],int key){
    int index=hashing(key);
    
    int i=0;
    
    while(H[(index+i)%SIZE]!=key)
        i++;
    
    return (index+i)%SIZE;
}

int main() {
    int HT[10]={0};
    
    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);
    return 0;
}
