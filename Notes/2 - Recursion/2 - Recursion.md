# 2 - Recursion

### What is recursion?

The syntax of a recursive function is the following:

```cpp
returnType functionName(parameter) {
    if (condition) {
        // 1.Execute at calling phase...
        // 2.fun(param) and operation at returning phase...;
        // 3.Execute at returning phase...
    }
}
```

- If a function is calling itself, then it is called a recursive function.
- There must be a base condition that will terminate the recursion, otherwise, it will go into the infinite calling of the function.
- A loop will only have ascending phase, but the recursion will have ascending and descending phase.

### Tracing Recursion

- This helps us visualize what happens inside the code, this graph is called the **Tracing Tree of Recursive Function**.
- Recursive functions are traced in the form of a tree.
- Once there is no further calling and the function has terminated it will go back to the previous function and come out of the function and so on until it reaches the initial call.
- Recursion has two phases, the calling phase, and returning phase. Just like a rubber band, if you pull it will stretch, stretch, stretch, and when you release it will come back.

Example 1:

```cpp
void fun1(int n) {
    if (n > 0) {
        cout << n;
        fun1(n - 1);
    }
}

int main() {
    int x = 3;
    fun1(x);
    return 0;
}

» 3 2 1
```

Form of a tree:

![Untitled](2%20-%20Recurs%2008af2/Untitled.png)

Example 2:

```cpp
void fun2(int n) {
    if (n > 0) {
        fun2(n - 1);
        cout << n;
    }
}

int main() {
    int x = 3;
    fun1(x);
    return 0;
}

» 1 2 3
```

Graph:

![Untitled](2%20-%20Recurs%2008af2/Untitled%201.png)

To set both examples as real-life situations let’s picture the following scenario:

![Untitled](2%20-%20Recurs%2008af2/Untitled%202.png)

- There are three rooms, in each room, there is a bulb.
- You are standing in room number 1.

Let’s set two problems:

1. Switch on the bulb.
2. Go to the next room.

The output will be:

1 2 3

1. Go to the next room.
2. Switch on the bulb.

The output will be:

3 2 1

### How recursion uses stack?

- As we previously mentioned, all new variables are created inside the stack. And once we finish using them they get automatically deleted.

Let’s take example number 1:

```cpp
void fun1(int n) {
    if (n > 0) {
        cout << n;
        fun1(n - 1);
    }   
}

int main() {
    int x = 3;
    fun1(x);
    return 0;
}

» 3 2 1
```

The Stack Memory would look something similar to this:

![Untitled](2%20-%20Recurs%2008af2/Untitled%203.png)

- Remember we start adding variables onto the stack starting from main upwards. Activation records are created when the function calls itself again and again.
- The total number of calls is **n+1** and **o(n)** for this example.
- In conclusion, we understood Recursion utilizes the stack, internally it takes extra memory for the stack.

### How to find the time complexity of recursive functions?

- Every statement inside a program takes 1 unit of time for execution.
- Take advantage of code and tree when finding time complexity on recursion.

With that in mind let’s analyze example 1:

```cpp
void fun1(int n) { 
    if (n > 0) { // Conditional takes 1 unit of time
        cout << n; // Print statement takes 1 unit of time
        fun1(n - 1); // Function call takes T(n - 1)
    }  
}
```

So the $T(n)$ of this recursive function is $T(n) = T(n-1) + 2$

### How to see step-by-step recursion code in Xcode?

- Start by setting breaking points when we create variables:
- Then press the F7 key to continue. Make sure Use F1, F2, etc. keys as standard function keys setting is enabled.

### Static and Global Variables in Recursion

- There is a subsection inside the code section called Section for Global and Static Variables.
- Static variables get created only one time (e.g. it will not be created every time a function is called). Meaning it will have a single copy, unlike variables that get new values piled up in the Stack.

Let’s take two examples and see the difference between normal variables and static variables:

Example one:

```cpp
int fun(int n) {
    if (n > 0) {
        return fun(n - 1) + n;
    }
    return 0;
}

int main() {
    int a = 5;
    cout << fun(a) << endl;
    return 0;
}

» 15
```

The tree form for this function is:

![Untitled](2%20-%20Recurs%2008af2/Untitled%204.png)

Example two:

```cpp
int fun(int n) {
    static int x = 0;

    if (n > 0) {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main() {
    int a = 5;
    cout << fun(a) << endl;
    return 0;
}

» 25
```

- We can get the same result if we set x as a global variable outside the function.
- If we call this function two times the first output will be 25 and the second output will be 50.

The tree form of this function is:

![Untitled](2%20-%20Recurs%2008af2/Untitled%205.png)

## Types of recursion

### 1 - Tail recursion

- If a recursive function is calling itself, and that recursive call is the last statement in the function. Then it is called Tail Recursion.
- When all process is done at calling time, then such functions are Tail Recursion.

```cpp
void fun(int n) {
    if (n > 0) {
        // operation...
        fun(n - 1);
    }
}
```

### 2 - Head recursion

- The function doesn’t have to process any operation at the time of call, it has to do everything only at the time of returning.
- When all process is done at returning time, then such functions are Head Recursion.

```cpp
void fun(int n) {
    if (n > 0) {
        fun(n - 1);
        // operation...
    }
}
```

### 3 - Tree recursion

- Before understanding tree recursion let’s tackle Linear Recursion.
- Linear Recursion is a recursive function that it’s calling itself only one time.
- If a Recursive Function is calling itself more than one time. Then it is tree recursion.

Example:

```cpp
void fun(int n) {
    if (n > 0) {
        cout << n;
        fun(n - 1);
        fun(n - 1);        
    }
}

int main() {
    fun(3);
    return 0;
}

» 3 2 1 1 2 1 1
```

Tree form:

![Untitled](2%20-%20Recurs%2008af2/Untitled%206.png)

### 4 - Indirect recursion

- Where there may be more than one function and they are circularly calling one another. That’s what we mean by indirect recursion.

Example: We will round the numbers

```cpp
void funA(int n) {
    if (n > 0) {
        cout << n << endl;
        funB(n - 1);       
    }
}

void funB(int n) {
    if (n > 1) {
        cout << n << endl;
        funA(n/2);       
    }
}

int main() {
    funA(20);
    cout << endl;
    return 0;
}

» 20 19 9 8 4 3 1
```

Tree form:

![Untitled](2%20-%20Recurs%2008af2/Untitled%207.png)

### 5 - Nested recursion

- Where the parameter itself is a recursive call. That’s nested recursion.

```cpp
int fun(int n) {
    if (n > 100)
        return n - 10;
    else
        return fun(fun(n + 11));   
}

int main() {
    cout << fun(98) << endl;
    return 0;
}

» 91
```

Tree form:

![Untitled](2%20-%20Recurs%2008af2/Untitled%208.png)

[2.5 - Recursion examples](https://www.notion.so/2-5-Recursion-examples-6d84805df2b9448ea4719b95e4d48dc2)