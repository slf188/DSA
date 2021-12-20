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

int main() {
    
    int A[] = {30, 20, 15, 5, 10, 12, 6};
    insert(A, 40);
    
    return 0;
}
