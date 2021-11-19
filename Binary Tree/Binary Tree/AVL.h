//
//  AVL.h
//  Binary Tree
//
//  Created by Felipe Vallejo on 18/11/21.
//

#ifndef AVL_h
#define AVL_h

struct NodeAVL {
    NodeAVL *lChild;
    int data;
    /* It is necessary that we maintain
     balance for every node in a
     AVL tree so this means we
     need to keep track of the height */
    int height;
    NodeAVL *rChild;
}*root = nullptr;

int nodeHeight(NodeAVL *p){
    int hLeftSubtree, hRightSubtree;
    hLeftSubtree = p && p->lChild ? p->lChild->height : 0;
    hRightSubtree = p && p->rChild ? p->rChild->height : 0;
    return hLeftSubtree > hRightSubtree ? hLeftSubtree + 1 : hRightSubtree + 1;
}

int balanceFactor(NodeAVL *p){
    /* The balance factor is the height
     of the left subtree minus the
     height of the right subtree */
    int hLeftSubtree, hRightSubtree;
    hLeftSubtree = p && p->lChild ? p->lChild->height : 0;
    hRightSubtree = p && p->rChild ? p->rChild->height : 0;
    return hLeftSubtree > hRightSubtree ? hLeftSubtree + 1 : hRightSubtree + 1;
    return hLeftSubtree - hRightSubtree;
}

Node * LLRotation(NodeAVL *p){
    /* We should make p->lChild the root
     node and p->rLChild should
     become the lChild of p */
    NodeAVL *pLeft = p->lChild;
    NodeAVl *pLeftRight = pl->rChild;
    pLeft->rChild = p;
    p->lChild p = pLeftRight;
    p->height = nodeHeight(p);
    pLeft->height = nodeHeight(pl);
    if(root = p)
        root = pl;
    return pl;
}

Node * recursiveInsertAVL(NodeAVL *p, int key){
    Node *t;
    if(p==NULL){
        t = new Node;
        t->data = key;
        t->height = 1;
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
    p->height = nodeHeight(p);
    /* Now we can proceed on checking
     the balance factor of the tree and
     deciding whether we make a rotation or not */
    if(balanceFactor(p) == 2 && balanceFactor(p->lChild) == 1)
        // This will trigger LL Rotation
        return LLRotation(p);
    else if(balanceFactor(p) == 2 && balanceFactor(p->lChild) == -1)
        // This will trigger LR Rotation
        return LRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->lChild) == -1)
        // This will trigger RR Rotation
        return RRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->lChild) == 1)
        return RLRotation(p);
    
    
    return p;
}

#endif /* AVL_h */
