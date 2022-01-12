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
    // For the passes
    int j, k;
    for(int i = 0; i < n - 1; i++){
        // For j and k
        for(j = k = i; j < n; j++){
            // Compare if j is smaller than k, if so move k to where j is
            if(A[j] < A[k])
                k = j;
        }
        // Swap i and k
        swap(A[i], A[k]);
    }
    
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    cout << endl;
}

int partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l, j = h;
    
    do{
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i < j)
            swap(A[i], A[j]);
    }while(i < j);
    swap(A[l], A[j]);
    return j;
    
}

void quickSort(int A[], int l, int h){
    // Quick sort is a recursive function that could be written inside the partition function.
    int j;
    if(l < h){
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);
    }
}

void mergeTwoLists(int A[], int B[], int m, int n){
    int C[m + n];
    int i, j, k;
    i = j = k = 0;
    while(i < m && j < n){
        if(A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = A[j++];
    }
    // Copy the elements from array A if there are any elements remaining
    for(; i < m; i++)
        C[k++] = A[i];
    // Copy the elements from array B if there are any elements remaining
    for(; j < n; j++)
        C[k++] = B[j];
    // The time taken for this algorithm is O(m + n)
    for(int l = 0; l < m + n; l++)
        printf("%d ", C[l]);
    cout << endl;
}

void mergeTwoInASingleArray(int A[], int l, int mid, int h){
    int i, j, k;
    i = l, j = mid + 1, k = l;
    int B[100];
    while(i <= mid && j <= h)
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    
    for(; i <= mid; i++)
        B[k++] = A[i];
    
    for(; j <= h; j++)
        B[k++] = A[j];
    
    for(i = l; i<=h;i++)
        A[i] = B[i];
    
    for(int i = 0; i < 8; i++)
        printf("%d ",A[i]);
    cout << endl;
}

void iterativeMergeSort(int A[], int n){
    int p, i, l, mid, h;
    for(p = 2; p <= n; p = p * 2)
        for(i = 0; i + p - 1 < n; i = i + p){
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            mergeTwoInASingleArray(A, l, mid, h);
        }
    if(p/2 < n)
        mergeTwoInASingleArray(A, 0, p/2, n - 1);
}

void recursiveMergeSort(int A[], int l, int h){
    int mid;
    if(l < h){
        mid = (l + h) / 2;
        // We repeat the function on the first half
        recursiveMergeSort(A, l, mid);
        // Perform merge sort on the right hand-side or second half
        recursiveMergeSort(A, mid + 1, h);
        // Merge the two lists in a single array with the help of auxiliary array B
        mergeTwoInASingleArray(A, l, mid, h);
    }
}

void countSort(int A[]){
    
}

int main() {
    int A[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    countSort(A);
    return 0;
}
