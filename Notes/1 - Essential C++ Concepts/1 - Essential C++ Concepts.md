# 1 - Essential C++ Concepts

### What are the essential concepts we will review?

1. Arrays
2. Structure
3. Pointers
4. Reference
5. Parameters Passing
6. Classes
7. Constructor
8. Templates

### Arrays

- We can group a collection of similar data elements under one name as an array.
- We must specify the data type the array will hold, a name, and the size of the array.
- We can access all the elements inside the array by an integer value.

Declaration and initialization of an array:

```cpp
int main() {
    int A[5] = {2, 4, 6, 8, 10};
		cout << "The second element inside the array is: " << A[1] << endl;
    return 0;    
}

» The second element inside the array is: 4
```

### Structures

- Collection of dissimilar data items under one name.
- Structures are used for defining user-defined data types.
- The definition of a structure doesn’t consume memory unless it is declared.

```cpp
struct Car {
    int seats;
    char model;
};

int main() {
    Car tesla;
    tesla.seats = 8;
    tesla.model = 'S';
    cout << "We have a Tesla model " << tesla.model << endl;
    cout << "Our Tesla has " << tesla.seats << " seats" << endl;
    return 0;
}

» We have a Tesla model S
Our Tesla has 8 seats
```

### What is memory padding?

C++ data types hold the following sizes:

![Screen Shot 2021-09-30 at 17.15.30.png](1%20-%20Essent%2008eec/Screen_Shot_2021-09-30_at_17.15.30.png)

Let’s see the number of bytes inside our previous C++ Structure program:

```cpp
int main() {
    Car tesla;
    cout << "The size of this structure is " << sizeof(tesla) << endl;
    return 0;
}

» The size of this structure is 8
```

But why? We have two properties, one int, and one char. It should be 5.

- This is called Padding Memory.
- Compilers nowadays count ints as 4 bytes.
- It is easy for a computer to read the biggest number. So when reading a smaller data type it will try to round it so it adjusts the same size as the bigger data type.
- The actual size is 5 bytes, but it will take 4 extra bytes so it is easier for the computer to read the internal structure at once.

### Pointers

- Pointers are also known as address variables.
- They indirectly access the data.
- They are meant for storing the address of data.
- Useful for accessing Heap memory.
- Every pointer takes the same amount of memory no matter what data type it holds.
- Useful for accessing resources that are outside the program.

```cpp
int main() {
    int a = 10;
    int *p;
    p = &a;
    cout << "The value of a is: " << a << endl;
    cout << "The address of a is: " << &a << endl;
    cout << "The address of p is: " << p << endl;
    cout << "The value of p is: " << *p << endl;
    return 0;
}

» The value of a is: 10
The address of a is: 0x16fdff428
The address of p is: 0x16fdff428
The value of p is: 10
```

To create a new variable inside Heap we can do the following:

```cpp
int main() {
    int *p;
    // The new operator allocates memory to a variable.
    p = new int;
    *p = 88;
    cout << "The value inside Heap variable is " << *p << endl;
    // Once we no longer need to use a variable that we have declared
    // dynamically, we can deallocate the memory occupied by the variable.
    delete p;
    return 0;
}

» The value inside Heap variable is 88
```

[C++ Memory Management: new and delete](https://www.programiz.com/cpp-programming/memory-management)

### How does the Main Memory or RAM of a computer look like?

![Untitled](1%20-%20Essent%2008eec/Untitled.png)

- The memory is separated into 3 parts
    - Heap
        - Outside the program. Although it can be accessed with Pointers.
    - Stack
        - Where all created variables inside the Code Section are located.
    - Code Section
        - Where all our code resides.
        - Our code can only access this and the Stack section.

### Reference

- It’s a nickname or an alias given to a variable.
- For pointers, we use the * symbol, and & for a reference.

```cpp
int main() {
    int a = 10;
    int &r = a;
    cout << "The initial values of r " << r << " and a is " << a << endl;
    r++;
    cout << "The current values of r " << r << " and a is " << a << endl;
    return 0;
}

» The initial values of r 10 and a is 10
The current values of r 11 and a is 11
```

### Pointer to Structure

- The way to access properties inside a structure with pointers is different compared to the standard method.

```cpp
struct Rectangle {
    int lenght;
    int width;
};

int main() {
    Rectangle r = {10, 5};
    Rectangle *p = &r;
    cout << r.lenght << endl;
    // This is how we access properties in a struct with a pointer:
    // We can access them also by: (*p).lenght = 20
    p -> lenght = 20;
    cout << r.lenght << endl;
    return 0;
}

» 10
20
```

### Functions

- Functions are a piece of code that performs a specific task.
- By using functions we can break the main program into small manageable size pieces and we can separate the repeating tasks.
- Please take a look at the following resources for [C++ Functions](https://www.programiz.com/cpp-programming/function).
- When we use functions we are employing Modular Programming or Procedural Programming.
- The same functions can be used in other software projects also, so we can group together the functions inside a library.

```cpp

int add(int a, int b) {
    int c;
    c = a + b;
    return c;
}

int main() {
    cout << add(8, 8) << endl;
    return 0;
}

» 16
```

### Array as a parameter

```cpp
void fun(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }
}

int main() {
    int A[5] = {2, 4, 6, 8, 10};
    fun(A, 5);
    return 0;
}

» 2
4
6
8
10
```

### Structure as a parameter

```cpp
struct Rectangle {
    int lenght;
    int width;
};

int area(Rectangle r){
    return r.lenght * r.width;
}

int main() {
    Rectangle size = {10, 5};
    cout << "The area of our rectangle is " << area(size) << endl;
    return 0;
}

» The area of our rectangle is 50
```

### Classes

- A class is a blueprint for the object.
- We can think of it as a sketch (prototype) of a house. It contains all the details about the floors, doors, windows, etc. Based on these descriptions we build the house. House is the object.
- Please check the resources on C++ [Classes and Objects](https://www.programiz.com/cpp-programming/object-class).
- When using Classes and Objects we are employing OOP.
- The rule for C++ OOP states there should be a .h file declaring the parts of the class and a .cpp file used for defining the methods inside of a class.
- By default, every item inside a class is set to private so we must specify which parts are public and which ones are private.
- Every class should have a constructor because it’s a good programming practice. We should set default values like 0.
- Every class should have setters and getters.
- When compiling we do not need to specify the .h file. (e.g. g++ main.cpp Rectangle.cpp).

**Rectangle.h**

```cpp
class Rectangle {
    private:
        int lenght;
        int width;
    public:
        // Constructor:
        Rectangle ();
        Rectangle (int l, int w);
        int area();
        void setLenght(int l);
        int getLength();
        void setWidth(int w);
        int getWidth();  
};
```

**Rectangle.cpp**

```cpp
#include "Rectangle.h"

Rectangle::Rectangle() {
    lenght = 0;
    width = 0;
}

Rectangle::Rectangle(int l, int w) {
    lenght = l;
    width = w;
}

int Rectangle::area() {
    return lenght * width;
}

void Rectangle::setLenght(int l) {
    lenght = l;
}

int Rectangle::getLength() {
    return lenght;
}

void Rectangle::setWidth(int w) {
    width = w;
}

int Rectangle::getWidth() {
    return width;
}
```

**main.cpp**

```cpp
#include "Rectangle.h"

int main() {
    Rectangle r(10, 5);
    cout << "The area of our Rectangle is " << r.area() << endl;
    return 0;
}

» The area of our rectangle is 50
```

### Template Classes

- Let’s start off with a question. Should we write two different functions or classes for a different data type? No, C++ allows us to use the same class of functions for multiple data types with **Templates**.
- When using Template the suggestion is first writing the class supporting one data type, then converting it into a template.
- Before adding the T of the template we should check what data type we want to add a template to.
- Please check the following resource on [C++ Templates](https://www.programiz.com/cpp-programming/templates)

**Rectangle.h**

```cpp
template <class T>
class Rectangle {
    private:
        T lenght;
        T width;
    public:
        // Constructor:
        Rectangle ();
        Rectangle (T l, T w);
        T area();
        void setLenght(T l);
        T getLength();
        void setWidth(T w);
        T getWidth();
};
```

**Rectangle.cpp**

```cpp
#include "Rectangle.hpp"

template <class T>
Rectangle<T>::Rectangle() {
    lenght = 0;
    width = 0;
}

template <class T>
Rectangle<T>::Rectangle(T l, T w) {
    lenght = l;
    width = w;
}

template <class T>
T Rectangle<T>::area() {
    return lenght * width;
}

template <class T>
void Rectangle<T>::setLenght(T l) {
    lenght = l;
}

template <class T>
T Rectangle<T>::getLength() {
    return lenght;
}

template <class T>
void Rectangle<T>::setWidth(T w) {
    width = w;
}

template <class T>
T Rectangle<T>::getWidth() {
    return width;
}
```

**main.cpp**

```cpp
#include "Rectangle.hpp"

int main() {
    Rectangle<int> ri(10, 5);
    Rectangle<float> rf(10.5, 5.8);
    cout << "The area of our rectangle is " << ri.area() << endl;
    cout << "The area of our rectangle is " << rf.area() << endl;
    return 0;
}

» The area of our rectangle is 50
The area of our rectangle is 60.9
```