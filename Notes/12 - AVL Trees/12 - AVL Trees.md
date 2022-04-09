# 12 - AVL Trees

### What are AVL trees?

- AVL Trees are height balanced binary search trees
- The height of this type of tree is balanced by using a balance factor. A balance factor is:

$$
balance\space factor = height\space of \space left\space subtree - height\space of\space right\space subtree=(-1,0,1)
$$

- This balance factor is calculated on every node of a binary search tree, the balance factor of every node must be in between the range of {-1, 0, 1}
- We can see whether a node is balanced by checking on the following conditions
- Remember that we are not counting nodes, instead we are counting height

```cpp
if(|bF| = |hL-hR| <= 1)
		// balanced
else if(|bF| = |hL-hR| > 1)
		// imbalanced
```

Let's try to grasp with the following search binary trees:

![Untitled](12%20-%20AVL%20T%20668ea/Untitled.png)

### Inserting in AVL with rotations

- When we are creating an AVL tree, and we are inserting a node in it then some nodes may come imbalanced, so that makes the whole tree imbalanced. So to balance it we perform rotations
- Those rotations are named as:
    - LL-Rotation
        - Suppose this is an initial AVL Tree:
        
        ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%201.png)
        
        - Let's insert a value 10
        
        ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%202.png)
        
        - This is an special kind of imbalance, we should first ask in which direction is 10 inserted? It's inserted on the left of left so this case is LL-Imbalance
        - To tackle this problem we should implement rotation in the following direction
        
        ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%203.png)
        
        - The tree looks like this after the rotation, and it has become balanced
        
        ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%204.png)
        
    - RR-Rotation
    
    ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%205.png)
    
    - LR-Rotation
    
    ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%206.png)
    
    - RL-Rotation
    
    ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%207.png)
    
- What should we do if the tree is very big? Don't worry rotations are always done with three nodes only

### General form of AVL rotations

- Now we are going go to focus on the formulas for the time of rotation.
- We will only review two formulas, one which we'll use for LL rotations and LR rotation, the same thing applies for the other two formulas.

**LL Rotation**

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%208.png)

- The way it works is the following way:
    - So we have like a knot and we are pulling it to the right side from the uppermost corner, and if something is attached to the knot like on the side.
    - Once we stretch it to the right side its size will reduce on the left side and the attached thing will come on the right side.
    - Remember that no matter how big a tree is we only focus on the main three nodes to make the rotation.
    
    ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%209.png)
    

**LR Rotation**

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2010.png)

Here is another example:

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2011.png)

```cpp
**AVL.h**
struct NodeAVL {
    NodeAVL *lChild;
    int data;
    /* It is necessary that we maintain
     balance for every node in a
     AVL tree so this means we
     need to keep track of the height */
    int height;
    NodeAVL *rChild;
}*rootAVL = nullptr;

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

NodeAVL * LLRotation(NodeAVL *p){
    /* We should make p->lChild the root
     node and p->rLChild should
     become the lChild of p */
    NodeAVL *pLeft = p->lChild;
    NodeAVL *pLeftRight = pLeft->rChild;
    pLeft->rChild = p;
    p->lChild = pLeftRight;
    p->height = nodeHeight(p);
    pLeft->height = nodeHeight(pLeft);
    if(rootAVL == p)
        rootAVL = pLeft;
    return pLeft;
}

NodeAVL * RRRotation(NodeAVL *p){
    NodeAVL *pRight = p->rChild;
    NodeAVL *pRightLeft = pRight->lChild;
    pRight->lChild = p;
    p->rChild = pRightLeft;
    p->height = nodeHeight(p);
    pRight->height = nodeHeight(pRight);
    if(rootAVL == p)
        rootAVL = pRight;
    return pRight;
    
}

NodeAVL * LRRotation(NodeAVL *p){
    /*
     Plr will be the root,
     the rChild of plr will be p,
     pl will be plr's lChild
     */
    NodeAVL *pLeft = p->lChild;
    NodeAVL *pLeftRight = pLeft->rChild;
    pLeft->rChild = pLeftRight->lChild;
    p->lChild = pLeftRight->rChild;
    pLeftRight->lChild = pLeft;
    pLeftRight->rChild = p;
    pLeft->height = nodeHeight(pLeft);
    p->height = nodeHeight(p);
    pLeftRight->height = nodeHeight(pLeftRight);
    if(rootAVL == p)
        rootAVL = pLeftRight;
    
    return pLeftRight;
}

NodeAVL * RLRotation(NodeAVL *p){
    NodeAVL *pRight = p->rChild;
    NodeAVL *pRightLeft = pRight->lChild;
    pRight->lChild = pRightLeft->rChild;
    p->rChild = pRightLeft->lChild;
    pRightLeft->rChild = pRight;
    pRightLeft->lChild = p;
    pRight->height = nodeHeight(pRight);
    p->height = nodeHeight(p);
    pRightLeft->height = nodeHeight(pRightLeft);
    if(rootAVL == p)
        rootAVL = pRightLeft;
    return pRightLeft;
}

NodeAVL * recursiveInsertAVL(NodeAVL *p, int key){
    NodeAVL *t;
    if(p==NULL){
        t = new NodeAVL;
        t->data = key;
        t->height = 1;
        t->lChild = t->rChild = NULL;
        return t;
    }
    if(p->data > key)
    /* Because p->lChild is null now we will
     assign p->lChild to a new created node */
        p->lChild = recursiveInsertAVL(p->lChild, key);
    else
    /* Because p->rChild is null now we will
     assign p->rChild to a new created node */
        p->rChild = recursiveInsertAVL(p->rChild, key);
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

**main.cpp**
#include "AVL.h"

int main() {
    rootAVL = recursiveInsertAVL(rootAVL, 10);
    recursiveInsertAVL(rootAVL, 5);
    recursiveInsertAVL(rootAVL, 2);
    
    return 0;
}
```

### How to create a AVL Tree

Let's try to generate a tree by using the following numbers: 10, 20, 30, 25, 28, 27, 5

- Per every single insertion we must calculate the balance factor.
- We must calculate the balance factor, if a node is becoming imbalanced then we have to balance the node.
- If we encounter a tree that becomes imbalanced we must perform balance it right away by performing rotation on any side which makes the tree into a balanced tree.

The procedure starts out like this:

1. The first element is 10 which has a balance factor of 0 i.e. it is balanced

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2012.png)

1. The second element is 20 which makes up for a tree of balance -1 i.e. it is balanced.
    
    ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2013.png)
    

1. The third element is 30 which makes up an imbalanced tree
- Because this is a imbalanced tree we must perform RR-Rotations which will look like this:

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2014.png)

1. The fourth element is 25 which makes up a tree with a balance factor of -1 i.e. a blaanced tree

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2015.png)

1. The fifth element is 28 which makes up for a imbalanced tree

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2016.png)

- So in this case we must perform LR-Rotation to balance the tree

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2017.png)

1. The sixth element is 27 which makes an imbalanced tree

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2018.png)

- We must perform RL-Rotations

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2019.png)

1. The last element is 5 which makes up for an imbalanced tree

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2020.png)

- To balance the tree we must use LL rotations
- In conclusion this is the way the tree will look like

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2021.png)

- It is crucial for us to check the balance factor per every insertion, otherwise the binary search tree would look something like this, which does not make up for a AVL tree:

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2022.png)

- A binary tree is useful for searching, if we look for something on the binary search tree 6 comparations are required but for an AVL tree only two comparations are required for finding an element. **It is easier to look up for elements in a AVL tree.**
- **The searching time for a AVL tree is less than a Binary Search Tree.**

### Deletion from AVL Tree

- The deletion from an AVL tree is the same as the deletion from a binary search tree.
- The procedure for deletion is a follows:
    - First search for the key that we want to delete.
    - If we find the key we delete it, and the one who will take its place is the inorder predeccesor or the inorder succesor.

At the time of deletion, a node can become imbalanced and we need to perform rotations to avoid making it imbalanced. We can perform 6 rotations to balance them.

To see these 6 rotations in action we will take the three following trees.

![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2023.png)

The types of rotations available are the following ones:

1. L 1 - Rotation
    1. It holds L 1 because it is heavy on the left hand side, and the balance factor of the very first left child it is 1, so this is the reason why it is called L 1
    
    ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2024.png)
    
2. L -1 - Rotation
    1. If we delete an element and if the left child has a balance factor of -1 then we should perform L -1 Rotation.
    
    ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2025.png)
    
3. L 0 - Rotation
    1. If we delete an element and if the left child has a balance factor of 0 the we should perform L 0 Rotation.
    2. After deleting an element we can either take two paths, L 1 or L -1 rotation.
    
    ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2026.png)
    
4. R 1 - Rotation
5. R -1 - Rotation
6. R 0 - Rotation

### Height analysis of AVL Trees

Let's try to grasp the difference between height and nodes within AVL trees.

If the height is given let's try to find

- Minimum number of nodes: $n(h-2)+n(h-1)+1$t
    - If height is equivalent to 1 then the minimum num of nodes is 1.
    - If height is equivalent to 2 then the minimum num of nodes is 2.
    - If height is 3 then there will be 4 nodes, two left child nodes, one right child node.
    - If height is 4 then there will be at least 7 nodes.
    
    ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2027.png)
    
    - The pattern here is add the previous two values and add 1
    
    ![Untitled](12%20-%20AVL%20T%20668ea/Untitled%2028.png)
    
- Maximum number of nodes: $2^{h+1}-1$

We can see that the same rule form maximum nodes apply from binary trees.

If the nodes are given let's try to find the height:

- Minimum height: $\log_2(n+1)$
- Maximum height: Look in the table