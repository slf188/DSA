//
//  main.cpp
//  Arrays
//
//  Created by Felipe Vallejo on 27/6/21.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(Array arr){
    for (int i = 0; i < arr.length; i++){
        cout << arr.A[i] << endl;
    }
}

void Append(Array *arr, int x){
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void Insert(Array *arr, int index, int x){
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(Array *arr, int index) {
    int x = 0;
    if (index >= 0 && index < arr->length) {
        for (int i = index; i < arr->length - 1; i++){
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int LinearSearch(Array arr, int key) {
    for (int i = 0; i < arr.length; i++){
        if (key == arr.A[i]){
            return i;
        }
    }
    return -1;
}

int BinarySearch(Array arr,int key){
    int l, mid, h;
    l = 0;
    h = arr.length-1;
    while(l <= h){
        mid = (l + h) / 2;
        if(key == arr.A[mid]){
            return mid;
        } else if(key < arr.A[mid]){
            h=mid-1;
        } else{
            l=mid+1;
        }
    }
    return -1;
}

int get(Array arr, int index) {
    if (index >= 0 && index < arr.length){
        return arr.A[index];
    } else {
        return -1;
    }
}

void set(Array *arr, int index, int x){
    if (index >= 0 && index < arr->length){
        arr->A[index] = x;
    }
}

int max(Array arr) {
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++){
        if (arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int min(Array arr) {
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++){
        if (arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int sum(Array arr){
    int total = 0;
    for (int i = 0; i < arr.length; i++){
        total += arr.A[i];
    }
    return total;
}

int avg(Array arr){
    int total = 0;
    for (int i = 0; i < arr.length; i++){
        total += arr.A[i];
    }
    return total / arr.length;
}

void reverse1(Array *arr){
    int *B;
    int i, j;
    B = new int[arr->length];
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++){
        B[j] = arr->A[i];
    }
    
    for (i = 0; i < arr->length; i++){
        arr->A[i] = B[i];
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse2(Array *arr){
    int i, j;
    for (i = 0, j = arr -> length - 1; i < j; i++, j--){
        swap(&arr->A[i], &arr->A[j]);
    }
}

void insertInSorted(Array arr, int x){
    int i = arr.length - 1;
    while (arr.A[i] > x){
        arr.A[i + 1] = arr.A[i];
        i--;
    }
    arr.A[i + 1] = x;
    Display(arr);
}

bool isSorted(Array arr){
    for (int i = 0; i < arr.length - 1; i++){
        if (arr.A[i] > arr.A[i + 1]){
            return false;
        }
    }
    return true;
}

void exchange(Array arr){
    int i = 0;
    int j = arr.length - 1;
    while (i < j){
        while (arr.A[i] < 0){
            i++;
        }
        while (arr.A[j] > 0){
            j--;
        }
        if (i < j){
            swap(arr.A[i], arr.A[j]);
        }
    }
    Display(arr);
}

Array Merge(Array arr1, Array arr2){
    int i {0}, j {0}, k {0};
    
    Array arr3 = *new Array;
    
    while(i < arr1.length && j < arr2.length)
        if(arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else
            arr3.A[k++] = arr2.A[j++];
    
    for(; i < arr1.length; i++)
        arr3.A[k++] = arr1.A[i];
    
    for(; j < arr2.length; j++)
        arr3.A[k++] = arr2.A[j];
    
    arr3.length = arr1.length + arr2.length;
    arr3.size = 10;
    return arr3;
}

Array Union(Array arr1, Array arr2){
    int i {0}, j {0}, k {0};
    Array arr3 = *new Array;
    while (i < arr1.length && j < arr2.length){
        if (arr1.A[i] < arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];
        } else if (arr2.A[j] < arr1.A[i]){
            arr3.A[k++] = arr2.A[j++];
        } else {
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
    }
    
    for (; i < arr1.length; i++)
        arr3.A[k++] = arr1.A[i];
    
    for (; j < arr2.length; j++)
        arr3.A[k++] = arr2.A[j];
    
    arr3.length = k;
    arr3.size = 10;
    return arr3;
}

Array Intersection(Array arr1, Array arr2){
    int i {0}, j {0}, k {0};
    Array arr3 = *new Array;
    
    while (i < arr1.length && j < arr2.length){
        if (arr1.A[i] < arr2.A[j]){
            i++;
        } else if (arr2.A[j] < arr1.A[i]){
            j++;
        } else if (arr1.A[i] == arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
    }
    
    arr3.length = k;
    arr3.size = 10;
    return arr3;
}

Array Difference(Array arr1, struct Array arr2){
    int i {0}, j {0}, k {0};
    Array arr3 = *new Array;
    while(i < arr1.length && j < arr2.length){
        if (arr1.A[i] < arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];
        } else if (arr2.A[j] < arr1.A[i]){
            j++;
        } else {
            i++;
            j++;
        }
    }
    
    for(; i < arr1.length; i++)
        arr3.A[k++] = arr1.A[i];
    
    arr3.length = k;
    arr3.size = 10;
    return arr3;
}

void missingElement(Array arr1, int low, int num){
    int diff = low - 0;
    for (int i = 0; i < num; i++){
        if (arr1.A[i] - i != diff){
            cout << "The position of the missing element is " << diff << endl;
            break;
        }
    }
}

void missingMultipleElements(Array arr1, int low, int num){
    int diff = low - 0;
    for (int i = 0; i < num; i++){
        if (arr1.A[i] - i != diff){
            while(diff < arr1.A[i] - i){
                cout << "The missing element is " << i + diff << endl;
                diff++;
            }
        }
    }
}

void missingUnsorted(Array arr1, int high, int num){
    
    Array H = *new Array;
    
    for (int i = 0; i < num; i++)
        H.A[arr1.A[i]]++;
    
    for (int i = 0; i <= high; i++)
        if (H.A[i] == 0)
            cout << "The missing element is " << i << endl;
    
}

void countDuplicate(Array arr1, int length, int max){
    
    int *H = new int[max + 1];
    
    for (int i = 0; i < max + 1; i++)
        H[i] = 0;
    
    for (int i = 0; i < length; i++)
        H[arr1.A[i]]++;
    
    for (int i = 0; i <= max; i++)
        if (H[i] > 1)
            cout << i << " is repeated " << H[i] << " times" << endl;
    
}

void unsortedSumK(Array arr1, int length, int k, int max){
    
    int *H = new int[max + 1];
    
    for (int i = 0; i < max + 1; i++)
        H[i] = 0;
    
    for (int i = 0; i < k; i++){
        if(k - arr1.A[i] >= 0 && H[k - arr1.A[i]] != 0){
            printf("%d + %d = %d\n", arr1.A[i], k - arr1.A[i], k);
        }
        H[arr1.A[i]]++;
    }
    
}

void sortedSumK(Array arr1, int length, int k){
    int i {0}, j {length - 1};
    
    while(i < j){
        if (arr1.A[i] + arr1.A[j] == k){
            printf("%d + %d = %d\n", arr1.A[i], k - arr1.A[i], k);
            i++;
            j++;
        } else if (arr1.A[i] + arr1.A[j] < k){
            i++;
        } else {
            j--;
        }
    }
}

void maxMin(Array arr1, int length){
    int min = arr1.A[0];
    int max = arr1.A[0];
    
    for (int i = 0; i < length; i++)
        if (arr1.A[i] < min)
            min = arr1.A[i];
        else if (arr1.A[i] > max)
            max = arr1.A[i];
    
    printf("Max: %d and Min: %d\n", max, min);
}

int main() {
    
    Array arr1 {{5, 8, 3, 9, 6, 2, 10, 7, -1, 4}, 10, 9};
    
    maxMin(arr1, 9);
    
    return 0;
    
}
