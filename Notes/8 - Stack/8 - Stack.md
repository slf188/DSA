# 8 - Stack

### Introduction to stack

- Stack is a data structure which works on the discipline of **LIFO: Last-in First-out**
- Stack is a collection of elements, these collection of elements are inserted and deleted by following the LIFO discipline
- If we want to delete, we can only delete the last element that was inserted, and if we want to insert we can only do so after the last element.
- We cannot take elements from the middle or from the bottom, we must take things out from the top.
- The recursion algorithm uses stack.

### Stack in daily life

**Parking Lot**

- Suppose we have a parking lot where three cars are parked.
- If a car wants to leave the parking lot then the must go out from the same direction they entered.

![Untitled](8%20-%20Stack%20bd29d/Untitled.png)

- The first car that will go out is the white car, and if we want to insert another car it will go after the white color.

**Tennis Balls**

- Imagine we have a can of tennis balls
- The way we insert and take out balls is as follows:

![Untitled](8%20-%20Stack%20bd29d/Untitled%201.png)

- The last ball that was inserted was the blue ball, the one that will go out first is the blue ball

**Fruit Boxes**

- When we want to place boxes containing fruit in a stack form it will look like this

![Untitled](8%20-%20Stack%20bd29d/Untitled%202.png)

### ADT Stack

- ADT will contain data representation and the operations on the stack.
- **Data**
    - Space for storing elements
    - A pointer on the top-most element
- Operations
    1. push(x) - Inserting one value
    2. pop() - Take out the last element inserted in the stack
    3. peek(index) - Looking at a value in a given position, this will retrieve the value in that particular index
    4. stackTop() - Used for knowing which is the top-most value in the stack
    5. isEmpty() - Knowing whether the stack is empty or not, an empty stack is when the top == -1
    6. isFull() - Knowing whether the stack is full or not i.e. all the available indexes are filled, a full stack suits the top == size - 1 condition
- As we see when we make these operations we must be aware that there will be times when we must move the top pointer accordingly to the situation, either we delete the top-most element and move the top pointer down or if we insert a new element and move the pointer up.

### How can we implement a Stack?

- We have two options, we can implement the stack using the structure of an **array** or a **linked list.**

### Stack using Array

- The things required for creating the stack are:
    - Array
    - Variable holding the array size
    - Top pointer to point on the top-most element, initially top should point on minus one, as we go inserting new elements it will be moving upwards.
- Remember inserting new elements in an array is done from the right side, this will avoid making a mistake of inserting elements on the opposite side which will force us to shift all the elements one step to the right. This will take constant time.

![Untitled](8%20-%20Stack%20bd29d/Untitled%203.png)

- When we are saying stack we must picture it in a vertical sense

### Operations using Array

- An empty stack is when the top pointer is -1
- A full stack suits the top == size - 1 condition
- **push**
    - Whenever we insert a new element we should add one on the top value (e.g. top++) and insert on array[top] = x
    - If top reaches  4 in a 5 stack then we can't do top++ anymore, which means we should add a conditon that cheks if the stack is full or not i.e. (top == size - 1)
    - If we reach the 4 in a 5 sized array we cannot
- **pop**
    - Whenever we delete an element then we dicrement top—
    - This function should delete and return the deleted value
    - We should check whether we can delete a value or not but using the (top == -1) condition
    - We should initialize a variable with -1, we assign the value of the last element into x, then decrement top and then return x
    - If the function returns -1 then it means the stack is empty
- **peek**
    - To find an element at a given position we should acknowledge that the element at the first postition is the top pointer, then 2, 3 going downwards
    - The position here starts from the top
    - The formula for getting the indexes is (Index = topValue - position + 1)
- s**tackTop**
    - To know the top-most value in an stack
- **isEmpty and isFull**
    - We must use the previous formulas
    - (top == -1) to check if it is empty
    - (top == size - 1) to check if it is full

```cpp
struct Stack {
    int size;
    int top;
    int *array;
};

void create(Stack *st){
    cout << "Enter the desired size of the stack\n";
    cin >> st->size;
    st->array = new int[st->size];
    st->top = -1;
}

void push(Stack *st, int x){
    if (st->top == st->size - 1)
        cout << "Stack overflow\n";
    else {
        st->top++;
        st->array[st->top] = x;
    }
}

void pop(Stack *st){
    int x = -1;
    if (st->top == -1)
        cout << "Stack underflow\n";
    else{
        x = st->array[st->top];
        st->top--;
    }
    cout << "The deleted value is " << x << endl;
}

void peek(Stack *st, int position){
    int index = -1;
    if (st->top - position + 1 < 0)
        cout << "Invalid position\n";
    else {
        index = st->array[st->top - position + 1];
        printf("The value at %d is %d", position, index);
    }
}

void stackTop(Stack *st){
    if (st->top == -1)
        cout << "Stack underflow\n";
    else
        cout << st->array[st->top] << endl;
}

void isEmpty(Stack *st){
    if (st->top == -1)
        cout << "The stack is empty\n";
    else
        cout << "The stack is not empty\n";
}

void isFull(Stack *st){
    if (st->top == st->size - 1)
        cout << "The stack is full\n";
    else
        cout << "The stack is not full\n";
}

void displayStack(Stack *st){
    cout << "The stack looks as follows:\n";
    for(int i = st->top; i >= 0; i--)
        cout << st->array[i] << endl;
}

int main() {
    Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 15);
    push(&st, 8);
    push(&st, 20);
    displayStack(&st);
    return 0;
}

» Enter the desired size of the stack
5
The stack looks as follows:
20
8
15
10
```

### Stack using Linked List

- A stack can be implemented using a linked list too.
- The side we are going to use for inserting and deleting elements will be the left side, remeber that the last node of a linked list is located on the right side.

![Untitled](8%20-%20Stack%20bd29d/Untitled%204.png)

- To insert a new element, we create a new node on the left side of the top element; with the help of a temporary pointer, insert the value then make it point to the top element and top should then be brought to the new node.

![Untitled](8%20-%20Stack%20bd29d/Untitled%205.png)

- To delete a value, we take a new pointer on the top node, move top to the node on the right side and then delete the node.

![Untitled](8%20-%20Stack%20bd29d/Untitled%206.png)

- We say the stack is empty when there are no nodes. If the top is null then the stack is empty.

```cpp
// Empty
if (top == nullptr)
```

- In an array its size is limited but on the case of a linked list it is unlimited, we say the stack is full when we become unable to create a new node, which also means the heap is full.

```cpp
// Full
Node *t = new Node;
if (t == null)
```

### Stack operations using linked list

- Push
    - We should first create a new node, check for the full condition.
    - Fill up the node with data, make it point to the previous node and turn it into top
- Pop
    - We should first check if the stack is empty
- Peek
    - To return the value of a node at any particular position we should traverse through the nodes starting from the top. We can use a for loop for this case.
- stackTop
    - Check if top is not equal not null and then return its value
- isEmpty
    - Check if the top is null or not
- isFull
    - Create a node and check if is not null and assign a answer to a variable then delete the node

```cpp
struct Node {
    int data;
    Node *nextNode;
}*top = nullptr;

void push(int x){
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow\n";
    else{
        t->data = x;
        t->nextNode = top;
        top = t;
    }
}

void pop(){
    int x = -1;
    Node *p;
    if (top == nullptr)
        cout << "Stack Underflow\n";
    else {
        p = top;
        top = top->nextNode;
        x = p->data;
        delete p;
    }
    cout << "The deleted value is " << x << endl;
}

void peek(int position){
    int x = -1;
    Node *p = top;
    for(int i = 0; p != NULL && i < position - 1; i++)
        p = p->nextNode;
    if (p != NULL)
        x = p->data;
    cout << "The value at that particular position is " << x << endl;
}

void stackTop(){
    if (top != nullptr)
        cout << "The top value is " << top->data << endl;
    else
        cout << "The top value is -1\n";
}

void isEmpty(){
    cout << (top != nullptr ? "It is empty\n" : "Not empty\n");
}

void isFull(){
    Node *t = new Node;
    cout << (t != nullptr ? "It is full\n" : "Not full\n");
    delete t;
}

void display(){
    Node *p;
    p = top;
    while(p != nullptr){
        printf("%d\n", p->data);
        p = p->nextNode;
    }
}

int main() {
    push(10);
    push(15);
    push(8);
    push(3);
    
    peek(2);
    display();
    
    return 0;
}

» The value at that particular position is 8
3
8
15
10
```

### Parenthesis Matching

- One of the applications of stack is parenthesis matching.
- The problem consists on this, a parenthesised expression is given: $((a+b)*(c-d))$
- We need to find if the parenthesis are balanced or not i.e. for every parenthesis there must be a closing parenthesis.
- **For every opening bracket there must be a clsing bracket**
- In the procedure we must scan through the expression, by taking one symbol at a time.
- We scan through the expression from the beginning and push the symbols onto the stack.
- We need to ignore the symbols and move ahead if they are not opening brackets or closing brackets.
- Ignore math symbols and letters or numbers.
- Whenever we encounter a closing bracket we delete the opening bracket. We don't push closing brackets onto the stack.

![Untitled](8%20-%20Stack%20bd29d/Untitled%207.png)

- If we take an example of an unbalanced expression it will look something like this.

![Untitled](8%20-%20Stack%20bd29d/Untitled%208.png)

- In this case the stack is not empty, in other words the parenthesis are not balanced.
- For creating a function to check whether a string is balanced or not we need a character pointer to access the array.

```cpp
struct NodeC {
    char data;
    NodeC *nextNode;
}*topC = nullptr;

void push(char x){
    NodeC *t = new NodeC;
    if (t == NULL)
        cout << "Stack Overflow\n";
    else{
        t->data = x;
        t->nextNode = topC;
        topC = t;
    }
}

void popC(){
    char x = -1;
    NodeC *p;
    if (topC == nullptr)
        cout << "Stack Underflow\n";
    else {
        p = topC;
        topC = topC->nextNode;
        x = p->data;
        delete p;
    }
}

int isBalanced(char const *exp){
    for(int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if (topC == NULL){
                break;
            }
            else
                popC();
        }
    }
    return (top == NULL ? 1 : 0);
}

int main() {
		char const *exp = "{([a+b]*[c-d])/e}";
    cout << (isBalanced(exp) ? "True\n" : "False\n");
    return 0;
}

» True
```

### Infix to Postfix Conversion

**What is infix, prefix and postfix?**

- There are three notations of writing an expression:
    - Infix: operand - operator - operand
        - $a + b$
        - This is the common method used in mathematics.
    - Prefix: operator - operand - operand
        - $+ab$
        - This is the first new method introduced in computer science.
    - Postfix: operand - operand - operator
        - $ab+$
        - This is the second new method introduced in computer science.

**Why do we need this?**

If we are given the following expression:

$$
8+3*\frac{(9-6)}{2^2}+\frac62\\8+3*\frac34+3\\8+\frac94+3\\\frac{41}4+3=\frac{53}4
$$

- To evaluate this we must take into consideration the higher precendence for the brackets.
- We must first solve whats inside the parentheses, then the power, division ... until we can solve the problem in easy terms.
- It would be time consuming to create a program that does can do this. Instead of scaning through the expression multiple times we will give it only one scan and get the result.
- **We must admit the fact that it is not posible to do so in Infix form.**
- **The only way we can do it is by using the postfix form.**

The postfix form of the previous looks like this:

$$
8\quad3\quad96-\quad2^2/*+62/+\\8\quad3\quad34/*+3+\\8\quad3\frac34*+\quad3+\\8\frac94+3+\\\frac{41}43+=\frac{53}4
$$

- The purpose of writing an expresion in postfix form is that we can scan the expression only once and perform all the operations.

![Untitled](8%20-%20Stack%20bd29d/Untitled%209.png)

**Conversion**

The precedence table looks like this in programming:

![Untitled](8%20-%20Stack%20bd29d/Untitled%2010.png)

- Whenever we write an expression we should make it fully parenthesized i.e $a+b*c$ should be written as $(a+(b*c))$
- We first must turn the infix expression to prefix and then to postfix

![Screen Shot 2021-10-14 at 22.19.01.png](8%20-%20Stack%20bd29d/Screen_Shot_2021-10-14_at_22.19.01.png)

### Associativity and Unary Operators

**What is associativity?**

![Untitled](8%20-%20Stack%20bd29d/Untitled%2011.png)

To understand associativity let's take an expresssion:

$$
a+b+c-d
$$

- All of the operators in this expression have the same precedence, we should check on the associativity table and see which case matches our with our expression.
- In this case the expression turned out to have a precedence of 1 and associativity that is **L-R**.

$$
Left-Right\quad(((a+b)+c)-d)
$$

But to see the opposite case let's take this expression that is commonly see in programming:

$$
a=b=c=5
$$

- This expression has associativity that is **R-L**.
- 5 is first assigned to c, c is assigned to b and finally b is assigned to a.

$$
Right-Left\quad(a=(b=(c=5)))
$$

## Infix to posfix using Stack

### Method 1

Let's take a simple expression $a+b*c-d/e$

- We must have a stack ready and we need to generate a postfix expression.
- We need to scan through the infix expression by taking one symbol at the time.
- By traversing through the expression our program must behave like this:
    - If we encounter an operand we must send it to the postfix expression.
    - If we encounter a symbol we must check the precendence number before we push it into the stack. We must check what are the operators present in the stack.
        - If the operators in the stack has lower precedence then we push the current symbol to the stack.
        - If the operator has higher precedence we delete the symbol in stack and send the value in the stack to the postfix expression.
        - If the precedence is equal we should detele the value in stack and send it to the postfix expression. Insert the symbol to the stack.
        - One we reach the end of the expression, whatever is in the stack we empty it by sending the contents to the end of the postfix expression. **From top to bottom.**

### Method 2

Let's tweak the last method a bit now

- Operands have a precedence of three and a L-R associativity.
- This means we can now push operands onto the stack. Everything will now go in the stack.
- The conditions will be the same

### Program

- To write a function we need three functions.
- The first function will check whether a symbol is a operand or not.
- The second function will return the precedence level of a symbol.
- We need a character type stack

```cpp
struct NodeC {
    char data;
    NodeC *nextNode;
}*topC = nullptr;

void push(char x){
    NodeC *t = new NodeC;
    if (t == NULL)
        cout << "Stack Overflow\n";
    else{
        t->data = x;
        t->nextNode = topC;
        topC = t;
    }
}

char popC(){
    char x = -1;
    NodeC *p;
    if (topC == nullptr)
        cout << "Stack Underflow\n";
    else {
        p = topC;
        topC = topC->nextNode;
        x = p->data;
        delete p;
    }
    return x;
}

int isBalanced(char const *exp){
    for(int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if (topC == NULL){
                return 0;
            }
            else
                popC();
        }
    }
    return (topC == NULL ? 1 : 0);
}

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0; // false
    else
        return 1; // true
}

int precedence(char x){
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

void convertToPosfix(char const *infix){
    int i = 0, j = 0;
    char *postfix = new char[strlen(infix) + 1];
    while(infix[i] != '\0'){
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if (!topC || precedence(infix[i]) > precedence(topC->data))
                push(infix[i++]);
            else
                postfix[j++] = popC();
        }
    }
    while(topC != nullptr){
        postfix[j++] = popC();
    }
    postfix[j] = '\0';
    cout << postfix;
}

int main() {
    char const *infix = "a+b*c-d/e";
    
    convertToPosfix(infix);
    
    return 0;
}

» abc*+de/-
```

### Infix to profix with associativity and parenthesis

![Screen Shot 2021-10-16 at 20.48.31.png](8%20-%20Stack%20bd29d/Screen_Shot_2021-10-16_at_20.48.31.png)

```cpp
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')
        return 0; // false
    else
        return 1; // true
}

int outPrecedence(char x){
    if (x == '+' || x == '-')
        return 1; //2
    else if (x == '*' || x == '/')
        return 3; // 4
    else if (x == '^')
        return 6; // 5
    else if (x == '(')
        return 7; // 0
    else if (x == ')')
        return 0;
    else
        return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else
        return -1;
}

void convertToPosfixC(char const *infix){
    int i = 0, j = 0;
    char *postfix = new char[strlen(infix) + 1];
    while(infix[i] != '\0'){
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if (!topC || outPrecedence(infix[i]) > inPrecedence(topC->data))
                push(infix[i++]);
            else
                if (outPrecedence(infix[i]) == inPrecedence(topC->data)){
                    popC();
                    i++;
                } else
                    postfix[j++] = popC();
        }
    }
    while(topC != nullptr){
        postfix[j++] = popC();
    }
    postfix[j] = '\0';
    cout << postfix;
}

int main() {
    char const *infix = "((a+b)*c)-d^e^f";
    
    convertToPosfixC(infix);
    
    return 0;
}

» ab+c*def^^-
```

### Evaluation of postfix expression

Let's take an expression $3*5+6/2-4$

If we evaluate this it will look like

$15 + 3 - 4\\18-4=14$

- We will try to mimic this in posfix form
- We must first convert the expression into posfix
- The previous expression in postfix form is $35*62/+4-$
- We need to scan the postfix expression by one symbol at a time
- The procedure is the following
    - index[i] == operand push it into the stack
    - index[i] == operator pop out two elements from the stack and perfom the operation with the current operator and push the result into the stack
    - Once we reach the end of the expression we take what's left in the stack and set it as the answer.

![Screen Shot 2021-10-18 at 20.39.35.png](8%20-%20Stack%20bd29d/Screen_Shot_2021-10-18_at_20.39.35.png)

```cpp
struct Node {
    int data;
    Node *nextNode;
}*top = nullptr;

void push(int x){
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow\n";
    else{
        t->data = x;
        t->nextNode = top;
        top = t;
    }
}

int pop(){
    int x = -1;
    Node *p;
    if (top == nullptr)
        cout << "Stack Underflow\n";
    else {
        p = top;
        top = top->nextNode;
        x = p->data;
        delete p;
    }
    return x;
}

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int evaluationPosfix(char const *postfix){
    int i, x1, x2, r;
    for(i = 0; postfix[i] != '\0'; i++){
        if (isOperand(postfix[i]))
            push(postfix[i]-'0');
        else {
            x2 = pop(); x1 = pop();
            switch(postfix[i]){
                case '*': r = x1 * x2; break;
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '/': r = x1 / x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main() {
    char const *postfix = "35*62/+4-";
    cout << evaluationPosfix(postfix) << endl;
    return 0;
}

» 14
```