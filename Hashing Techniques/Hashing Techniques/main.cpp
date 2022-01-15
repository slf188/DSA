//
//  main.cpp
//  Hashing Techniques
//
//  Created by Felipe Vallejo on 14/1/22.
//

#include <iostream>
#include "Node.h"
using namespace std;

int hashFunction(int key){
    return key % 10;
}

void insert(struct Node *H[], int key){
    int index = hashFunction(key);
    SortedInsert(&H[index],key);
}

int main() {
    struct Node *hashTable[10];
    int i;
    
    for(i=0;i<10;i++)
        hashTable[i]=NULL;
    
    insert(hashTable,12);
    insert(hashTable,22);
    insert(hashTable,42);
    return 0;
}
