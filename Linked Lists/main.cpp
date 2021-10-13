//
//  main.cpp
//  Linked Lists
//
//  Created by Felipe Vallejo on 26/8/21.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *nextNode;
    /* For implementing a linked list I
     need a pointer outside the structure */
}*firstNode = nullptr, *secondNode = nullptr, *third = nullptr, *head = nullptr;

void createLL(int A[], int n){
    /* We will scan through the first parameter,
     take one element at a time
     and create a node to form a Linked List */
    Node *nodeCreator, *lastNode;
    firstNode = new Node;
    // Head
    firstNode->data = A[0];
    firstNode->nextNode = nullptr;
    lastNode = firstNode;
    
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

void displayLL(Node *p){
    while(p != nullptr){
        printf("%d ", p->data);
        // Move to the next node:
        p = p->nextNode;
    }
}

void recursiveDisplayLL(Node *p){
    if (p != nullptr){
        printf("%d ", p->data);
        recursiveDisplayLL(p->nextNode);
        /* If we place printf below the recursive
         call then the linked list will be printed in reverse order */
    }
}

int nodeCountLL(Node *p){
    int count = 0;
    while (p != nullptr){
        count++;
        p = p->nextNode;
    }
    return count;
}

void addLL(Node *p){
    int sum = 0;
    while(p != nullptr){
        sum += p->data;
        p = p->nextNode;
    }
    printf("The sum of all the elements in this Linked List is %d\n", sum);
}

void maxLL(Node *p){
    int max = 0;
    /* We need to traverse through all the
     nodes and compare them with the max variable */
    while(p != nullptr){
        if (p->data > max)
            max = p->data;
        p = p->nextNode;
    }
    printf("The maximum number in the Linked List is %d\n", max);
}

bool searchLL(Node *p, int key){
    while(p != nullptr){
        if (key == p->data)
            return true;
        
        p = p->nextNode;
    }
    return false;
}

void insertLL(Node *p, int index, int element){
    Node *t;
    // Check if the given index is valid or not:
    if (index < 0){
        cout << "Unable to insert\n";
        return;
    }
    
    t = new Node;
    t->data = element;
    // First node insertion:
    if (index == 0){
        t->nextNode = firstNode;
        firstNode = t;
        // Position is index is greater than zero:
    } else {
        for(int i = 0; i < index - 1 && p != NULL; i++)
            p = p->nextNode;
        
        t->nextNode = p->nextNode;
        p->nextNode = t;
    }
}

void insertSortedLL(Node *p, int x){
    // q is a trailing pointer that will follow each step of the linked list
    Node *t, *q = nullptr;
    // New node with data
    t = new Node;
    t->data = x;
    t->nextNode = nullptr;
    // If the linked list empty?
    if (firstNode == nullptr)
        // Create a single node in the linked list
        firstNode = t;
    else{
        /* This loop will end when the data
         inside the current node is greater than x */
        while(p != nullptr && p->data < x){
            // Let q move to position p
            q = p;
            // Move to the next node
            p = p->nextNode;
        }
        // If the element we want to insert is the smallest it will come before the first node
        if (p == firstNode){
            t->nextNode = firstNode;
            firstNode = t;
        } else {
            // the node we want to insert will point to the bigger node
            t->nextNode = q->nextNode;
            // the previous node will point to the node we inserted
            q->nextNode = t;
        }
    }
}

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

void displayCircularLL(Node *p){
    do {
        printf("%d ", p->data);
        p = p->nextNode;
    } while(p != head);
}

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

struct DoubleNode {
    DoubleNode *prevNodeD;
    int dataD;
    DoubleNode *nextNodeD;
}*firstNodeD = nullptr, *headD = nullptr;


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


//*firstNode = nullptr, *secondNode = nullptr, *third = nullptr, *head = nullptr;
//
//void createLL(int A[], int n){
//    /* We will scan through the first parameter,
//     take one element at a time
//     and create a node to form a Linked List */
//    Node *nodeCreator, *lastNode;
//    firstNode = new Node;
//    // Head
//    firstNode->data = A[0];
//    firstNode->nextNode = nullptr;
//    lastNode = firstNode;
//
//    // Linked List creation
//    // Start from position 1 because head already exists
//    for (int i = 1; i < n; i++){
//        // New node
//        nodeCreator = new Node;
//        // Populate the node's data and nextNode location:
//        nodeCreator->data = A[i];
//        nodeCreator->nextNode = nullptr;
//        /* The data and nextNode location
//         will now belong to the lastNode */
//        lastNode->nextNode = nodeCreator;
//        lastNode = nodeCreator;
//    }
//}

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
            // t->nextNodeD = firstNodeD;
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
