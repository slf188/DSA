# 5 - Matrices

### **What are special matrices?**

- Special Matrices are square matrixes, that is their dimension is row*column
- These matrices have more than zero elements.

### **What type of matrices are there?**

1. Diagonal Matrix
2. Lower Triangular Matrix
3. Upper Triangular Matrix
4. Symmetric Matrix
5. Tridiagonal Matrix
6. Band Matrix
7. Toeplitz Matrix
8. Sparse Matrix

### **Diagonal Matrix**

![Untitled](5%20-%20Matric%20198a0/Untitled.png)

- Most of the numbers inside a diagonal matrix are zeros.
- Only the elements in the diagonal are non-zero numbers.
- In a matrix where other than the diagonal, all elements must be zero, then only we can say that a matrix is diagonal.

```cpp
struct Matrix{
    int A[10];
    int n;
};

void set(struct Matrix *arr1, int i, int j, int x){
    if (i == j)
        arr1->A[i - 1] = x;
}

int get(struct Matrix arr1, int i, int j){
    if (i == j)
        return arr1.A[i - 1];
    else
        return 0;
}

void display(struct Matrix *arr1){
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

int main() {
    Matrix arr1;
    arr1.n = 5;
    set(&arr1, 1, 1, 3);
    set(&arr1, 2, 2, 7);
    set(&arr1, 3, 3, 4);
    set(&arr1, 4, 4, 9);
    set(&arr1, 5, 5, 6);
    cout << get(arr1, 2, 2) << endl;
    display(&arr1);
    return 0;
}
» 7
30000
07000
00400
00090
00006
```

### **Lower Triangular Matrix | Row - Major Mapping**

- A lower triangular matrix is a square matrix in which the lower triangular part of the matrix is non-zero elements, and the upper triangular part is all 0s.

![Untitled](5%20-%20Matric%20198a0/Untitled%201.png)

- We notice that non-zero happens when i >= j, and 0 happens when i < j.
- By Row-Major Mapping, we mean how we store and retrieve the elements inside the matrix, below we’ve sketched how it’s done and what’s the formula.

![Untitled](5%20-%20Matric%20198a0/Untitled%202.png)

### **Lower Triangular Matrix | Column - Major Mapping**

- The way we store and retrieve the elements for column-major mapping is somewhat similar to row-major mapping.

![Untitled](5%20-%20Matric%20198a0/Untitled%203.png)

```cpp
void lowerRowSet(struct Matrix *arr1, int i, int j, int x){
    if (i >= j)
        // By changing the formula we can get lowerColSet
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

int main() {
    Matrix arr1;
    arr1.n = 5;
    arr1.A = new int[arr1.n*(arr1.n+1)/2];
    lowerRowSet(&arr1, 1, 1, 1);
    lowerRowSet(&arr1, 2, 1, 1);
    lowerRowSet(&arr1, 2, 2, 2);
    lowerRowSet(&arr1, 3, 1, 1);
    lowerRowSet(&arr1, 3, 2, 2);
    lowerRowSet(&arr1, 3, 3, 3);
    lowerRowSet(&arr1, 4, 1, 1);
    lowerRowSet(&arr1, 4, 2, 2);
    lowerRowSet(&arr1, 4, 3, 3);
    lowerRowSet(&arr1, 4, 4, 4);
    lowerRowSet(&arr1, 5, 1, 1);
    lowerRowSet(&arr1, 5, 2, 2);
    lowerRowSet(&arr1, 5, 3, 3);
    lowerRowSet(&arr1, 5, 4, 4);
    lowerRowSet(&arr1, 5, 5, 5);
    cout << lowerRowGet(arr1, 2, 3) << endl;
    cout << lowerRowGet(arr1, 3, 3) << endl;
    lowerRowDisplay(&arr1);
    return 0;
}

» 0
3
10000
12000
12300
12340
12345
```

### **Upper Triangular Matrix | Row - Major Mapping**

- An upper triangular matrix is the opposite of a lower triangular matrix i.e. non-zero elements are in the upper triangular part of this matrix.
- So when i <= j elements are non-zeros, and 0 when i > j.

```cpp
cout << upperRowGet(arr1, 3, 4) << endl;
    upperRowDisplay(&arr1);
    return 0;
}

» 4
12345
02345
00345
00045
00005
```

### Upper Triangular Matrix | Column - Major Mapping

```cpp
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

int main() {
    Matrix arr1;
    arr1.n = 5;
    arr1.A = new int[arr1.n * (arr1.n + 1)/2];
    // Col 1
    upperColSet(&arr1, 1, 1, 1);
    // Col 2
    upperColSet(&arr1, 1, 2, 2);
    upperColSet(&arr1, 2, 2, 2);
    // Col 3
    upperColSet(&arr1, 1, 3, 3);
    upperColSet(&arr1, 2, 3, 3);
    upperColSet(&arr1, 3, 3, 3);
    // Col 4
    upperColSet(&arr1, 1, 4, 4);
    upperColSet(&arr1, 2, 4, 4);
    upperColSet(&arr1, 3, 4, 4);
    upperColSet(&arr1, 4, 4, 4);
    // Col 5
    upperColSet(&arr1, 1, 5, 5);
    upperColSet(&arr1, 2, 5, 5);
    upperColSet(&arr1, 3, 5, 5);
    upperColSet(&arr1, 4, 5, 5);
    upperColSet(&arr1, 5, 5, 5);
    cout << upperColGet(arr1, 3, 4) << endl;
    upperColDisplay(&arr1);
    return 0;
}

» 4
12345
02345
00345
00045
00005
```

### Symmetric Matrix

- A symmetric matrix is a matrix where the elements at location i, j are equal to an element at location j, i.
- So the condition is M[i, j] = M[j, i].
- This means we don’t have to store all the elements of a symmetric matrix i.e. if I know an element at i, j then I know the element at j, i.
- We can store either a lower or upper triangular part.

![Untitled](5%20-%20Matric%20198a0/Untitled%204.png)

### Tridiagonal Matrix

![Untitled](5%20-%20Matric%20198a0/Untitled%205.png)

- A tridiagonal matrix contains non-zero elements at the main diagonal, lower diagonal, and upper diagonal.
- The rule goes as main diagonal are i - j = 0, in lower diagonal are i - j = 1, and upper diagonal i - j = -1.
- The formulas for mapping are as follows:
    - Case 1 - if i - j = 1: index = i - 1
    - Case 2 - if i - j = 0: index = n - 1 + i - 1
    - Case 3 - if i - j = -1: index = 2n - 1 + i - 1

### **Square Band Matrix**

- Similar to Tridiagonal Matrix, but below the main diagonal there is more than one diagonal and the same for the upper case.

![sq.jpeg](5%20-%20Matric%20198a0/sq.jpeg)

### Toeplitz Matrix

![Untitled](5%20-%20Matric%20198a0/Untitled%206.png)

- Toeplitz Matrix has elements that are the same in a diagonal which applies to the main, lower, and upper diagonal.
- The pattern for this type of matrix is M[i, j] = M[i - 1, j - 1].
- Knowing this we conclude it is sufficient to store a row and a column of elements.

![Untitled](5%20-%20Matric%20198a0/Untitled%207.png)

- The formula for mapping is:
    - Case 1: If i < j = j - i
    - Case 2: If i > j = n + i - j - 1
    - Case 3: If i == j = 0

```cpp
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
    
    toeplitzDisplay(&arr1);
    
    return 0;
}

» 
2   3   4   5   6
7   2   3   4   5
8   7   2   3   4
9   8   7   2   3
10  9   8   7   2
```