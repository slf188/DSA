//
//  main.cpp
//  Sorting Techniques
//
//  Created by Felipe Vallejo on 6/1/22.
//

#include <iostream>
using namespace std;

void bubbleSort(int A[], int n){
    int flag;
    // This for loop is reponsible for the passes
    for(int i = 0; i < n - 1; i++){
        flag = 0;
        // This for loop is reponsible to traverse through the whole array and swap the elements
        for(int j = 0; j < n - 1 - i; j++)
            if(A[j] > A[j + 1]){
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        /* By introducing flag we can identify whether there was any swapping in the past, if there is no swapping then the list is already sorted and can stop the whole algorithm.
         By introducing flag we have made bubble sort an adaptive technique, by nature is it not adaptive.
         */
    
        if(flag == 0)
            break;
    }
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    cout << endl;
}

void insertionSort(int A[], int x){
    
}

int main() {
    int A[] = {8, 5, 7, 3, 2};
    bubbleSort(A, 5);
    return 0;
}
