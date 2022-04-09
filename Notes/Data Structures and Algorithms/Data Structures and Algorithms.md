# Data Structures and Algorithms

### What topics will be reviewed in DSA?

The topics we will review are as follows:

- Arrays
- Matrices
- Linked List
- Stack
- Queues
- Trees
- Graphs
- Hashing
- Recursion
- Sorting

### What level of expertise is required for an IT job with regards to DSA?

Let’s picture this in three levels of expertise:

- **First Level**
    - You know what Data Structures are, how they work, and where to use them.
- **Second Level**
    - You know how they work in detail, and you are able to do the analysis based on the time and space complexities.
- **Third Level**
    - You know DS in detail, you know how to develop your own DS, and you know how to code them.

### What are Data Structures?

- Data is an integral part of our programs.
- A program is nothing but a set of instructions that performs operations on data to get some results.
- Arrangement of collection of data items that can be utilized to generate efficient programs.
- Without DS there cannot be any application.
- Depending on the requirement of the program, the type of procedures it is performing, we have various data structures, so depending on the requirement we can choose a suitable data structure.
- Every application will have a set of instructions that will perform operations on data, so data is mandatory. This means data is kept inside the main memory during the execution of a program.

### How do Data Structures work graphically?

- There are three parts inside a computer that we should look closely at:
    - CPU
        - Executes programs.
    - RAM
        - Temporary memory.
    - HDD Storage
        - Permanent Storage.
        - Where pc or mobile applications get stored.
        - Where our photos, videos, data get stored in our PCs or phones.
- Whenever we want to use an application we first tap into HDD Storage, the program will be brought to RAM where the instructions of our desired program will execute, then the CPU will start executing the application from RAM so then we’ll see a window appearing on the screen and then we can start using the application.
- This explains why every application deals with data, and that data is inside the main memory.
- **The arrangement or organizing of the data inside the main memory for efficient utilization by the application. This arrangement is called Data Structure.**

## Stack & Heap Memory

### What is Main Memory?

- Memory is divided into small addressable units called bytes.
- Every single byte has its own address. Each address has a single value.

### How does a program use memory?

- A program uses the main memory by dividing it into three sections
    - Heap
        - Outside the program. Although it can be accessed with Pointers.
        - Heap means piling up.
        - Heap means two different things. One where there are organized things and the other where things are unorganized. In the case of memory, we are talking about unorganized memory.
        - Heap memory is unorganized.
        - Heap memory should be used as a resource, when required we take the memory, and when we don’t require it we release it.
        - Dynamic Allocation of memory is applied here.
    - Stack
        - Where all created variables inside the Code Section are located.
        - Memory is allocated inside the stack, and it is automatically created, and automatically destroyed when the function ends.
        - Static Allocation is utilized here.
        - Stack memory is organized.
    - Code Section
        - Where all our code resides.
        - Our code can only access this and the Stack section.

![Untitled](Data%20Struc%20e6379/Untitled.png)

- Acknowledge that the number of bytes taken depends on the compiler, OS, and hardware.

## Physical vs Logical DS

### Physical DS

- There are two physical data structures, we can have more by combining both.
- They are Physical because they decide or define how memory is organized, and allocated.
1. **Array**
    1. Directly supported by programming languages.
    2. A collection of contiguous memory locations, all locations are side by side.
    3. It has a fixed or static size (e.g. once created of some size then that size cannot be increased or decreased).
    4. It can be created inside a stack or inside a heap.
    5. This DS should only be used when we know the maximum number of elements that we are going to store.
    
    ![Untitled](Data%20Struc%20e6379/Untitled%201.png)
    
2. **Linked List**
    1. Dynamic DS
    2. Collection of nodes, where each node contains data and is linked to the next node.
    3. The length of this list can grow and reduce, dynamically.
    4. This Linked List is always created in heap.
    5. This DS should be only used when the size of the list is not known.
    
    ![Untitled](Data%20Struc%20e6379/Untitled%202.png)
    

### Logical DS

- They define how data can be utilized.
- Logical Data Structures are implemented using any of the 2 Physical Data Structures.
- They consist and are separated into three different groups:
    - Linear
        - Stack
            - Works on LIFO discipline. Last in First Out.
        - Queues
            - Works on FIFO discipline. First in First Out.
    - Non-Linear
        - Trees
            - Works like a hierarchy.
        - Graph
    - Tabular
        - Hash Table

## Abstract Data Type

### What is a ADT?

- Let’s split this term into two parts Abstract and Datatype.
- The meaning of ADT is related to OOP languages. Because with them we can use classes to define our own data types, that are abstract.
- Abstract means hiding internal details (e.g. for performing any operators on data, we don’t know the internal details on how these operations are performed).
- By Datatype we define two terms:
    - Representation of data (e.g. how we store data)
    - Operations on data (e.g. what operations we allow on the data)

Let’s take an example:

- We have a list:
    - List -> 8, 3, 9, 4, 6, 10, 12
- The data required for this list is:
    - Space for storing elements
    - The capacity of a list (e.g. maximum capacity)
    - Size of a list (e.g. number of elements)
- Operations allowed on this list:
    - add(x)
    - remove(x)
    - search(x)
- So we can represent this list taking into consideration data and operation:
    - Array
    - Linked List
- So in conclusion the List -> 8, 3, 9, 4, 6, 10, 12 is an abstract data type, it holds the representation of data, and the operations on data.
- So when we have the 2 things, data representation and operations on the data together it becomes a datatype.
- We can put all this together and define a C++ class. We can represent this either with an Array and a Linked List, whatever is used it will work perfectly.

## Time and space complexity

### Time complexity

- In daily life, we measure the time based on the work that we have to do. If we want to know how much does a machine take to do a particular task we can take in consideration the fact that computers are used for performing computation task, so we measure time.
- Time complexity tries to measure the amount of time it takes for a computer to complete a task based on the procedure the computer is adopting.

Let’s take an example:

- We have an array A = [2, 5, 9, 6, 4, 12, 8, 3, 7].
- If we don’t know how many elements are inside this array, we say this array has **n** elements.
- If we want to make operations say finding a certain element, or adding the elements inside this array, and see the time taken to complete the task we say n time.
- So this n we can represent it as a degree. So we can say **Order(n) - o(n)**. To go through all the elements in this array we can use a for loop:

```cpp
for (int i; i < n; i++){
	// code...
}
```

- And when dealing with $o(n²)$ we can write code like:

```cpp
for (int i = 0; i < n; i++) {
    for (int i + 1; j < n; j++) {
       // code...
    }
}
```

- Measuring Time Complexity differs on DS, if we have a matrix then we would search column and row which equals c * r so it’s o(n2) to search through all the elements inside the matrix. With a linked list we would use Log(first element)n.
- We can calculate time complexity with either a for or a while loop.

### Space complexity

- Used to measure how much space is consumed in the main memory during the execution of a program.
- We don’t take into consideration the number of bytes used. We want to know the space is dependent on what, how many elements. If the value of n is more, the space will be more.

### Time and space complexity in code

- When finding time complexity when analyzing code we will get a time function.
- Every simple statement in a function takes one unit of time.
- By a simple statement, we mean having arithmetic operations, assignments, or conditional statements.
- Anything inside a loop will execute for **n** times.

To measure both we do the following:

```cpp
void swap(int x, int y) {
    int t;
    // Each of the following statements take 1 unit of time
    t = x; // --> 1
    x = y; // --> 1
    y = t; // --> 1
    // The total time is 3
    // So time function will be: f(n) = 3 * n°
    // o(1)
    // o(n°) = o(1)
}
```

As a second example:

```cpp
int sum(int A[], int n) {
    int s, i;
    s = 0; // --> 1
    // The for loop will get executed for n times:
    // Assignment 1, Condition n + 1, Operator n
    for (i = 0; i < n; i++) { // We can ignore the other two and say n + 1
        s = s + A[i]; // --> n times loop will run
    }
    return s; // --> 1
    // The time function will be: f(n) = 2n + 3
    // o(n)
}
```

### Topics:

[1 - Essential C++ Concepts](https://www.notion.so/1-Essential-C-Concepts-c1e70b2fd4ec4a2abe67738feb074a0c)

[2 - Recursion](https://www.notion.so/2-Recursion-9cd0f47769a3416fb010ed0adf248b07)

[3 - Arrays](https://www.notion.so/3-Arrays-a8de24dd26fc4e3cb63bc4d428e5e706)

[4 - Strings](https://www.notion.so/4-Strings-45109d46634e44eaba810d5f7def2e92)

[5 - Matrices](https://www.notion.so/5-Matrices-40266bfedca044f2a02ae0d768110a28)

[6 - Sparse Matrix and Polynomial Representation](https://www.notion.so/6-Sparse-Matrix-and-Polynomial-Representation-0d540bb7df6b4eb2a2ae28af1ed1b245)

[7 - Linked Lists](https://www.notion.so/7-Linked-Lists-6f089e59ea7944f888545b1d55aec610)

[8 - Stack](https://www.notion.so/8-Stack-585d94b273174445be70c95104856f6b)

[9 - Queue](https://www.notion.so/9-Queue-72ee4687dcf94f0aa0291922111c7e44)

[10 - Trees](https://www.notion.so/10-Trees-b849adc42d8e423fb31794218039d8b7)

[11 - Binary Search Trees](https://www.notion.so/11-Binary-Search-Trees-0e9ae7186a7940dcad8979715088f1b5)

[12 - AVL Trees](https://www.notion.so/12-AVL-Trees-0ce0febc903442269274c8c4cd904b2b)

[13 - Search Trees](https://www.notion.so/13-Search-Trees-036d61e41cbc4e6d8d82700b9eae541c)

[14 - Heap](https://www.notion.so/14-Heap-0cd6477066db42dcb3630aac58629b43)

[15 - Sorting Techniques](https://www.notion.so/15-Sorting-Techniques-6cb8390644ab4d5592ba7b5633e8a95b)

[16 - Hashing Technique](https://www.notion.so/16-Hashing-Technique-5091622cc61741c583de797eee3f2f78)

[17 - Graphs](https://www.notion.so/17-Graphs-736921a74f6e425f8dfce160c7e468e9)

[18 - Asymptotic Notations](https://www.notion.so/18-Asymptotic-Notations-ce7b8b5eefbb4f74a6eb5bff8a0246c0)