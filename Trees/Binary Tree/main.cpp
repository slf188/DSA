//
//  main.cpp
//  Trees
//
//  Created by Felipe Vallejo on 25/10/21.
//

#include <iostream>
#include "Queue.h"
using namespace std;

Node *root = NULL;

void createBinaryTree(){
    Node *p, *t;
    int x;
    Queue q;
    createQueue(&q, 100);
    cout << "Print root value\n";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lChild = root->rChild = NULL;
    enqueue(&q, root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        cout << "Enter left child of " << p->data << endl;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lChild= t->rChild = NULL;
            p->lChild = t;
            enqueue(&q, t);
        }
        cout << "Enter right child of " << p->data << endl;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->rChild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(Node *p){
    if(p){
        cout << p->data;
        preorder(p->lChild);
        preorder(p->rChild);
    }
}

void inorder(Node *p){
    if(p){
        inorder(p->lChild);
        cout << p->data;
        inorder(p->rChild);
    }
}

void postorder(Node *p){
    if(p){
        postorder(p->lChild);
        postorder(p->rChild);
        cout << p->data;
    }
}

void levelOrder(Node *p){
    Queue q;
    createQueue(&q, 100);
    cout << p->data;
    enqueue(&q, p);
    while(!isEmpty(q)){
        p = dequeue(&q);
        if(p->lChild){
            cout << p->lChild->data;
            enqueue(&q, p->lChild);
        }
        if(p->rChild){
            cout << p->rChild->data;
            enqueue(&q, p->rChild);
        }
    }
}

int count(Node *p){
    int x, y;
    if(p != NULL){
        x = count(p->lChild);
        y = count(p->rChild);
        return x + y + 1;
    }
    return 0;
}

int sumOfData(Node *p){
    int x, y;
    if(p != NULL){
        x = count(p->lChild);
        y = count(p->rChild);
        return x + y + p->data;
    }
    return 0;
}

int height(Node *p){
    int x, y;
    if(p != NULL){
        x = height(p->lChild);
        y = height(p->rChild);
        if(x > y)
            return x + 1;
        else if (x == y || x < y)
            return y + 1;
    }
    return 0;
}

int countLeafNodes(Node *p){
    // Leaf nodes count degree zero nodes
    int x, y;
    if(p != NULL){
        x = countLeafNodes(p->lChild);
        y = countLeafNodes(p->rChild);
        if(p->lChild == NULL && p->rChild == NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int countDegreeOneNodes(Node *p){
    int x, y;
    if(p!=NULL){
        x = countDegreeOneNodes(p->lChild);
        y = countDegreeOneNodes(p->rChild);
        if(p->lChild!=nullptr ^ p->rChild!=nullptr)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int countDegreeOneOrTwoNodes(Node *p){
    int x, y;
    if(p!=NULL){
        x = countDegreeOneOrTwoNodes(p->lChild);
        y = countDegreeOneOrTwoNodes(p->rChild);
        if(p->lChild != NULL || p->rChild != NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int countDegreeTwoNodes(Node *p){
    int x, y;
    if(p != NULL){
        x = countDegreeTwoNodes(p->lChild);
        y = countDegreeTwoNodes(p->rChild);
        if(p->lChild != NULL && p->rChild != NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int countUsingRecursion(Node *p){
    if(p==NULL)
        return 0;
    return countUsingRecursion(p->lChild) + countUsingRecursion(p->rChild) + 1;
}

// Binary Search Tree Section

int rSearch(Node *t, int key){
    if(t==NULL)
        return NULL;
    if(key==t->data)
        return t->data;
    else if(t->data>key)
        // Perform search on the left subtree
        return rSearch(t->lChild, key);
    else
        // Perform search on the right subtree
        return rSearch(t->rChild, key);
}

void insert(Node *t, int key){
    Node *r = NULL, *p;
    while(t!=NULL){
        r = t;
        if(key==t->data)
            return;
        else if(t->data>key)
            t = t->lChild;
        else
            t = t->rChild;
    }
    p = new Node;
    p->data = key;
    p->lChild = p->rChild = NULL;
    if(r->data > p->data)
        r->lChild = p;
    else
        r->rChild = p;
}

Node * recursiveInsert(Node *p, int key){
    Node *t;
    if(p==NULL){
        t = new Node;
        t->data = key;
        t->lChild = t->rChild = NULL;
        return t;
    }
    if(p->data > key)
    /* Because p->lChild is null now we will
     assign p->lChild to a new created node */
        p->lChild = recursiveInsert(p->lChild, key);
    else
    /* Because p->rChild is null now we will
     assign p->rChild to a new created node */
        p->rChild = recursiveInsert(p->rChild, key);
    return p;
}

Node * inorderPredecessor(Node *p){
    while(p && p->rChild != NULL)
        p = p->rChild;
    return p;
}

Node * inorderSuccessor(Node *p){
    while(p && p->lChild != NULL)
        p = p->lChild;
    return p;
}

Node * deleting(Node *p, int key){
    Node *q;
    if(p == nullptr)
        return nullptr;
    // Directly delete this leaf node:
    if(p->lChild == nullptr && p->rChild == nullptr){
        // Check if the node is a root node:
        if(p==root)
            root = nullptr;
        // Delete this leaf node
        delete p;
        return nullptr;
    }
    if(p->data > key)
        p->lChild = deleting(p->lChild, key);
    else if(p->data < key)
        p->rChild = deleting(p->rChild, key);
    else { // Key is found
        // Decide if we will take a left
        // or right subtree predecessor
        if(height(p->lChild) > height(p->rChild)){
            q = inorderPredecessor(p->lChild);
            p->data = q->data;
            p->lChild = deleting(p->lChild, q->data);
        } else {
            q = inorderSuccessor(p->rChild);
            p->data = q->data;
            p->rChild = deleting(p->rChild, q->data);
        }
    }
    return p;
}

int main() {
    root = recursiveInsert(root, 30);
    recursiveInsert(root, 20);
    recursiveInsert(root, 10);
    recursiveInsert(root, 25);
    recursiveInsert(root, 40);
    recursiveInsert(root, 35);
    recursiveInsert(root, 45);
    recursiveInsert(root, 43);
    deleting(root, 30);
    return 0;
}
