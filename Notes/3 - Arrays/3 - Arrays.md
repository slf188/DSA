# 3 - Arrays

### **What is an array**

- An array is a collection of similar data elements grouped under one name.
- Arrays are vector variables (e.g. all elements inside an array are under the name of the array) unlike scalar variables that hold one value at a time.
- We can differentiate the elements of the array with their indices.
- Check for more info at [C++ Arrays](https://www.programiz.com/cpp-programming/arrays).

### **Declarations of an array**

- The available methods of declaration of an array are as follows:
    - int A[5];
        - This will allocate memory space for 5 integers.
        - The 5 elements hold garbage values because they haven’t been initialized.
    - int A[5] = {2, 4, 6, 8, 10};
        - The array will be created during runtime and all values will be initialized.
    - int A[5] = {2, 4};
        - If we don’t initialize all the values then an array of the provided size will be created with the initialized values and the remaining elements will be initialized with zero.
        - Once the initialization process starts it will initialize all the elements.
    - int A= {2, 4, 6, 8, 10};
        - Depending on the number of elements initialized, the array size will be the same as the initialization list.
- The available methods of accessing an array are as follows: int A[5] = {2, 5, 4, 9, 8};
    - A[0]
        - This will return the element at position 0.
    - for (int i = 0; i < 5; i++) { cout << A[i]; }
        - This will go through the entire array.
    - 0[A]
        - This will return the element at position 0.
    - (A + 3)
        - Using pointers will return the fourth element in the array.

## **Static vs Dynamic Array**

### **Static**

- A static array means the size of the array is static, and the size of a dynamic array is dynamic.
- A vector variable array created inside the main memory will always be located inside the stack.
- The size of an array can be decided at runtime in C++, but only at compile time in C.

```cpp
int main() {
    // This B array will be located inside the stack
    int n;
    cin >> n;
    int A[n];
    cout << "The size of the array is " << sizeof(A) << endl;
    return 0;
}
```

### Dynamic

- For accessing anything inside the heap we must have a pointer.
- We get memory in heap only when we say **new** otherwise all other data will be placed inside the stack.
- If memory is not required we must delete it, because if we don’t we may face a memory leak.

```cpp
int main() {
    // This array wil be in stack
    int A[5];
    // This array will be in heap
    int *P;
    P = new int[5];
    // Initializing arrays in stack and heap is the same:
    A[0] = 5;
    P[0] = 5;
    // When memory is no longer required we say:
    delete P;
    return 0;
}
```

### **How to increase the size of an array**

- Once an array is created, its size cannot be modified. This applies to static arrays and dynamic arrays.
- We can increase its size by creating another larger-sized array and assigning the values of the first array to the second larger array.
- After assigning the values to the second array we must delete the first array, and then make the first array point to the second array.
- Then we can remove the second array so the first array remains.

```cpp
int main() {
    // Size 5 array created in heap:
    int *p = new int[5];
    p[0] = 5;
    p[1] = 8;
    p[2] = 9;
    p[3] = 6;
    p[4] = 4;
    // To increase size do the following steps:
    // 1 - Create a larger-sized array in heap:
    int *q = new int[10];
    // 2 - Assign the values of the first array to the second array:
    for (int i = 0; i < 5; i++) {
        q[i] = p[i];
    }
    // 3 - Delete the first array:
    delete []p;
    // 4 - Let the first array point to the second array:
    p = q;
    // 5 - Remove the second array so that the first array remains:
    q = NULL;
    return 0;
}
```

### **2D Arrays**

- Multidimensional arrays are possible.
- 2D arrays are mostly used for implementing matrices or for tabular data.
- There are 3 methods of creating 2D arrays:
    - int A[3][4];
        - Memory will be allocated like a single dimension array with 12 integers.
        - Declaration and initialization is possible by adding {{1, 2, 3, 4}, {2, 4, 6, 8}, {3, 5, 7, 9}};
        - To assign and retrieve values we can say A[1][2] = 15;
        
        ![Untitled](3%20-%20Arrays%2049cef/Untitled.png)
        
        - int *A[3];
            - In each of the 3 elements, we can create 3 arrays of size 4. So each pointer points to the array of 4 elements (e.g. A[0] = new int[4], A[1] = new int[4], A[2] = new int[4];
            - We can assign and retrieve values the same way as the previous method.
        - int **A;
            - We can use double pointers, and then create columns and rows in heap (e.g. A = new int*[3]; A[0] = new int[4], A[1] = new int[4], A[2] = new int[4];).
- We can access all the elements of 2D arrays by using a for a loop.

```cpp
int main() {
    int A[3][4] = {{1, 2, 3, 4}, {2, 9, 6, 8}, {3, 5, 7, 9}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << A[i][j] << " ";
        }
    }
    return 0;
}

» 1 2 3 4 2 9 6 8 3 5 7 9
```

### **Array representation by the compiler**

- Once we’ve defined an array, during execution time memory will be allocated for the array and the values will be stored in corresponding locations.
- The compiler needs the address of a location, acknowledge that any location of an array can be accessed with the help of visitors.
- The formula for finding elements in an array is: Address[i]=Lo+i+w
    - **Lo: Base address**
    - **i: Index**
    - **w: Size of DataType**
    - This reads as follows, from the base location of an array I want to access i index where each index takes w bytes.

### **2D array representation by the compiler**

- For 2D arrays, we can access every element by providing a row and column number.
- There are two ways 2D arrays are stored in a single-dimensional array:
    - **Row-major Mapping**
        - Elements are stored row by row, starting from top to bottom.
        - The formula for finding elements in this case is
        
        $$
        Address(A[i][j]) = Lo+[i+n+j]*w
        $$
        
        - **Lo: Base address**
        - **i: Index**
        - **n: Number of columns**
        - **j: Index j**
        - **w: Size of datatype**
        
        ![Untitled](3%20-%20Arrays%2049cef/Untitled%201.png)
        
        - **Column-major Mapping**
            - Opposite to **Row-major mapping**, the elements of a 2D array will be mapped on a single dimension array column by column.
            - The formula for finding elements in this case is: Address(A[i][j]=Lo+[j*m+i]*w
            - **Lo: Base address**
            - **i: Index**
            - **n: Number of rows**
            - **j: Index j**
            - **w: Size of datatype**
            
            ![Untitled](3%20-%20Arrays%2049cef/Untitled%202.png)
            
    
    ### **Formulas for nD arrays**
    
    - To prepare a formula for n numbers of arrays we can frame it by splitting it into 2 parts.
    - **Row-major**
        - Row major is done from left to right.
        - The formula is $Address(A[i1][i2][i3][i4])=Lo+[i1*d2*d3*d4+i2*d3*d4+i3*d4+i4]*w$
        - The general formula is $Address(A[n])=Lo+p=1n[ip*nq=p+1dq]*w$
    - **Col-major**
        - Col major is done from right to left.
        - The formula is $Address(A[i1][i2][i3][i4])=Lo+[i4*d1*d2*d3+i3*d1*d2+i2*d1+i1]*w$
    
    **Formulas for 3D Arrays**
    
    Let’s split this into two parts
    
    - **Row-major**
        - int A[l][m][n];
        
        $Address(A[i][j][k])=Lo+[i*m*n+j*n+k]$
        
    - **Col-major**
        
        $Address(A[i][j][k])=Lo+[k*l*m+j*m+i]$
        

[3.5 - Array ADT](https://www.notion.so/3-5-Array-ADT-fd4328ac01b546cf9f1f105db43fe564)