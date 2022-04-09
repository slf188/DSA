# 10 - Trees

### Terminology of Trees

Let's try to understand a tree by taking a general form of a tree where each node contains alphabet letters that will help us understand it.

![Untitled](10%20-%20Trees%202691d/Untitled.png)

- **A tree is a collection of nodes where one node taken as root node and the rest of the nodes are divided into disjoint subsets and each subset is a tree or a subtree.**
- A tree contains edges i.e. connection or links with the other nodes.
- If there are $n$ nodes there will be $n-1$ edges.
    - Because for each node we can see there is a edge coming from the parent node that is above except for the root node.

The terms used for trees are the following:

1. Root
    1. The very first node on the top is the root node.
        
        ![Screen Shot 2021-10-25 at 20.40.42.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-25_at_20.40.42.png)
        
2. Parent & Child
    1. A node is a parent to its next descendents. 
    2. A child node is the descendent nodes which are children connected one edge away of the parent node.
        
        ![Screen Shot 2021-10-25 at 20.43.04.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-25_at_20.43.04.png)
        
    3. In this case D is the parent node and G, H and I are the child nodes.
3. Siblings
    1. Siblings are children of the same parent node.
        
        ![Screen Shot 2021-10-25 at 20.43.04.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-25_at_20.43.04.png)
        
    2. G, H, I are children of D. Which means they are siblings.
4. Descendents
    1. Descendents are all the set of nodes which can be reached from a particular node or under the node.
        
        ![Screen Shot 2021-10-25 at 20.47.49.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-25_at_20.47.49.png)
        
    2. For example for the node B. E, F, J, K and M are all descendents of B.
5. Ancestors
    1. For any node all the nodes along the path from that node to the root node are all ancestors.
        
        ![Screen Shot 2021-10-25 at 20.50.14.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-25_at_20.50.14.png)
        
    2. For example M. J, F, B, A are all ancestors.
6. Degree of a node
    1. Degree of a node means the number of children a node has.
    2. We only take into consideration direct children, not all descendents
        
        ![Screen Shot 2021-10-25 at 20.52.05.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-25_at_20.52.05.png)
        
    3. For example the degree of the L node is two.
    4. If a node doesn't have any child nodes then the degree will be zero.
7. Internal & External nodes
    1. Internal & external nodes are also called as non-leaf nodes and leaf nodes.
    2. Nodes with degree zero are called as leaf nodes or external nodes
        
        ![Screen Shot 2021-10-25 at 20.56.49.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-25_at_20.56.49.png)
        
    3. E, M, K, C, G, N, O and I are leaf nodes or external nodes.
    4. Those nodes who's degree is greater than zero are internal nodes or non-leaf nodes.
8. Levels
    1. The level of a tree starts from 1 onwards, the next children belong to the level 2, their children at level 3 and so onwards.
    
    ![Untitled](10%20-%20Trees%202691d/Untitled%201.png)
    
9. Height
    1. The height of a tree starts from 0 onwards, the next children are in height 1 and so forth.
    
    ![Untitled](10%20-%20Trees%202691d/Untitled%202.png)
    
10. Forest
    1. A collection of trees is called as forest.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%203.png)
        
    2. Here in total there are three trees. B, C and D.
    3. If we combine all the forest and convert them into a single collection then we can introduce a node that will ge connected to the different forests.

### Binary Tree

- A binary tree is a tree that is of degree 2.
- Every node of a binary tree can have either 0, 1 or at most 2 children.
- As there are only two children we can give names to the children, left child and right child.

![Untitled](10%20-%20Trees%202691d/Untitled%204.png)

Some more examples of binary trees can be the following:

![Untitled](10%20-%20Trees%202691d/Untitled%205.png)

- This is called a left-skewed tree
    
    ![Untitled](10%20-%20Trees%202691d/Untitled%206.png)
    
- This is called a right-skewed tree
    
    ![Untitled](10%20-%20Trees%202691d/Untitled%207.png)
    

### Number of binary trees using N nodes

- What we are trying to say is suppose some number of nodes are given like $n=3$, using these 3 nodes how many different binary trees can be generated.
- During the review of this topic we will learn about two type of nodes.
1. Unlabelled Nodes
    1. An unlabelled node is a node that are empty i.e. they contain no alphabets we can use to identify them like with alphabet letters or numbers.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%208.png)
        
    2. The number of possible binary trees that can be generated from $n=3$ are as follows:
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%209.png)
        
    3. The number of possible binary trees that can be generated from $n=4$ are 14 different binary trees.
    4. The formula for getting the number of possible binary trees is:
        1. The name of this formula is 
        
        [Catalan number | Wikiwand](https://www.wikiwand.com/en/Catalan_number)
        
    
    $$
    T(n)=\frac{^{2n}C_n}{n+1}
    $$
    
    Let's try to calculate the number of possible binary trees if we have $n=5$:
    
    $$
    T(5)=\frac{^{2*5}C_5}{5+1}=\frac{^{10}C_5}6=\frac{\frac{10*9*8*7*6}{5*4*3*2*1}}{6}=3*2*7=42
    $$
    
    - We can also generate the number of possible binary trees by using a different formula:
    
    ![Untitled](10%20-%20Trees%202691d/Untitled%2010.png)
    
    The new formula for generating possible binary trees is the following:
    
    $$
    T(n)=\sum_{i=1}^n T(i-1)*T(n-i)
    $$
    
2. Labelled Nodes
    1. A labelled node is a type of node that is labelled
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2011.png)
        
    2. If there are labelled nodes our duty is to again find out the number of possible binary trees can be generated
    3. Because we are dealing with labelled nodes we will get even more possible binary trees, for example if we just try to generate a part of a $n=3$ manually it will look something like this:
    
    ![Untitled](10%20-%20Trees%202691d/Untitled%2012.png)
    
    - This means we should shift our equation to use factorials i.e. $6=3!$
    - One of the five shapes can be shaped in 3! ways, second shape again it can be shaped in 3! ways, and so forth
    - The equation look like this taking into consideration the factorials:
        - This formula has two parts, the left part is used to generate the number of shapes and the second part is used to generate the number of permutations.

$$
T(n)=\frac{^{2n}C_n}{n+1}*n!
$$

### Height vs Nodes in Binary tree

- In this topic we will compare the formulas used for height and nodes.
- The formulas consist on taking the height of a binary tree, in find what could be the minimum and maximum number of nodes and viceversa if the number of nodes is given what could be the minimum height and what could be the maximum height.

**Height**

Let's see the following examples:

![Untitled](10%20-%20Trees%202691d/Untitled%2013.png)

- If we analyze this graph we can conclude that if a binary tree has a height of 1 it will at least have two nodes and at most it should have 3 nodes.

- If we analyze this graph we can conclude that if a binary tree has a height of 2 it will at least have 3 nodes and at most it should have 7 nodes.

![Untitled](10%20-%20Trees%202691d/Untitled%2014.png)

![Untitled](10%20-%20Trees%202691d/Untitled%2015.png)

- If we analyze this graph we can conclude that if a binary tree has a height of 3 it will at least have 4 nodes and at most it should have 15 nodes.
- Let's do some observations to find if there is any pattern to come up with a formula:
    - If hight is per say 1 the minimum is 2, if height is 2 min is 3. So we can say that the minimum amount of nodes is $min+1$
    - It appears to be like there is no pattern for finding the maximum amount of nodes possible, although there is something we should acknowledge the following:
    
    ![Untitled](10%20-%20Trees%202691d/Untitled%2016.png)
    
    - With this in mind we can see that the formula for getting the max number of nodes is the G.P series formula:
    
    $$
    G.P \; Series \quad a+ar+ar^2+ar^3+...+ar^k=\frac{a(r^{k+1}-1)}{r-1}
    $$
    
    - G.P stands for Geometry Progression
    
    $$
    a=1 \quad r=2\\1+2+2^2+2^3+...+2^h=\frac{1*(2^{h+1}-1)}{2-1}=2^{h+1}-1\\2^{3+1}-1\\=2^4-1\\=16-1\\=15
    $$
    
    - To simplify this we can conclude that the formulas for min and max nodes is:
    
    $$
    min \ nodes \quad n=h+1\\max \ nodes \quad n=2^{h+1}-1
    $$
    

**Nodes**

- Now let's do the same work but in the other way around. If nodes are given what will be the min and max height.

Let's see the following examples:

![Untitled](10%20-%20Trees%202691d/Untitled%2017.png)

- If we analyze this graph we can conclude that if a binary tree has 15 nodes it will at least have a height of 3 and at most it should have a height of 14.

![Untitled](10%20-%20Trees%202691d/Untitled%2018.png)

- If we analyze this graph we can conclude that if a binary tree has 7 nodes it will at least have a height of 2 and at most it should have a height of 7.

- If we analyze this graph we can conclude that if a binary tree has 3 nodes it will at least have a height of 1 and at most it should have a height of 2.

![Untitled](10%20-%20Trees%202691d/Untitled%2019.png)

- We can conclude that this is just the opposite case of the height problems, not just in a sense of finding the opposite elements but in a sense that the formulas are opposite as well.
- To summerize everything let's write down the formula of when height is given and nodes are given:
    - If height is given
    
    $$
    Min \ Nodes \quad n=h+1\\Max \ Nodes \quad n=2^{h+1}-1
    $$
    
    - If nodes are given

$$
Min \ Height \quad h=\log_2(n+1)-1\\Max \ Height \quad h=n-1
$$

### Internal Nodes vs External Nodes in Binary Trees

- Let's understand the relationship between internal nodes and external nodes in a binary tree.
- Remember that an external node is also known as leaf nodes which have a degree of 0.
- Remember that an internal node is also known as a non-leaf node which have a degree > 0

![Screen Shot 2021-10-27 at 00.11.47.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-27_at_00.11.47.png)

- Let's analyze the following trees:
    - In the three trees we are counting the number of nodes that have a degree of 2, 1 and 0.
    - We can see there is a relationship between degree 2 and degree 0. That is $deg(0)=deg(2)+1$
    - There is no pattern in degree 1.

### Strict Binary Tree

**Concept**

- Strict binary trees are also called as **Proper Binary Tree** or **Complete Binary Tree**.
- A general binary tree can have 0, 1 or 2 children but in a strict binary tree it can only have either 0 children or 2 children, there cannot be one child.

![Untitled](10%20-%20Trees%202691d/Untitled%2020.png)

![Screen Shot 2021-10-27 at 00.30.46.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-27_at_00.30.46.png)

- In the previous graph we can see six trees, only the two first trees are strict trees and the rest are not even binary trees.

To understand strict binary tree we will review the most important topics that are height, nodes, internal and external nodes.

**Height vs Nodes**

- The formula for the maximum number of nodes is the exact same as the one formula from a general form binary tree.
- The only difference is the minimum number of nodes because every node must have either 0 or 2 children. This means we need a formula for the minimum number of nodes here.

![Untitled](10%20-%20Trees%202691d/Untitled%2021.png)

- The formula for the number of nodes when height is given is:

$$
min = 2*height + 1\\max = 2^{h+1}-1
$$

- The formulas for the height when nodes are given is:

$$
min = \log_2(n+1)-1\\ max = \frac{n-1}2
$$

**Internal nodes vs External nodes**

- Internal nodes are nodes with degree > 0 and external nodes are nodes with degree = 0

![Untitled](10%20-%20Trees%202691d/Untitled%2022.png)

- There is a pattern here, if $i = 0$, then $e = i + 1$. That is external nodes are one node greater than internal nodes.

### N-Ary Trees

- N is the degree of a tree. Degree means every node in a tree can have at most n children, not more than n children.

For example:

![Untitled](10%20-%20Trees%202691d/Untitled%2023.png)

![Untitled](10%20-%20Trees%202691d/Untitled%2024.png)

- In the 3-ary tree we can conclude that every node can have 0, 1, 2 or 3 children. The maximum capacity of children is 3.
    - The third tree is a binary tree but there is no problem because we clearly stated that every node has the capacity to have three children but if they have less then there is no problem with that at all.

**Strict N-ary trees**

- A strict n-ary tree is a tree which every node can have either 0 children or exactly n children.

![Screen Shot 2021-10-27 at 23.41.44.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-27_at_23.41.44.png)

**Analysis of n-ary trees**

- We will do analysis of height vs nodes, we have done the analysis for height vs nodes on binary trees but we will now do it for strict n-ary trees.

![Untitled](10%20-%20Trees%202691d/Untitled%2025.png)

- If height is given:

$$
min \quad n=degree*height +1\\max\quad n=\frac{degree^{height+1}-1}{degree-1}
$$

- If nodes are given:

$$
min\quad h = \log_{degree}[n(m-1)+1]-1\\ max\quad h = \frac{n-1}m
$$

Now let's switch on analyzing the number of internal and external nodes.

![Untitled](10%20-%20Trees%202691d/Untitled%2026.png)

- The pattern here is we can get the number of external nodes with the following equation $e=2*i+1$ or generally it would be $e=(degree-1)*i+1$

## Representation of a binary tree

- There are two ways of representing a binary tree
    - Array Representation
    - Linked Representation

### Array Representation

![Untitled](10%20-%20Trees%202691d/Untitled%2027.png)

- Imagine we have the following tree and the following array here.
- For storing a binary tree in an array we have to store two things
    - All the elements
        - We can loop through the elements of the tree and place them inside the array.
        - We must store the elements level by level
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2028.png)
        
    - The relationship between those elements (e.g. A is the parent of B and C or B is the left child of A and C is the right child of A)
        - The indexes of the array will help us preserve the relationship of the elements
        - We need to make a table to see how the relationships between elements works:
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2029.png)
        
        - In the fourth row we can see the formulas we will use to maintain the relationship between nodes. This is the only way because remember binary trees can only store elements ranging from 0 to 2, we don't need to worry about a 3rd child.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2030.png)
        
- If we maintain the parent and child relationship then we can produce a tree back again

### Linked Representation

- We say linked representation and not linked list representation because list means linear, and a tree is a non linear representation.
- A linked list representation means we will be using nodes, we will use the structure of a doubly linked list
    
    ![Untitled](10%20-%20Trees%202691d/Untitled%2031.png)
    
- Let's try to represent a tree with the node structure shown above i.e. for every node in a binary tree we will create this structure node.

![Untitled](10%20-%20Trees%202691d/Untitled%2032.png)

- This structure will be dinamically created so it means we must create it in heap, whereas in array representation an array can be represented in the stack or in heap.
- There is a pattern in this type of representations, if there are n nodes there will definitely $n+1$ null nodes.

![Untitled](10%20-%20Trees%202691d/Untitled%2033.png)

### Full vs Complete Binary Tree

- Let's learn about full binary tree and complete binary tree, then we will learn about the difference between them.

**Full Binary Tree**

- A full binary tree is a binary tree of height h having maximum number of nodes.
- Remember that the formula for getting the maximum number of nodes when height is given is $n=2^{h+1}-1$

![Untitled](10%20-%20Trees%202691d/Untitled%2034.png)

**Complete Binary Tree**

- If a binary tree is represented in an array, then there should be any blank spaces or no skipping in between the elements, if there are blank spaces then it is not a complete binary tree.

![Untitled](10%20-%20Trees%202691d/Untitled%2035.png)

- This binary tree is complete because there are no blank spaces.

![Untitled](10%20-%20Trees%202691d/Untitled%2036.png)

- This binary tree is not complete because there are two blank spaces.

### Strict vs Complete Binary Tree

- Let's remember that a strict binary tree is a binary tree that can have either no children or 2 children.
    - There are occassions in which a strict binary tree is called a complete binary tree.
    - If we store this in an array there will always be blank spaces.
- A complete binary tree on the other hand is when it is represented in an array there should be no skipping when filling the elements.
    - Another definition for complete binary tree is when the height is h, then when up to h -1 it is full, and the last elements are filled from left to right.
    - There are occassions in which a complete binary tree is called Almost Complete Binary Tree.

![Screen Shot 2021-10-28 at 20.04.55.png](10%20-%20Trees%202691d/Screen_Shot_2021-10-28_at_20.04.55.png)

## Binary Tree Traversals

- Traversing means visiting all the elements.
- If a data structure is linear, we can traverse it in two methods, from first to last or from last to first.
- When a data structure is non-linear like in the case of Trees, these are the possible methods:
    - Preorder: visit(node), Preorder(leftSubTree), Preorder(rightSubTree)
        - Which means visiting a node first, then perform preorder on its left subtree and on its right subtree.
    - Inorder: Inorder(left), visit(node), Inorder(right)
        - Perform inorder traversal on the left subtree, then visit the node and perform inorder on the right subtree.
    - Postorder: Postorder(left), Postorder(right), visit(node)
        - Perform postorder on the left subtree, then postorder on the right subtree and finally visit the node.
    - Levelorder: Level by level
        - Visit all the nodes level by level.

Examples:

![Untitled](10%20-%20Trees%202691d/Untitled%2037.png)

Let us see a bigger tree and see how it is traversed by using the four methods we reviewed previously.

- If we are dealing with a big tree we should break it into small parts.

![Untitled](10%20-%20Trees%202691d/Untitled%2038.png)

This method of breaking the tree into small parts is a little to tedious to do, so instead let us review some other methods of traversing through a binary tree.

### Easy Method -  1

- Preorder
    - Begin by drawing a line in the bottom, from the left hand side strech a line a connect it to the bottom line, for every node we repeat the same process.
    - Scan the line from left to right and print the output.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2039.png)
        
- Inorder
    - Begin by drawing a line in the bottom, from the middle of a tree node connect a line a connect to the bottom, for every tree we repeat the same process.
    - Scan the line from left to right and print the output.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2040.png)
        
- Postorder
    - Begin by drawing a line in the bottom, from the right hand side strech a line a connect it to the bottom line, for every node we repeat the same process.
    - Scan the line from left to right and print the output.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2041.png)
        

### Easy Method - 2

- Preorder
    - On every node draw a line on the left-hand side, and then start from the top and go along the boundaries of the tree and print every node we encounter throughout the way.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2042.png)
        
- Inorder
    - On every node draw a mark on the bottom of each node, and then start from the top and go along the boundaries of the tree and print every node we encounter throughout the way.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2043.png)
        
- Postorder
    - On every node draw a line on the right-hand side, and then start from the top and go along the boundaries of the tree and print every node we encounter throughout the way.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2044.png)
        

### Easy Method - 3

- Preorder
    - Start from root and take a finger around the boundaries of the tree, print every node we encounter when moving our finger around the tree.
        
        ![postorder.gif](10%20-%20Trees%202691d/postorder.gif)
        
- Inorder
    - Start from root and take a finger around the boundaries of the tree, print every node we encounter taking in consideration the bottom of the node.
        
        ![inorder.gif](10%20-%20Trees%202691d/inorder.gif)
        
- Postorder
    - Start from root and take a finger around the boundaries of the tree, print every node we encounter taking in consideration the right-hand side of the node.

### Creating a Binary Tree

- Let's first learn how to represent a binary tree using Linked Representation.
- For generating a binary tree we can start by generating it from the root node, then we can proceed to create the left child and the right child.
- Before creating space for a left child or a right child we should check if they exist or not.
- We will generate it level by level

Steps:

- **For creating a binary tree we need a Queue data structure**
    - The first step is create a root node, insert the value of the root node into this node and insert the address from the node into the first index of the queue.
    - We only store the addresses in the queue, not the values.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2045.png)
        
    - Now we are ready for repeating the procedure.
    - Take a temporary pointer p on the root node, starting from that node ask if there is a left child. If so then take a temporary pointer t and insert the value and set the pointers as null and make the p node point on t. Then insert the newly created node t onto the queue.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2046.png)
        
    - Next, for the same node p ask if there is a right child or not, if so then take the temporary pointer and create a new node and insert the value and let p's right child point onto it.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2047.png)
        
    - Then to continue we must take out the next address from the queue which in this case is 210, and make the pointer p point on that location, being there ask the same questions, is there a left child or a right child. If there is no child the value will be simply -1.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2048.png)
        
    - We must continue taking out the addresses of the queue until it is empty. At that point we can stop. The end of the procedure will look like this:
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2049.png)
        

```cpp
**Queue.h**
struct Node {
    Node *lChild;
    int data;
    Node *rChild;
};

struct Queue {
    int size;
    int rear;
    int front;
    Node **array;
};

void createQueue(Queue *q, int size){
    q->size = size;
    q->array = new Node*[q->size];
    q->front = -1; q->rear = -1;
}

void enqueue(Queue *q, Node *x){
    if (q->rear == q->size - 1)
        cout << "Queue is full\n";
    else {
        q->rear++;
        q->array[q->rear] = x;
    }
}

Node * dequeue(Queue *q){
    Node *x = NULL;
//    int x = -1;
    if (q->front == q->rear)
        cout << "Queue is empty\n";
    else {
        q->front++;
        x = q->array[q->front];
    }
    return x;
}

int isEmpty(Queue q){
    return q.front==q.rear;
}

**main.cpp**
#include "Queue.h"
****Node *root = NULL;

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

int main() {
    createBinaryTree();
    return 0;
}

» Print root value
5
Enter left child of 5
8
Enter right child of 5
6
Enter left child of 8
-1
Enter right child of 8
9
Enter left child of 6
3
Enter right child of 6
-1
Enter left child of 9
4
Enter right child of 9
2
Enter left child of 3
-1
Enter right child of 3
-1
Enter left child of 4
-1
Enter right child of 4
-1
Enter left child of 2
-1
Enter right child of 2
-1
```

### Tree traversal

- Making the functions for preorder, inorder and postorder is just as simple as printing your first hello world program.

```cpp
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
    preorder(root);
		inorder(root);
		postorder(root);
    return 0;
}

» 5894263
8492536
4298365
```

### Level Order Traversal

- Level order means traversing all the nodes of a tree level by level by first visiting the root node and visiting the left child and right child, then children of the left child and right child and so on.
- This procedure requires a queue.
    1. First take a pointer p in the root node, print its value and store its address on the first index of the queue.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2050.png)
        
    2. Take out the address in queue and visit its left child, print its value and insert its address on queue and do the same for its right child.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2051.png)
        
    3. We repeat this address, the procedure looks like this in the end. We can see that this procedure is the exact same as creating a binary tree.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2052.png)
        

```cpp
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

int main() {
    createBinaryTree();
    levelOrder(root);
    cout << endl;
    return 0;
}

» 5869342
```

### Can we generate a tree from traversals?

- In the normal way of how things work from the tree we find traversals.
- Let's analyze and see if we can use any of the three methods of traversals to generate a tree.

**Preorder**

- Let's see if we can generate a tree using the preorder traversal method
    
    ![Untitled](10%20-%20Trees%202691d/Untitled%2053.png)
    
- As we can see if we try to generate a tree using the preorder method, five trees are possible for three elements. And in our case we are only looking to generate a single tree.
- To shorten this comparison of methods, we can also conclude that by using the postorder method five trees are possible for three elements, so we must also discard it.

**Conclusion**

- The amount of possible trees cannot be 1 for any of the three methods we know, we can only generate the the number of trees defined by this equation:

$$
\begin{vmatrix}
Preorder\\
Inorder\\Postorder
\end{vmatrix}=\frac{^{2n}C_n}{n+1}
$$

- And for more than one tree we can conclude it will be:

$$
\begin{vmatrix}
Preorder\\
Postorder
\end{vmatrix}=1+
$$

- The only traversals that can give us a tree are

$$
Preorder + Inorder\\Postorder+Inorder
$$

- Inorder is possible because it can help us only if we know the root so we can then differentiate the left subtree and the right subtree.

### Generating tree from traversals

- Let's take the following example and show how we can trace this:
1. Create a node, and place all the elements from inorder without changing the order and place them inside
    
    ![Untitled](10%20-%20Trees%202691d/Untitled%2054.png)
    
2. Scan through preorder by taking one element at a time
    1. For the first element in preorder we will mark it as the root of the tree i.e 4.
    2. Search for the first element from preorder in the node that we just created.
    3. When we find it we take the element out and place it in one node.
    4. For the rest of the elements we place 7, 6, 9, 3 on the left side of the root node and 5, 8, 2, 1 on the right-hand side of the root node.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2055.png)
        
    5. Then we can proceed on to moving to the next element in preorder, in this case it will be 7. 
    6. See if it belongs to the left-hand side or the right-hand side. And place the lements either on the left-hand side or in the right-hand side.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2056.png)
        
    7. The rest of the nodes will make the procedure look like this in the end.
        
        ![Untitled](10%20-%20Trees%202691d/Untitled%2057.png)
        

### Height and count of binary tree

![Untitled](10%20-%20Trees%202691d/Untitled%2058.png)

- Let's take the binary tree above as an example for this topic
- We can write a function that counts the number of nodes using recursion:

```cpp
int count(Node *p){
    int x, y;
    if(p != NULL){
        x = count(p->lChild);
        y = count(p->rChild);
        return x + y + 1;
    }
    return 0;
}

int main() {
    createBinaryTree();
    cout << "The number of nodes is " << count(root) << endl;
    return 0;
}

» The number of nodes is 10
```

- The complete procedure looks like this:

![Untitled](10%20-%20Trees%202691d/Untitled%2059.png)

```cpp
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
        else
            return y + 1;
    }
    return 0;
}

int main() {
    createBinaryTree();
    cout << "The sum of all the elements is " << sumOfData(root) << endl;
		cout << "The height is " << height(root) << endl;
    return 0;
}

» The sum of all the elements is 66
The height is 5
```

### Count leaf nodes of a binary tree

- Leaf nodes are nodes that nodes with degree zero.
- Non-leaf nodes are nodes with degree greater than zero
- Leaf nodes are external nodes
- Non-leaf nodes are internal nodes

Let's try to count the number of leaf nodes by taking the previously seen tree as an example.

```cpp
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
    cout << "The number of leaf nodes is " << countLeafNodes(root) << endl;
    cout << "The number of nodes with degree one is " << countDegreeOneNodes(root) << endl;
    cout << "The number of nodes with degree two is " << countDegreeTwoNodes(root) << endl;
    cout << "The number of nodes with degree one or two is " << countDegreeOneOrTwoNodes(root) << endl;
    return 0;
}

» The number of leaf nodes is 4
The number of nodes with degree one is 3
The number of nodes with degree two is 3
The number of nodes with degree one or two is 6
```

### Count nodes function using recursion

We can modify the count function to use recursion and make it more readable:

```cpp
int countUsingRecursion(Node *p){
    if(p==NULL)
        return 0;
    return countUsingRecursion(p->lChild) + countUsingRecursion(p->rChild) + 1;
}

int main(){
		createBinaryTree();
		cout << "The number of nodes using the recursion function is " << 
		countUsingRecursion(root) << end;
		return 0;
}
```