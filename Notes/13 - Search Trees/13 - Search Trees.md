# 13 - Search Trees

## 2-3 Trees

- 2-3 Trees are search trees, like in the case of binary search trees which the fundamental rule states that it can only contain one or two children.
- They have a degree of 3.
- They are also known as Multiway Search Tree or M-way.
- They are height balanced search trees called B-Trees.
- They have 2 rules for balancing the height:
    - All leaf nodes should be at the same level.
    - Every node must have at least half of the children, the value we get from the division should use the ceil function i.e. 2.5 will be 3.
    
    $$
    [\frac n2]=[\frac32]=2
    $$
    

The structure is the following:

- The degree of every node is 3 i.e. every node can have 3 children.
- We can identify every node by left, middle and right. The child values should respect the following condition:

 $l<K_1\\K_1<m<K_2\\K_2<r$

- When 3 children are possible then 2 children are possible, those two keys should be: $k_1<k_2$
- Because this is a search tree then it cannot have duplicate elements.

![Untitled](13%20-%20Searc%208fc01/Untitled.png)

### How to insert or create a 2-3 tree?

- The set of keys we will use for this example are the following ones: 20, 30, 40, 50, 60, 10, 15, 70, 80.
- The procedure is as follows:
    - Insert 20, first we should create a root node holding 20.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%201.png)
    
    - Next insert 30, so 30 will come after 20, it should be inserted on the same root node but separated with a boundary.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%202.png)
    
    - Now insert 40, 40 comes after 30 but there is no space which means that the degree is 3 and the keys are two only. So because it is filled we should split the node into two, one on the left and one on the right
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%203.png)
    
    - An important thing to notice is **binary search trees grow downwards, but in the case of 2-3 trees they grow upwards**. That's how they maintain balance.
    - Now insert 50, start by comparing with the data in the root, 50 is greater than 30 and it doesn't hold another key, go to 40, 50 must be next because 50 does not exist and there is not next key.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%204.png)
    
    - Now 60, start checking from the root node first, 60 is greater than 30 and 30 has not next node so go to its children. 60 is greater than 40 and greater than 50 but there is no space so we should now split.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%205.png)
    
    - Next 10, start from the root node, 10 is less than 30, 10 is less than 20 so it should be here, 20 must be shifted as the next element from that node.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%206.png)
    
    - Now 15, it is less than 30, greater than 10 and less than 20 so it should come in between but there is no space. So we must now split.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%207.png)
    
    - Next 70, it is greater than 30, 50, 60 so it should go here:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%208.png)
    
    - Next 80, it is greater than 30, 50, and 70 but there is no space so we should split.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%209.png)
    

### Deletion of elements in 2-3 trees

- Let's use the same tree for this example
- The examples of elements to be deleted are as follows:
    - Let's delete 90, it is greater than 30 and it holds no next value, it is greater than 50 and 70, so it is in the right child, greater than 80 and boom found
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2010.png)
    
    - Let's delete 80, it is greater than 30, 50, 70 and it is found so now the node becomes vacant, we should not have empty nodes floating around our tree so we should merge it with either the left or right sibling.
    - At the time of insertion we were spliting but on deletion we should merge, in this case 70 should be 60's next.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2011.png)
    
    - Now let's delete 60, once it is found delete it looks like this if we merge with the right sibling:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2012.png)
    
    - Now if we merge with the left sibling it will look like this:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2013.png)
    
    - Let's delete 60 by another method this time called Borrowing
    - Ok we found 60 now what? The node is vacant but we haven't merged anything yet, we can borrow a key in that vacant node, we cannot borrow anything from 40 because it only has one key, but on the right side we have 80 and 90. It will look like this:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2014.png)
    
    - Until now we have seen the following cases for deletion:
        1. Simply delete
        2. Delete and merge
        3. Borrow
    - If borrowing is not possible then we should merge

### Where are 2-3 search trees used?

They are usually used in DBMS like:

- Softworks
- Oracle
- MySQL

## 2-3-4 Trees

- 2-3-4 trees are B-trees of degree 4.
    - Remember b-trees are multiway trees that are height balanced.
- Every node must have $[\frac42]=2$ children. The following structure is possible:
    - There can be at least 1 or 2 children.

![Untitled](13%20-%20Searc%208fc01/Untitled%2015.png)

- All leaf nodes must be in the same level.
- The same procedure is applied for inserting and deleting as in 2-3 trees.
    - When we want to insert and there is not enough space then we must split.
    - If we have the following set of numbers 10, 20, 30, 40, 50, 60, 70, 80 the insertion procedure is the following:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2016.png)
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2017.png)
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2018.png)
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2019.png)
    

## Red Black Trees

![Untitled](13%20-%20Searc%208fc01/Untitled%2020.png)

- A red black tree is a height balanced binary search tree that is similar to 2-3-4 trees.
- Every node is either red or black.
- The root node of this type of tree is always black.
- Null nodes are always black.
- The number of black nodes located on the paths from the root to the leaf are the same.
- There should be no consecutive red nodes and the children of red nodes are black.
- When we insert a new node it should always be a red node as default.
- There are two approaches for adjusting problems we might encounter with this type of tree:
    - Recoloring: To understand this concept we should see the **Uncle is red** case.
        - If the **P**arent and **U**ncle node are both red nodes the **N**ew node is red then recoloring should take place:
            
            ![Untitled](13%20-%20Searc%208fc01/Untitled%2021.png)
            
    - Rotation: To understand this concept we should see the **Uncle is black** case.
        - If a new node is inserted, its parent is also red and its uncle is a null node which means it is black, then rotation should take place: This type of rotation is called **Zig-zig**
            
            ![Untitled](13%20-%20Searc%208fc01/Untitled%2022.png)
            
        - There is another type of rotation called **Zig-zag** rotation:
            
            ![Untitled](13%20-%20Searc%208fc01/Untitled%2023.png)
            

### Creation of red black trees

Let's create a red black tree by inserting the following keys one by one:

**keys: 10, 20, 30, 50, 40, 60, 70, 80, 4, 8**

The procedure is as follows:

The first key is 10, remember that the insertion will be done just like we do for binary search trees.

1. Because we insert it then it must be a red node.

![Untitled](13%20-%20Searc%208fc01/Untitled%2024.png)

1. But because it is the root node then it will change to black.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2025.png)
    

Next we have 20, because it is greater than 10 then it should go on the right-hand side of 10.

1. Because we are inserting the node should become a red node, and its parent is black so there is no problem.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2026.png)
    

Next we have 30, it should come as the right child of 20.

1. Because we are inserting the node should become a red node, but there is a red-red conflict so we should check the uncle, because it is null we should perform a rotation.
    
    Before:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2027.png)
    
    After:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2028.png)
    

Now we have to insert 50, it must go on the right side of 30 and it is a red node so once again we have a red-red conflict, we should perform recoloring or rotation:

1. In this case recoloring will do the magic for us so let perform it then:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2029.png)
    
2. Now there is a problem here, 20 is the grandparent and root node which by has to be black, so we should only modify it:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2030.png)
    

Now let's insert 40, 40 is less then 50 so it should go on its left side.

1. One again we encounter a red-red conflict, so the way to solve this conflict will be done in the following way.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2031.png)
    
2. So as we can see we should perform Zig-zag rotation:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2032.png)
    

Now we must insert 60, once again we encounter a red-red conflict, so we should perform recoloring:

Before:

![Untitled](13%20-%20Searc%208fc01/Untitled%2033.png)

After:

![Untitled](13%20-%20Searc%208fc01/Untitled%2034.png)

Next we must insert 70, we wil encounter a red-red conflict once again so we must perform zig-zig rotation in this case:

Before:

![Untitled](13%20-%20Searc%208fc01/Untitled%2035.png)

After:

![Untitled](13%20-%20Searc%208fc01/Untitled%2036.png)

Now let's insert 80, we will encounter a red-red conflict again so in this case we should perform recoloring.

Before:

![Untitled](13%20-%20Searc%208fc01/Untitled%2037.png)

After:

![Untitled](13%20-%20Searc%208fc01/Untitled%2038.png)

- But we have a problem now, again we have a red-red conflict so in this case we should perform rotation around the grandparent:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2039.png)
    

Now let's insert 4, there will be no problem inserting this node so the output will be:

![Untitled](13%20-%20Searc%208fc01/Untitled%2040.png)

And finally let us insert 8, there wil be a red-red conflict so we should perform rotation:

Before:

![Untitled](13%20-%20Searc%208fc01/Untitled%2041.png)

After:

![Untitled](13%20-%20Searc%208fc01/Untitled%2042.png)

### Red Black trees vs 2-3-4 trees

- 2-3-4 trees means:
    - Every node in a tree can have one key and two children.
        
        ![Untitled](13%20-%20Searc%208fc01/Untitled%2043.png)
        
    - A node can have two keys and three children.
        
        ![Untitled](13%20-%20Searc%208fc01/Untitled%2044.png)
        
    - A node can have three keys and have four children.
        
        ![Untitled](13%20-%20Searc%208fc01/Untitled%2045.png)
        
- This structure is related to red black trees in the following way:
    - When a node has only one key then the tree is:
        
        ![Untitled](13%20-%20Searc%208fc01/Untitled%2046.png)
        
    - When a node has 2 keys i.e. a node has a red node node then it is similar
        
        ![Untitled](13%20-%20Searc%208fc01/Untitled%2047.png)
        
    - When a node has tree keys in a single node then it means that in a red black tree it will be equivalent to having a middle black node and a red node on both the left side and the right side:
        
        ![Untitled](13%20-%20Searc%208fc01/Untitled%2048.png)
        

In conclusion this means that red color nodes are related to its parent black parent node.

So one again we can take the following example to visualize this in a better way:

![Untitled](13%20-%20Searc%208fc01/Untitled%2049.png)

All of this can be summarized with the general form:

![Untitled](13%20-%20Searc%208fc01/Untitled%2050.png)

### Creating a red black tree and a 2-3-4 tree

Let's use the following set of keys for this example: 10, 20, 30, 50, 40, 60, 70, 80, 4, 8

- When we insert 10 it will look like this for both cases:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2051.png)
    
- For 20:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2052.png)
    
- For 30, we need to perform zig zig rotations:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2053.png)
    
- For 50, we need to perform recoloring, we would first turn 20 into a red node but because it is the root node then it must be black and in the case of the 2-3-4 tree we need to split the node bacause there is no more space for 50:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2054.png)
    
- For 40, we need to perform rotations and in the case of the 2-3-4 tree we should put 40 in between 30 and 50:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2055.png)
    
- For 60 the result would be:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2056.png)
    
- For 70 the result would be:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2057.png)
    
- For 80 the result would be:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2058.png)
    
- Finally for 4 and 8:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2059.png)
    

### Red Black Tree deletion cases

- Now we will focus on what are the procedures for deleting elements in a red black tree.
- This is very similar to the deletion of elements in a binary search tree but in addition recoloring and rotations will be involved.

So let's start off by taking the following tree as an example:

![Untitled](13%20-%20Searc%208fc01/Untitled%2060.png)

- Suppose we want to delete 90, we start making comparisons starting from the root node until we reach 90. Because it is a leaf node we simply delete it.
- Suppose we wnat to delete 20, once we find it we only delete its value but we let another element take the place of that empty node. The one who will take its place can be either the inorder succesor or predecessor i.e. 10 or 30.
- Suppose I want to delete 50, the element that will take its place can be either the inorder predecessor or succesor i.e. 40 or 60.

The cases for the deletion of nodes in a red black tree are the following ones:

1. For the first case the procedure is the following:
    1. If a node is red we simply delete it and don't bother doing anything else.
    2. If a node is red but it contains two children then the element that will take its place will be either the inorder succesor or predecessor.
    3. Suppose a we want to delete a red node that contains one left black child, in this case we remove the red node and let the black node take its place.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2061.png)
    
2. For the second case the procedure is the following:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2062.png)
    
    1. The node we want to delete now is D which has a child, P is its parent and S is the sibling. 
    2. When we want to delete a node that is black we should be really careful.
    3. The node is black, and the sibling is red then we simply delete D and perform a rotation starting from the right side and make both child nodes red.
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2063.png)
    
3. Now for the third case the procedure is the following:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2064.png)
    
    1. In this case the node we want to delete is D, in this case its sibling is black and that means we have two choices, which are:
        1. If the children of S are both black then we simply perform recoloring on S and the parent, then we can only remove D.
            
            ![Untitled](13%20-%20Searc%208fc01/Untitled%2065.png)
            
        2. Now let's think about the case where we want to delete D, where its parent node is black and sibling is also black but its sibling's left child is red. In this case we need to perform zig zag rotation.
            
            ![Untitled](13%20-%20Searc%208fc01/Untitled%2066.png)
            

### Red-Black tree deletion examples

- Now let us look at an example on how deletion applies to this type of trees
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2067.png)
    
1. Now 100, it has children so the node that can take its place can be either its inorder successor or predeccesor. Let us take 90 for this case
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2068.png)
    
2. Now 110, the node that will take its place will be the inorder succesor i.e 120
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2069.png)
    
3. Now let’s delete 80, nobody will take its place because it is a leaf node, but it turns into a black null node and the main problem here is that its sibling 120 also has two black null children nodes which means we need to perform recoloring in this case:
    
    ![Untitled](13%20-%20Searc%208fc01/Untitled%2070.png)
    
4. 120 this time, we just have to remove it from the tree and nothing else.

## Red-Black Tree vs 2-3-4 Tree Deletion

Now let us compare the deletion step on both cases.

- We can see the following patter on the following trees which is that
    - For every black node there is a separate node
    - If there is a red node that is along with a black node then it means that it is positioned inside the same node.
    - 2-3-4 Trees behave exactly the same as red black trees with regards to the deletion step.

![Untitled](13%20-%20Searc%208fc01/Untitled%2071.png)

![Untitled](13%20-%20Searc%208fc01/Untitled%2072.png)