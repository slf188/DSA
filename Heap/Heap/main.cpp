//
//  main.cpp
//  Heap
//
//  Created by Felipe Vallejo on 20/12/21.
//

#include <iostream>
using namespace std;

void insert(int A[], int n){
    int temp, i = n;
    temp = A[n];
    while(i > 1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

void createHeap(){
    int A[] = {40, 35, 30, 15, 10, 25, 5};
    int i;
    for(i = 2; i <= 7; i++)
        insert(A, i);
}

void deleteHeap(int A[], int n){
    // n is the last index
    int x, i, j;
    // the last element is copied into x
    x = A[n];
    // we copy the last element at the root
    A[i] = A[n];
    // i must be placed at index one and j at its left child
    i = 1, j = 2 * i;
    // this procedure just repeats so we need to write a while loop
    while(j < n - 1){
        // 1. compare left and right child, the element that is greater will point on j
        if(A[j + 1] > A[j])
            j = j + 1;
        /* 2. if the parent element is smaller than the child
         element then interhcange the parent and the child */
        if(A[i] < A[j]){
            swap(A[i], A[n]);
            i = j;
            j = 2 * j;
        } else
            break;
    }
    // Heap sort:
    A[n] = x;
}

int main() {
//    createHeap();
    int A[] = {40, 35, 30, 15, 10, 25, 5};
    deleteHeap(A, 5);
    return 0;
}
