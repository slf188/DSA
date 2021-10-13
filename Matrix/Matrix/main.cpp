//
//  main.cpp
//  Matrices
//
//  Created by Felipe Vallejo on 31/7/21.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Matrix{
    int *A;
    int n;
};

void diagonalSet(struct Matrix *arr1, int i, int j, int x){
    if (i == j)
        arr1->A[i - 1] = x;
}

int diagonalGet(struct Matrix arr1, int i, int j){
    if (i == j)
        return arr1.A[i - 1];
    else
        return 0;
}

void diagonalDisplay(struct Matrix *arr1){
    for(int i = 1; i < arr1->n + 1; ++i){
        for(int j = 1; j < arr1->n + 1; ++j){
            if (i == j)
                cout << arr1->A[i - 1];
            else
                cout << 0;
        }
        cout << endl;
    }
}

void lowerRowSet(struct Matrix *arr1, int i, int j, int x){
    if (i >= j)
        arr1->A[i * (i - 1)/2 + j - 1] = x;
}

int lowerRowGet(struct Matrix arr1, int i, int j){
    if (i >= j)
        return arr1.A[i * (i - 1)/2 + j - 1];
    else
        return 0;
}

void lowerRowDisplay(struct Matrix *arr1){
    for(int i = 1; i < arr1->n + 1; ++i){
        for(int j = 1; j < arr1->n + 1; ++j){
            if (i >= j)
                cout << arr1->A[i * (i - 1)/2 + j - 1];
            else
                cout << 0;
        }
        cout << endl;
    }
}

void upperRowSet(struct Matrix *arr1, int i, int j, int x){
    if (i <= j)
        arr1->A[arr1->n * i - (i - 2) * (i - 1)/2 + j - i] = x;
}

int upperRowGet(struct Matrix arr1, int i, int j){
    if (i <= j)
        return arr1.A[arr1.n * i - (i - 2) * (i - 1)/2 + j - i];
    else
        return 0;
}

void upperRowDisplay(struct Matrix *arr1){
    for(int i = 1; i < arr1->n + 1; i++){
        for (int j = 1; j < arr1->n + 1; j++){
            if (i <= j)
                cout << arr1->A[arr1->n * i - (i - 2) * (i - 1)/2 + j - i];
            else
                cout << 0;
        }
        cout << endl;
    }
}

void upperColSet(struct Matrix *arr1, int i, int j, int x){
    if (i <= j)
        arr1->A[j * (j - 1)/2 + i - 1] = x;
}

int upperColGet(struct Matrix arr1, int i, int j){
    if (i <= j)
        return arr1.A[j * (j - 1)/2 + i - 1];
    else
        return 0;
}

void upperColDisplay(struct Matrix *arr1){
    for(int i = 1; i < arr1->n + 1; i++){
        for(int j = 1; j < arr1->n + 1; j++){
            if (i <= j)
                cout << arr1->A[j * (j - 1)/2 + i - 1];
            else
                cout << 0;
        }
        cout << endl;
    }
}

void triSet(struct Matrix *arr1, int i, int j, int x){
    if (i - j == 1)
        arr1->A[i - 1] = x;
    else if (i - j == 0)
        arr1->A[arr1->n - 1 + i - 1] = x;
    else if (i - j == -1)
        arr1->A[2 * arr1->n - 1 + i - 1] = x;
}

int triGet(struct Matrix arr1, int i, int j){
    if (i - j == 1)
        return arr1.A[i - 1];
    else if (i - j == 0)
        return arr1.A[arr1.n - 1 + i - 1];
    else if (i - j == -1)
        return arr1.A[2 * arr1.n - 1 + i - 1];
    else
        return 0;
}

void triDisplay(struct Matrix *arr1){
    for(int i = 1; i < arr1->n + 1; i++){
        for(int j = 1; j < arr1->n + 1; j++){
            if (i - j == 1)
                cout << arr1->A[i - 1];
            else if (i - j == 0)
                cout << arr1->A[arr1->n - 1 + i - 1];
            else if (i - j == -1)
                cout << arr1->A[2 * arr1->n - 1 + i - 1];
            else
                cout << 0;
        }
        cout << endl;
    }
}

void toeplitzSet(struct Matrix *arr1, int i, int j, int x){
    if (i == j)
        arr1->A[0] = x;
    else if (i < j)
        arr1->A[j - i] = x;
    else if (i > j)
        arr1->A[arr1->n + i - j - 1] = x;
}

int toeplitzGet(struct Matrix arr1, int i, int j){
    if (i == j)
        return arr1.A[0];
    else if (i < j)
        return arr1.A[j - i];
    else if (i > j)
        return arr1.A[arr1.n + i - j - 1];
    else
        return 0;
}

void toeplitzDisplay(struct Matrix *arr1){
    for(int i = 1; i < arr1->n + 1; i++){
        for(int j = 1; j < arr1->n + 1; j++){
            if (i == j)
                cout << arr1->A[0];
            else if (i < j)
                cout << arr1->A[j - i];
            else if (i > j)
                cout << arr1->A[arr1->n + i - j - 1];
            else
                cout << 0;
        }
        cout << endl;
    }
}

int main() {
    
    Matrix arr1;
    arr1.n = 5;
    arr1.A = new int[arr1.n * (arr1.n + 1)/2];
    
    // Row
    toeplitzSet(&arr1, 1, 1, 2);
    toeplitzSet(&arr1, 1, 2, 3);
    toeplitzSet(&arr1, 1, 3, 4);
    toeplitzSet(&arr1, 1, 4, 5);
    toeplitzSet(&arr1, 1, 5, 6);
    // Col
    toeplitzSet(&arr1, 2, 1, 7);
    toeplitzSet(&arr1, 3, 1, 8);
    toeplitzSet(&arr1, 4, 1, 9);
    toeplitzSet(&arr1, 5, 1, 10);
    
    cout << toeplitzGet(arr1, 4, 1) << endl;
    
    toeplitzDisplay(&arr1);
    
    return 0;
}
