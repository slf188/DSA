# 7 - Linked Lists

### **Problems with Arrays**

- An array is of fixed size, whenever we create it we need to mention the size and later on, we cannot modify the size of that array.
- Fixed-size is a problem because if we take a random size, then that size may be either insufficient or it may be excess and space will be wasted.

### **Difference between Arrays and Linked Lists**

- An array can exist inside stack and heap.
- An array is like a bench, say there are 5 seats, one person can seat and the rest of the 4 seats will be wasted.
- A data structure that holds the capacity of growing and reducing in size is a Linked List
- We create linked lists inside the heap, we start with an initial value, and we create a new node whenever I want to store an element, then I place that new element inside the node.
- A Linked List is like free space, if a person wants to sit, he should bring his chair and when the next person comes, the first person will link to that second person, and continuously...and if anybody wants to leave they can take off their chair. So we are forming a chain.
- We can not only remove elements on each end, but we can also delete elements in between other elements and the links will adjust to that modification!
- This data structure is more flexible than an array; the size can grow and reduce, we can easily insert and remove elements.

![Screen Shot 2021-10-07 at 15.34.23.png](7%20-%20Linked%20e1a7d/Screen_Shot_2021-10-07_at_15.34.23.png)

## **Linked List**

### **What is a linked list?**

![Screen Shot 2021-10-07 at 15.35.12.png](7%20-%20Linked%20e1a7d/Screen_Shot_2021-10-07_at_15.35.12.png)

- A linked list is a collection of nodes where each node contains data and a pointer to the next node.
- On every linked list we have a first element which is known as **First** or **Head**.
- The continuity of the linked list is maintained through links.

### **What is a node?**

- To understand what a node is, we must first understand two concepts:
    - **Data**: Of any type including int, float,...
    - **Pointer**: Connecting to a node type, a pointer of its own type
- A node is a box that contains two members, data, and a pointer to the next node.

![Screen Shot 2021-10-07 at 15.36.13.png](7%20-%20Linked%20e1a7d/Screen_Shot_2021-10-07_at_15.36.13.png)

### **Node Structure**

- This is called a self-referential structure.
- For creating a node we must create a pointer because nodes live inside the heap.
- We can define this in code using a structure as:

```cpp
struct Node{
	int data;
	Node *next;
};

int main(){
  Node *p;
  // Create a node
  p = new Node;
  // Access a node
  p->data = 10;
  p->next = 0; //Null is zero
  // The three methods of checking if 
  a node is not pointing anywhere are:*/
  // if (p==NULL)
  // if (p==0)
  // if (!p)
  // Switch opposite symbols for a node that points at somewhere
  // The last element in a linked list is found as:
  // if (p->next == NULL)
  return 0;
}
```

### **Display Linked List**

- For this problem, we will display all the elements that exist within a Linked List
- For this, we should know how to traverse through the entire linked list i.e. visit all the nodes at once.
- We must start from the first node.
- Because we don’t know how many nodes are in the linked list we must use a while loop.
- While traversing we can do multiple things, including displaying, counting, adding all the elements, searching for an element, sorting…

```cpp
struct Node{
    int data;
    Node *nextNode;
    /* For implementing a list I
    need a pointer outside the structure */
} *mainLinkedList = nullptr;

void createLL(int A[], int n){
    /* We will scan through the first parameter,
     take one element at a time
     and create a node to form a Linked List */
    Node *nodeCreator, *lastNode;
    mainLinkedList = new Node;
    // Head
    mainLinkedList->data = A[0];
    mainLinkedList->nextNode = nullptr;
    lastNode = mainLinkedList;
    
    // Linked List creation
    // Start from position 1 because head already exists
    for (int i = 1; i < n; i++){
        // New node
        nodeCreator = new Node;
        // Populate the node:
        nodeCreator->data = A[i];
        nodeCreator->nextNode = nullptr;
        // The data and nextNode location
         will now belong to the lastNode */
        lastNode->nextNode = nodeCreator;
        lastNode = nodeCreator;
    }
}

void displayLL(Node *p){
    while(p != nullptr){
        cout << p->data << “ ”;
        // Move to the next node:
        p = p->nextNode;
    }
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    createLL(A, 5);
    displayLL(mainLinkedList);
    return 0;
}

» 3 5 7 10 15
```

### **Recursive display of Linked List**

- We will now learn how to use a recursive function to display the linked list

```cpp
void recursiveDisplayLL(Node *p){
    if (p != nullptr){
        printf("%d ", p->data);
        recursiveDisplayLL(p->nextNode);
        /* If we place printf below the recursive
         call then the linked list will be printed in reverse order */
    }
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    createLL(A, 5);
    recursiveDisplayLL(mainLinkedList);
    return 0;
}

» 3 5 7 10 15
```

### **Counting nodes in a Linked List**

- By knowing how many nodes are in the Linked List we will also know the exact length of it.

```cpp
void nodeCountLL(Node *p){
    int count = 0;
    while (p != nullptr){
        count++;
        p = p->nextNode;
    }
    printf("The number of nodes in this Linked List is %d\n", count);
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    createLL(A, 5);
    nodeCountLL(mainLinkedList);
    return 0;
}

» The number of nodes in this Linked List is 5
```

### **Sum of all elements in a Linked List**

- For adding we should traverse through all the nodes inside the LL.
- We need to declare a variable holding zero and adding all the elements to that same variable.

```cpp
void addLL(Node *p){
    int sum = 0;
    while(p != nullptr){
        sum = sum + p->data;
        p = p->nextNode;
    }
    printf("The sum of all the elements in this Linked List is %d\n", sum);
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    createLL(A, 5);
    addLL(mainLinkedList);
    return 0;
}

» The sum of all the elements in this Linked List is 40
```

### Maximum element in a Linked List

```cpp
void maxLL(Node *p){
    int max = 0;
    /* We need to traverse through all the
     nodes and compare them with the max variable */
    while(p){
        if (p->data > max)
            max = p->data;
        p = p->nextNode;
    }
    printf("The maximum number in the Linked List is %d\n", max);
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    createLL(A, 5);
    maxLL(mainLinkedList);
    return 0;
}

» The maximum number in the Linked List is 15
```

### **Searching in a Linked List**

- Binary search cannot be performed within a Linked List because we can’t go into the middle of the list, instead, we must traverse from the start.
- Binary search is not suitable, only Linear Search works fine on this type of list.

```cpp
bool searchLL(Node *p, int key){
    while(p){
        if (key == p->data)
            return true;

        p = p->nextNode;
    }
    return false;
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    createLL(A, 5);
    searchLL(mainLinkedList, 18) ? cout << "Found\n" : cout << "Not found\n";
    return 0;
}

» Not found
```

### **Inserting in a Linked List**

- To insert a new node in an existing Linked List we should mention at what index we want to insert.
- Because linked lists don’t have index positions we must provide them; usually, with arrays, we start the index with zero but with a linked list it’s our wish.
- The places available for insertion are: before the first node, in between two nodes, or after the last node.
- We can use this as a function to create an entire linked list.
- The procedure for creating a new node before the first node is as follows
    - We create a new node with the help of a pointer.
    - Initialize the data, insert any data to that node.
    - Because it must become the first node we must point it towards the first node. Now the newly inserted node becomes the first node.

```cpp
// First node insertion
newNode = *new Node;
newNode->data = anyData;
newNode->next = firstNode;
first = newNode;
```

- The procedure for creating a new node in a given position is as follows:
    - Create a new node with some data.
    - Make the node point towards the following position of the position specified i.e. if we insert at 4 we must point to 5.
    - If the position is 4 we should move the node three times forward.
    - Finally, we should make 4 point to the new node and point the new node to 5.
    - This procedure works anywhere even if we want to insert in the last node.

```cpp
void insertLL(Node *p, int index, int element){
    Node *t;
    // Check if the given index is valid or not:
    if (index < 0){
        cout << "Unable to insert\n";
        return;
    }
    // Creation and node initialization:
    t = new Node;
    t->data = element;
    // First node insertion:
    if (index == 0){
        t->nextNode = mainLinkedList;
        mainLinkedList = t;
        // Position is index is greater than zero:
    } else {
        for(int i = 0; i < index - 1 && p != NULL; i++)
            p = p->nextNode;
        
        t->nextNode = p->nextNode;
        p->nextNode = t;
    }
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    createLL(A, 5);
    insertLL(mainLinkedList, 4, 13);
    displayLL(mainLinkedList);
    return 0;
}

» 3 5 7 10 13 15
```

### **Inserting in a sorted linked list**

- To find the suitable position for the new node we want to insert, we must compare starting from the first node if the node is smaller or not, in case it is smaller we advance to the following node until this condition is false to then place it.
- We must insert the node before a bigger node.
- We then must connect the previous node with the new node and connect the new node with the next node.
- If the node is smaller than the first node we must insert it to its left.

```cpp
void insertSortedLL(Node *p, int x){
    /* q is a trailing pointer that
     will follow each step of the linked list */
    Node *t, *q = nullptr;
    // New node with data
    t = new Node;
    t->data = x;
    t->nextNode = nullptr;
    // If the linked list is empty
    if (firstNode == nullptr)
        // Create a single node
        firstNode = t;
    else{
        /* This loop will end when the data
         inside a node in the linked list is greater than x */
        while(p != nullptr && p->data < x){
            // Let q move one step forward
            q = p;
            // Move to the next node
            p = p->nextNode;
        }
        /* If the element we want to insert
         is the smallest it will come before the first node */
        if (p == firstNode){
            t->nextNode = firstNode;
            firstNode = t;
        } else {
            /* The node we want to insert 
            will point to the bigger node */
            t->nextNode = q->nextNode;
            // The previous node will point to the node we inserted
            q->nextNode = t;
        }
    }
}

int main() {
    int A[] = {3, 7, 9, 15, 20};
    createLL(A, 5);
    insertSortedLL(firstNode, 18);
    displayLL(firstNode);
    return 0;
}

» 3 7 9 15 18 20
```

**Deleting a node from a Linked List**

- For deleting there are two cases
    - Deleting the first node
        - If the first node then the second node should become the first node.
        - We need the help of another pointer to assign the first node’s location to the pointer, assign the first node to the next node and delete the pointer.
    - Deleting a node at a given position
        - If we have 6 nodes and we want to delete the 4 node, we must point node 3 to node 5.
        - Modify the list and then delete.
        - We need two pointers. One for modifying the link and another for deallocating from memory.
        - The first pointer should start from null and the second from the head node.
- When a node is not linked in the list i.e. its been deleted, it must be deallocated.

```cpp
int deleteLL(int position){
    Node *p, *q;
    int x = 0;
    // If we want to delete the first node
    if (position == 1){
        // Store the first node's data
        x = firstNode->data;
        // Assign the pointer to the first node
        p = firstNode;
        // Move the first node to the second node
        firstNode = firstNode->nextNode;
        // Delete the first pointer holding the data of the first node
        delete p;
    } else {
        q = nullptr;
        p = firstNode;
        // Loop until we reach the node we want to delete
        for(int i = 0; i < position - 1 && p != NULL; ++i){
            // First node should jump to position where the second node is
            q = p;
            // The second node should go to the next node
            p = p->nextNode;
        }
        if (p != NULL){
            /* The first node should link to the node
             that is after the one we want to delete */
            q->nextNode = p->nextNode;
            x = p->data;
            delete p;
        }
    }
    return x;
}

int main() {
    int A[] = {3, 7, 9, 15, 20};
    createLL(A, 5);
    cout << deleteLL(1) << endl;
    displayLL(firstNode);
    return 0;
}

» 3
7 9 15 20
```

### **Check if a linked list is sorted**

- We should traverse through the list and see if the next node is greater than the previous one until it is null.

```cpp
int sortedLL(Node *p){
    int x = -32768;
    p = firstNode;
    while (p != NULL){
        if (p->data < x)
            return 0;
            
        x = p->data;
        p = p->nextNode;
    }
    return 1;
}

int main() {
    int A[] = {3, 9, 8, 12, 16};
    createLL(A, 5);
    if (sortedLL(firstNode))
        cout << "Sorted\n";
    else
        cout << "Unsorted\n";    
    return 0;
}

» Unsorted
```

### **Remove duplicates from a sorted linked list**

- We should have two pointers, one on the first node and one on the second node.
- We have to check whether the current node and the next node’s data are the same. If it is the same we can delete any of the second node.

```cpp
void removeDuplicateLL(){
    Node *p, *q;
    p = firstNode;
    q = firstNode->nextNode;
    while(q != NULL){
        if (p->data == q->data){
            p->nextNode = q->nextNode;
            delete q;
            q = q->nextNode;
        } else {
            p = q;
            q = p->nextNode;
        }
    }
}

int main() {
    int A[] = {3, 5, 5, 8, 9, 10};
    createLL(A, 5);
    removeDuplicateLL();
    displayLL(firstNode);
    return 0;
}
» 3 5 8 9
```

### **Reversing a linked list**

- If we have a linked list 2, 4, 6, 8. By reversing we mean changing the order of the linked list and making the elements as 8, 6, 4, 2.
- There are three methods for achieving this:
    - **Reversing elements**
        - Interchange the value on the left side with the right side, but the node will be the same.
        - We should have an array of the same size of the elements ready to copy the elements in the array.
        - Once the elements are copied in the array we should reverse copy the elements in that linked list.
    - **Reversing links**
        - We must make the last elements point backward instead of forwards.
        - We should have 3 pointers. We should slide the three until the p node located in the first node reaches null.
    - **Recursion**
        - Because there is a calling phase and a returning phase in recursion this can help us reverse the linked list.
        - We shall reverse the links in the returning phase.
        - We only need two pointers, one on before the first node and another on the first node

In a linked list we prefer reversing links rather than reversing elements because by moving data in the linked list, **reversing the order of the links is just a healthier way to reverse the linked list.**

```cpp
void reversingLinksLL(Node *p){
    Node *r, *q;
    r = q = NULL;
    while (p != NULL){
        r = q;
        q = p;
        p = p->nextNode;
        q->nextNode = r;
    }
    firstNode = q;
}

void reversingRecursionLL(Node *q, Node *p){
    if (p != NULL){
        reversingRecursionLL(p, p->nextNode);
        p->nextNode = q;
    } else {
        firstNode = q;
    }
}

int main() {
    int A[] = {2, 4, 6, 8};
    createLL(A, 4);
    // reversingLinksLL(firstNode);
    reversingRecursionLL(NULL, firstNode);
    displayLL(firstNode);
    return 0;
}

» 8 6 4 2
```

### **Concatenating two linked lists**

- Concatenating means joining both linked lists into a single linked list
- We need to reach the end of the first linked list, and instead of null, we point it to the first node of the second linked list.
- We need two pointers

### **Merging two ordered linked lists**

- When we combine the two linked lists they must be a single ordered linked list.
- We don’t need a third linked list to do this procedure.
- We need two pointers. third and last.
- Procedure:
    - Compare the first node of the first linked list and the first node of the second linked list.
    - If the first node from the first linked list is smaller then we make the third and last point on it and set last’s next node to null.
    - Then we jump to the next node from the first linked list and again compare.
    - If the first node from the second linked list is smaller than the node from the first linked list we make the last point on it and move last to its position.
    - Continue the procedure

```cpp
struct Node{
    int data;
    Node *nextNode;
    /* For implementing a linked list I
     need a pointer outside the structure */
} *firstNode = nullptr, *secondNode = nullptr, *third = nullptr;

void create2LL(int A[], int n){
    /* We will scan through the first parameter,
     take one element at a time
     and create a node to form a Linked List */
    Node *nodeCreator, *lastNode;
    secondNode = new Node;
    // Head
    secondNode->data = A[0];
    secondNode->nextNode = nullptr;
    lastNode = secondNode;
    
    // Linked List creation
    // Start from position 1 because head already exists
    for (int i = 1; i < n; i++){
        // New node
        nodeCreator = new Node;
        // Populate the node's data and nextNode location:
        nodeCreator->data = A[i];
        nodeCreator->nextNode = nullptr;
        /* The data and nextNode location
         will now belong to the lastNode */
        lastNode->nextNode = nodeCreator;
        lastNode = nodeCreator;
    }
}

void concatenatingTwoLL(Node *p, Node *q){
    third = p;
    while(p->nextNode != NULL){
        p = third->nextNode;
    }
    p->nextNode = q;
}

void mergingTwoLL(Node *first, Node *second){
    Node *last;
    last = NULL;
    if (first->data < second->data){
        third = last = first;
        first = first->nextNode;
        last->nextNode = nullptr;
    } else {
        third = last = second;
        second = second->nextNode;
        last->nextNode = nullptr;
    }

    while(first != NULL && second != NULL){
        if (first->data < second->data){
            last->nextNode = first;
            last = first;
            first = first->nextNode;
            last->nextNode = nullptr;
        } else {
            last->nextNode = second;
            last = second;
            second = second->nextNode;
            last->nextNode = nullptr;
        }
    }
}

int main() {
    
    int A[] = {2, 4, 6, 8};
    int B[] = {3, 5, 7, 9};
    createLL(A, 4);
    create2LL(B, 4);
    mergingTwoLL(firstNode, secondNode);
//    concatenatingTwoLL(firstNode, secondNode);
    displayLL(third);
    return 0;
    
}

» 2 3 4 5 6 8 9
```

### **Check if a linked list has a loop or its linear**

- A loop is when the last node in a linked list points at some node i.e. the linked list has no end.
- A linear linked list is one where the last node points to null.
- Method for loop:
    - Use two pointers p, and q.
    - P will move by one node and q will move by two nodes.
    - Check if the nodes meet again, if so then there is a loop.

```cpp
void isLoopLL(Node *f){
    Node *p, *q;
    p = q = firstNode;
    do {
        p = p->nextNode;
        // First step
        q = q->nextNode;
        // Second step, check if the next node is null or not
        q = q != NULL ? q->nextNode : NULL;
        
    } while(p && q && p != q);
    
    cout << (p == q ? "There is a loop\n" : "There is no loop\n");
}

int main() {
    int A[] = {2, 4, 6, 8};
    createLL(A, 4);
    isLoopLL(firstNode);
    return 0;
}

» There is no loop
```

### **Circular linked list**

- A linear linked list is where the last node points to null, a circular linked list is where the last node will point to the first node.
- Another definition is “where the nodes are circularly connected”
- A circular linked list doesn’t have a first or last node.
- The benefit of using it is we can traverse the nodes circularly.
- Suppose there is only one node then it will point to itself.
- To access the first node in a circular linked list we can create a head node that is null. The last node will only point to the next node of the head node that is null.

The procedure for implementing a circular linked list is:

- We should only traverse the linked list until we reach the starting point.

```cpp
struct Node{
    int data;
    Node *nextNode;
    /* For implementing a linked list I
     need a pointer outside the structure */
}*head = nullptr;

void createHeadLL(int A[], int n){
    Node *nodeCreator, *lastNode;
    head = new Node;
    head->data = A[0];
    /* The next pointer should head on itself, it becomes circular now. It is a single node */
    head->nextNode = head;
    lastNode = head;
    
    for (int i = 1; i < n; i++){
        nodeCreator = new Node;
        nodeCreator->data = A[i];
        nodeCreator->nextNode = lastNode->nextNode;
        lastNode->nextNode = nodeCreator;
        lastNode = nodeCreator;
    }
}

void displayCircularLL(Node *p){
    do {
        printf("%d ", p->data);
        p = p->nextNode;
    } while(p != head);
}

int main() {
    int A[] = {2, 3, 4, 5, 6};
    createHeadLL(A, 5);
    displayCircularLL(head);
    return 0;
}

» 2 3 4 5 6
```

### **Inserting in a circular linked list**

- Same as insertion for a linear linked list we can either insert before the first node or in between nodes. For inserting in between nodes it’s the same method as in a linear linked list.
- For inserting in the first node, in this case, should be as follows:
    - Create a new node with the help of a pointer t, and insert data.
    - The new node t should point to the head node.
    - The last node should point to the pointer t. To do so we can use a pointer p and move it until the next node is equal to the head. Stop there and point to p.

```cpp
void insertCircularLL(Node *p, int index, int x){
    Node *t;
    if (index == 0){
        t = new Node;
        t->data = x;
        /* If there is one single node then
         the head node should point on itself */
        if (head == nullptr){
            head = t;
            head->nextNode = head;
        } else {
            while(p->nextNode != head)
                p = p->nextNode;
            p->nextNode = t;
            t->nextNode = head;
            head = t;
        }
    } else {
        p = head;
        for (int i = 0; i < index - 1; ++i)
            p = p->nextNode;
        
        t = new Node;
        t->data = x;
        t->nextNode = p->nextNode;
        p->nextNode = t;
    }
}

int main() {
    int A[] = {2, 3, 4, 5, 6};
    createHeadLL(A, 5);
    insertCircularLL(head, 0, 1);
    insertCircularLL(head, 6, 7);
    displayCircularLL(head);
    return 0;
}

» 1 2 3 4 5 6 7
```

### **Deleting from a circular linked list**

- For this operation, we have two cases
    - Delete head node
        - If the head node is deleted, we should make its next node the head node.
    - Deleting a node from a given position
        - This procedure is similar to deleting from a linear linked list.
        - We need two pointers, one on the node before the node we want to delete and another pointer in the node we want to delete.

```cpp
void deleteCircularLL(Node *p, int index){
    Node *q;
    int x;
    if (index == 0){
        while(p->nextNode != head)
            p = p->nextNode;
        p->nextNode = head->nextNode;
        x = head->data;
        delete head;
        head = p->nextNode;
    } else {
        
        for (int i = 0; i < index - 1; i++){
            p = p->nextNode;
        }
        // q is in the node we want to delete
        q = p->nextNode;
        p->nextNode = q->nextNode;
        x = q->data;
        delete q;
        
    }
}

int main() {
    int A[] = {2, 3, 4, 5, 6};
    createHeadLL(A, 5);
    deleteCircularLL(head, 0);
    displayCircularLL(head);
    return 0;
}

» 3 4 5 6
```

### **Doubly-linked list**

A doubly linked list looks something like this:

![Screen Shot 2021-10-07 at 15.46.59.png](7%20-%20Linked%20e1a7d/Screen_Shot_2021-10-07_at_15.46.59.png)

- In a singly linked list, each node has a pointer to the next node. But in a doubly-linked list, each node has a pointer to the next node and the previous node.
- This means we can go forward or backward from one node i.e. we can traverse in either direction.
- A doubly-linked list appears in a browser whenever we want to go back or forward in a page.

The node structure looks like this:

![Screen Shot 2021-10-07 at 15.47.26.png](7%20-%20Linked%20e1a7d/Screen_Shot_2021-10-07_at_15.47.26.png)

- Every node has the same structure.
- We can do the same operations a linear linked list does.

```cpp
struct DoubleNode {
    DoubleNode *prevNodeD;
    int dataD;
    DoubleNode *nextNodeD;
}*firstNodeD = nullptr;

void createDLL(int A[], int n){
    
    firstNodeD = new DoubleNode;
    firstNodeD->prevNodeD = firstNodeD->nextNodeD = nullptr;
    firstNodeD->dataD = A[0];
    DoubleNode *lastNodeD = firstNodeD;
    
    for (int i = 1; i < n; i++){
        DoubleNode *nodeCreatorD = new DoubleNode;
        nodeCreatorD->prevNodeD = lastNodeD;
        nodeCreatorD->dataD = A[i];
        nodeCreatorD->nextNodeD = nullptr;
        lastNodeD->nextNodeD = nodeCreatorD;
        lastNodeD = nodeCreatorD;
    }
}

void displayDoublyLL(DoubleNode *p){
    while(p != nullptr){
        cout << p->dataD << " ";
        p = p->nextNodeD;
    }
    cout << endl;
}

void lengthDoublyLL(DoubleNode *p){
    int length = 0;
    while(p != nullptr){
        length++;
        p = p->nextNodeD;
    }
    cout << length << endl;
}

int main() {
    int A[] = {2, 3, 4, 5, 6};
    createDLL(A, 5);
    lengthDoublyLL(firstNodeD);
    displayDoublyLL(firstNodeD);
    return 0;    
}

» 5
2 3 4 5 6
```

### **Insert in a doubly linked list**

- There are two scenarios for inserting
    - Before first node
    - In between nodes
        - For this case we need two pointers.

```cpp
void insertDoublyLL(DoubleNode *p, int index, int x){
    if (index == 0){
        p = new DoubleNode;
        p->dataD = x;
        p->prevNodeD = nullptr;
        p->nextNodeD = firstNodeD;
        firstNodeD->prevNodeD = p;
        firstNodeD = p;
    } else {
        p = new DoubleNode;
        p = firstNodeD;
        for (int i = 0; i < index - 1; i++)
            p = p->nextNodeD;
        
        DoubleNode *t = new DoubleNode;
        t->dataD = x;
        t->nextNodeD = p->nextNodeD;
        t->prevNodeD = p;
        p->nextNodeD = t;
        if (p->nextNodeD != nullptr)
            p->nextNodeD->prevNodeD = t;
        
    }
    
}

int main() {
    int A[] = {2, 3, 4, 5, 6};
    createDLL(A, 5);
    insertDoublyLL(firstNodeD, 5, 7);
    displayDoublyLL(firstNodeD);
    return 0;
}

» 2 3 4 5 6 7
```

### **Delete from a doubly linked list**

- There are two cases for deletion
    - Delete first node
        - We need one pointer for this.
    - Deleting from a given index
        - We need three pointers

```cpp
void deleteDoublyLL(DoubleNode *p, int index){
    int x;
    if (index == 0){
        DoubleNode *q = new DoubleNode;
        q = firstNodeD;
        firstNodeD = firstNodeD->nextNodeD;
        x = p->dataD;
        delete p;
        if (p->nextNodeD != nullptr){
            firstNodeD->prevNodeD = nullptr;
        }
    } else {
        DoubleNode *q = new DoubleNode;
        q = firstNodeD;
        for (int i = 0; i < index; i++)
            q = q->nextNodeD;
        q->prevNodeD->nextNodeD = q->nextNodeD;
        if (q->nextNodeD != nullptr)
            q->nextNodeD->prevNodeD = q->prevNodeD;
        x = q->dataD;
        delete q;
    }
}

int main() {
    int A[] = {2, 3, 4, 5, 6};
    createDLL(A, 5);
    deleteDoublyLL(firstNodeD, 0);
    displayDoublyLL(firstNodeD);
    return 0;
}

» 3 4 5 6
```

### **Reverse a doubly linked list**

- We should traverse through the linked list and swap the pointers.
- We need to interchange the pointers, a previous node should point on the next node and the next node should become null.

```cpp
void reverseDoublyLL(DoubleNode *p){
    DoubleNode *temp;
    while(p != nullptr){
        temp = p->nextNodeD;
        p->nextNodeD = p->prevNodeD;
        p->prevNodeD = temp;
        p = p->prevNodeD;
        if (p != nullptr && p->nextNodeD == NULL){
            firstNodeD = p;
        }
    }
}

int main() {
    int A[] = {2, 3, 4, 5, 6};
    createDLL(A, 5);
    reverseDoublyLL(firstNodeD);
    displayDoublyLL(firstNodeD);
    return 0;
}

» 6 5 4 3 2
```

### **Circular Doubly Linked List**

- Same as a circular linear linked list, the last node is pointing on the head node.
- These nodes are circularly connected.
- For inserting a node before the first node we don’t need to traverse until the last node to do so.

```cpp
struct DoubleNode {
    DoubleNode *prevNodeD;
    int dataD;
    DoubleNode *nextNodeD;
} *headD = nullptr;

void createHeadDLL(int A[], int n){

    headD = new DoubleNode;
    headD->prevNodeD = nullptr;
    headD->nextNodeD = nullptr;
    headD->dataD = A[0];
    DoubleNode *lastNodeD = headD;

    for (int i = 1; i < n; i++){
        DoubleNode *nodeCreatorD = new DoubleNode;
        nodeCreatorD->prevNodeD = lastNodeD;
        nodeCreatorD->dataD = A[i];
        nodeCreatorD->nextNodeD = nullptr;
        lastNodeD->nextNodeD = nodeCreatorD;
        lastNodeD = nodeCreatorD;
    }
    headD->prevNodeD = lastNodeD;
}

void displayCircularDLL(DoubleNode *p){
    do {
        cout << p->dataD << " ";
        p = p->nextNodeD;
    }while(p != headD);
}

void insertCircularDLL(DoubleNode *p, int index, int x){
    if (index < 0)
        return;
    
    DoubleNode *t = new DoubleNode;
    if (index == 0){
        t->dataD = x;
        if (headD == nullptr){
            t->nextNodeD = t;
            t->prevNodeD = t;
            headD = t;
        } else {
            t->prevNodeD = headD->prevNodeD;
            headD->prevNodeD->nextNodeD = t;
            t->nextNodeD = headD;
            headD->prevNodeD = t;
            headD = t;
        }
    } else {
        t->dataD = x;
        for (int i = 0; i < index - 1; i++)
            p = p->nextNodeD;
        t->nextNodeD = p->nextNodeD;
        p->nextNodeD = t;
        p->nextNodeD->prevNodeD = t;
        t->prevNodeD = p;
    }
}

int main() {
    int A[] = {2, 3, 4, 5, 6};
    createHeadDLL(A, 5);
    insertCircularDLL(headD, 0, 1);
    displayCircularDLL(headD);
    return 0;
}

» 1 2 3 4 5 6
```

### **Comparison of linked lists**

- So far we have reviewed
1. Linear Linked List
    1. One link will be modified if we insert before the head node.
    2. No links will be modified if we delete the first node.
2. Circular Linked List
    1. Two links will be modified if we insert before the head node.
    2. One link is modified if we delete the head node.
3. Linear Doubly Linked List
    1. Requires two pointers for creating each node.
    2. Takes double the space of pointers required for a Singly Linked List.
    3. Three links will be modified if we insert before the head node.
    4. One link is modified if we delete the head node.
    5. It takes the same space as a circular doubly linked list.
4. Circular Doubly Linked List
    1. Requires two pointers for creating each node.
    2. Takes double the space of pointers required for a Singly Linked List.
    3. Four links will be modified if we insert before the head node.
    4. Two links are modified if we delete the head node.
    5. The best linked list is a circular doubly linked list. But it takes extra space.
    6. It takes the same space as a linear doubly linked list.

### **Comparison of array with linked list**

- By using both of these data structures we can implement other data structures.
- **Array**
    - Can be created in stack and heap
    - Size is fixed
    - It wastes space if we don’t use it fully. If we know the maximum size then we should create it
    - This will occupy space only, equal to the size of the data.
    - Can be accessed randomly
    - Because it lives in the stack it is faster to access it
    - Movement of data is costly, it happens when we want to insert an element
    - Binary search is doable in an array
    - Most sorting methods are designed for arrays
- **Linked List**
    - Always created in heap
    - Size can grow as much as heap memory is available
    - We don’t necessarily need to know the maximum size of the list
    - Takes extra space
    - Can be accessed sequentially
    - Because it lives in both the stack and the heap its access is slower
    - There is no movement of data when we insert an element
    - Binary search is not doable in a linked list
    - Only a few sorting methods are designed for linked lists, these are Insertion sort and merge sort