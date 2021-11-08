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

int main() {
    createBinaryTree();
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}
