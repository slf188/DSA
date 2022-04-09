# 11 - Binary Search Trees

### What is Binary Search Tree?

Let's take an example binary tree:

![Untitled](11%20-%20Binar%20ab885/Untitled.png)

- This is a binary tree in which for every node, all the elements on its left subtree are smaller than that node and all the elements on its right subtree are bigger than that node.
- If we see this is clearly the case in the tree, the fundamental rule applies in the root node as well as in the left node and the right node.
- This binary tree is useful for searching so we now understand the reason for its name.
- The reason a binary search tree is useful for searching is because suppose we are looking for the key value 40, then the procedure will look like this:
    - Start from the root node, is it 40? No, 40 is greater than the root node. So definetly 40 is on the right-hand side.
    - Go to 50, is it 40? No, 40 is smaller than 50. So definetly the 40 is on the left-hand side.
    - Go to 40, is it 40? Yes, element is found.
- In conclusion this is extremely useful for searching an element in less number of comparations. This is very similar to binary search.
- **The search time depends on the height of the tree.**

### Properties of a binary search tree

1. There are no duplicate elements in a binary search tree.
2. The inorder traversal of a binary search tree, will output the list of elements in sorted order.
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%201.png)
    
3. The number of binary search trees that can be generated for n nodes if n nodes are given will differ
    1. Let's see how many different shapes can be generated if we have 3 nodes. Remember that if we take the inorder of a binary search tree we should get the elements in sorted order.
        
        ![Untitled](11%20-%20Binar%20ab885/Untitled%202.png)
        
    2. If we change the order of the following five shapes we will not get the same inorder ouput.
    3. For all these shapes we get the same inorder output. The number of binary search trees that can be generated are based on the Catalan Numbers:

$$
T(n)=\frac{^{2n}C_n}{n+1}
$$

### Representation

- Binary search trees can be represented using Linked Representation.
- We can also implement it using arrays but it is more common to it being implemented using Linked Representation.

The link representation for the tree looks like this:

![Untitled](11%20-%20Binar%20ab885/Untitled%203.png)

### Searching in a binary search tree

![Untitled](11%20-%20Binar%20ab885/Untitled%204.png)

- Let's take the binary search tree from above as an example
- Suppose we want to get the element 25.
- The procedure to get to 25 is the following one:
    - Take a temprorary pointer t on the root node
    - Wherever t is pointing check for the data, and compare with the key
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%205.png)
    
    - In this case t is 30 which is smaller than 25, so move t to the left child
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%206.png)
    
    - Now repeat the step, check the data and compare with the key. In this case we move t to the right side
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%207.png)
    
    - Again repeat, this time t is equal to the key so the procedure is now concluded.
    - We got the element 25, after making three comparations.
    - The maximum number of comparations depend on the height of the tree.
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%208.png)
    
    - An unsuccesful search i.e. when we never encounter the seeked key we will get a NULL value at the end of the procedure.

```cpp
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

int main() {
		// Create the same tree we saw previously
    createBinaryTree();
    if(rSearch(root, 23))
        cout << "The element was found\n";
    else
        cout << "The element was not found\n";
    return 0;
}

» The element was not found
```

### Inserting in a binary search tree

- Let's use the same binary search tree
- The procedure for inserting a key value is the following:
    - Suppose I want to insert the key value 38
    - First we need to perform search with the help of a tailing pointer and a temporary pointer.
    - In this case our output will be null because 38 is not present inside the tree, which means we can now proceed on to the insertion part.
    - To achieve this we should search for 38 with pointer t along with a tail pointer r.
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%209.png)
    
    - We should repeat the same procedure as in the search function. When t is in 40, r should be in 30, when t is in 35, r should be in 40 and when t is in 38, r should be in 35.
    - When t becomes null means we should insert the key value on the right child of 35 i.e. the location of r.
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%2010.png)
    

### Recursive insert in Binary Search Tree

- We can generate an entire binary search tree by inserting keys one by one
- When the pointer is null, create the data and initialize the pointers

```cpp
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

int main() {
    root = recursiveInsert(root, 30);
    recursiveInsert(root, 20);
    recursiveInsert(root, 25);
    return 0;
}
```

This will look like this:

![Untitled](11%20-%20Binar%20ab885/Untitled%2011.png)

### Deleting from a binary search tree

Let's take the following binary search tree as an example and see how we can delete any key:

![Untitled](11%20-%20Binar%20ab885/Untitled%2012.png)

The procedure for deleting a key is the following one:

1. Let's say I want to delete 25
2. The procedure is search for the key, if found delete it.
3. Start from the root node, 30 is greater so go to 20, 20 is smaller so go to 25, delete it.
4. If we delete a node we should make the parent's link as NULL.

![Untitled](11%20-%20Binar%20ab885/Untitled%2013.png)

1. But let's say I want to delete 42, we have a problem, 42 has a right child node.
2. If 42 has a child then its child will take its position

![Untitled](11%20-%20Binar%20ab885/Untitled%2014.png)

1. If we want to delete the key 30, which in this case is the root node then it can get quite messy, but fear not the procedure in this case is:
2. We must find the indorder precessor and succesor of 30 i.e. which nodes comes before and after 30, in this case it will be 25 and 35

![Untitled](11%20-%20Binar%20ab885/Untitled%2015.png)

1. Then we can pick either the inorder precessor or succesor to take the place of 30, it doesn't matter which node we chose either the precessor or succesor will make no difference when generating a new tree

![Untitled](11%20-%20Binar%20ab885/Untitled%2016.png)

1. To find the inorder predecessor or succesor we can shorten the inorder function by performing the following procedure:
    1. For finding the inorder predecessor, go the the left subtree of the root node, then go to the right-most child of the left subtree.
    2. For the case of an inorder sucesssor, go the the right subtree of the root node, then go to the left-most child of the right subtree.
    3. By doing this step we avoid making inorder traversal

![Untitled](11%20-%20Binar%20ab885/Untitled%2017.png)

1. If we encounter this tree, and we want to delete 30, then because 40 is the inorder succesor of 30, 40 should take its place and what about 50? 50 should then take the place of 40 so the tree will end up looking like this:

![Untitled](11%20-%20Binar%20ab885/Untitled%2018.png)

```cpp
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
    
    if(p == NULL)
        return NULL;
    if(p->lChild == nullptr && p->rChild == NULL){
        if(p==root)
            root = NULL;
        delete p;
        return NULL;
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
```

### Generating a binary search tree from preorder

Let's take the following preorder list:

![Untitled](11%20-%20Binar%20ab885/Untitled%2019.png)

The procedure for generating a binary search tree is the following:

1. We first need a stack, scan through this preorder list by taking one element at a time
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%2020.png)
    
2. For the first elemen element we create a new node and add a temporary pointer p on it and make root point on it
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%2021.png)
    
3. Now we move on to the next node which is 20, check if it is smaller than 30, if so then we create a new node with a temporary pointer t, set the value and let p's left point on it. Then push 30 into the stack and move p on the left node
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%2022.png)
    
4. And from now on this will repeat until we reach the last element in the preorder list, remember we check from the last checkpoint of pointer p, not from root anymore.
5. But when we push the element 15 we should be cautious because:
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%2023.png)
    
    1. 15 is greater than 10 so it belongs to its right child node
    2. But is it the right thing to put in in there blindly or not? No, we must first confirm one thing
    3. 15 should be in between the top-most element in the stack 20 and 10, because it is smaller than 20 and bigger than 10.
    4. The top-most element in the stack currently is 20, the elements in the stack should go from lowest to biggest in the stack
    5. Don't push the address of 10 in the stack yet
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%2024.png)
    
    f. When we have a left child we push the adress and move forward to the next node. But when it is a right child just go onto the new node and don't push the address.
    
    g. The role of 10 is over, we don't need it anymore on the stack.
    
6. When we encounter the element 25 we should also be cautious
    1. Before we insert 25 as a right child node of 15 we should do a prior check
    2. Check if 25 is laying in between the range of 15 and the uppermost element in the stack, in this case 20
    3. Because it is not in between 15 and 20 then it will not come as a right child of 15.
    4. So we need to pop out 20 from the stack and move the pointer p back to 20
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%2025.png)
    
    e. We don't move i to the next element yet, because 25 has yet to be inserted in the tree.
    
    f. 25 is greater than 20, but does it lie in between 20 and the topmost element in the stack 30? Yes it is in between so insert it as the left child of 20 and move p onto its location
    
    ![Untitled](11%20-%20Binar%20ab885/Untitled%2026.png)
    
7. When there is no element to compare in the stack we should compare it with $\infty$

The final result looks like this:

![Untitled](11%20-%20Binar%20ab885/Untitled%2027.png)

```cpp
#include <stack>

void createFromPreorder(int preorder[], int size){
    stack<Node*> st;
    Node *t, *p = root;
    int i = 0;
    root = new Node;
    root->data = preorder[i++];
    root->lChild = root->rChild = nullptr;
    p = root;
    while(i < size){
        if(preorder[i] < p->data){
            t = new Node;
            t->data = preorder[i++];
            t->lChild = t->rChild = nullptr;
            p->lChild = t;
            st.push(p);
            p = t;
        } else {
            if(preorder[i] > p->data && preorder[i] < st.empty() ? 32767 : st.top()->data){
                t = new Node;
                t->data = preorder[i++];
                t->lChild = t->rChild = nullptr;
                p->rChild = t;
                p = t;
            } else {
                p = st.top();
                st.pop();
            }
        }
    }
}

int main() {
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre)/sizeof(pre[0]);
    createFromPreorder(pre, n);
    return 0;
}
```

### Drawbacks of Binary Search Tree

- The heigh of a binary tree can be as minimum as $O(\log_n)$ and as maximum as $O(n)$. It depends on how we insert the keys.
- There is no control over the height of a binary search tree. It all depends on the order of insertion.
- We need a method to control the height of a binary search tree, in that case AVL Trees are here to help us tackle this problem.
- AVL Trees as a default are height balanced binary search trees

![Screen Shot 2021-11-13 at 00.55.34.png](11%20-%20Binar%20ab885/Screen_Shot_2021-11-13_at_00.55.34.png)

![Screen Shot 2021-11-13 at 00.52.18.png](11%20-%20Binar%20ab885/Screen_Shot_2021-11-13_at_00.52.18.png)