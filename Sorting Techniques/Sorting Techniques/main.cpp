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

void insertionSort(int A[], int n){
    /* For loop for passes
    1. We don't have to start from 0 because 0 is already sorted.
     2. We must check all the elements from the array.
     */
    int j, x;
    for(int i = 1; i < n; i++){
        j = i - 1;
        x = A[i];
        while(j > -1 && A[j] > x){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
        // We don't need the help of the flag variable becuase by nature insertion sort is adaptive.
    }
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    cout << endl;
}

void selectionSort(int A[], int n){
    
}

int main() {
    int A[] = {8, 5, 7, 3, 2};
    insertionSort(A, 5);
    return 0;
}
