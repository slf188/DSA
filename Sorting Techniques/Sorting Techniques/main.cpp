//
//  main.cpp
//  Sorting Techniques
//
//  Created by Felipe Vallejo on 6/1/22.
//

#include <iostream>
#include <cmath>
using namespace std;

class Node{
public:
    int value;
    Node* next;
};

void Insert(Node** ptrBins, int value, int idx){
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;
    
    if (ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

int Max(int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

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

int findMax(int A[], int n){
    int max=INT32_MIN;
    int i;
    for(i=0;i<n;i++)
        if(A[i]>max)
            max=A[i];
    return max;
}

void countSort(int A[], int n){
    int max = findMax(A, n), i;
    int *count = new int[max];
    for(int i=0; i<max + 1; i++)
        count[i] = 0;
    for(i = 0; i<n; i++)
        count[A[i]]++;
    i = 0;
    int j = 0;
    while(i < max + 1){
        if(count[i] > 0){
            A[j++] = i;
            count[i]--;
        } else {
            i++;
        }
    }
    
    for(int i = 0; i < n; i++)
        printf("%d ",A[i]);
    cout << endl;
}

//void binBucketSort(int A[], int n){
//    int max, i, j;
//    Node **bins;
//    max = findMax(A, n);
//    bins = new Node*[max + 1];
//    // We initialize the array with null values
//    for(i = 0; i < max + 1; i++)
//        bins[i] = NULL;
//    // We insert the elements from array A to the bins array
//    for(i = 0; i < n; i++)
//        insert(bins[A[i]], A[i]);
//
//    i = 0, j = 0;
//    // Delete and copy the elements back to the array A
//    while(i < max + 1){
//        while(bins[i] != nullptr)
//            A[j++] = delete(bin[i]);
//        i++;
//    }
//}

int countDigits(int x){
    int count = 0;
    while (x != 0){
        x = x / 10;
        count++;
    }
    return count;
}

void initializeBins(Node** p, int n){
    for (int i=0; i<n; i++){
        p[i] = nullptr;
    }
}

int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) % 10;
}

void radixSort(int A[], int n){
    int max = Max(A, n);
    int nPass = countDigits(max);
    
    // Create bins array
    Node** bins = new Node* [10];
    
    // Initialize bins array with nullptr
    initializeBins(bins, 10);
    
    // Update bins and A for nPass times
    for (int pass=0; pass<nPass; pass++){
        
        // Update bins based on A values
        for (int i=0; i<n; i++){
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }
        
        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10){
            while (bins[i] != nullptr){
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }
    
    // Delete heap memory
    delete [] bins;
    
    for(int i = 0; i < n; i++)
        printf("%d ",A[i]);
    cout << endl;
}

void shellSort(int A[],int n){
    int gap,i,j,temp;
    
    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp){
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d ",A[i]);
    cout << endl;
}

int main() {
    int A[] = {9, 5, 16, 8, 13, 6, 12, 10, 4, 2, 3};
    shellSort(A, 11);
    return 0;
}
