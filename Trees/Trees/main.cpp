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

int main() {
    createBinaryTree();
    cout << "The number of nodes is " << count(root) << endl;
    cout << "The sum of all the elements is " << sumOfData(root) << endl;
    cout << "The height is " << height(root) << endl;
    cout << "The number of leaf nodes is " << countLeafNodes(root) << endl;
    cout << "The number of nodes with degree one is " << countDegreeOneNodes(root) << endl;
    cout << "The number of nodes with degree two is " << countDegreeTwoNodes(root) << endl;
    cout << "The number of nodes with degree one or two is " << countDegreeOneOrTwoNodes(root) << endl;
    return 0;
}
