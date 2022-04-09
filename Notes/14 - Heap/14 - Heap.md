# 14 - Heap

### What is a heap?

- Heap is not useful for searching purpose.
- Heap is commonly known as binary heap.
- A heap is a type of binary tree that must meet certain conditions, which are:
    - Being a complete binary tree.
    - Every node is greater than or equal (e.g. duplicates are also allowed) to all it descendants. This condition is called **Max Heap**.
    
    ![Untitled](14%20-%20Heap%2034896/Untitled.png)
    
    - Every node is smaller than or equal to its descendants. This condition is called **Min Heap**.
    
    ![Untitled](14%20-%20Heap%2034896/Untitled%201.png)
    
    - The height of a heap is always $log_n$
- A complete binary tree can be understood in the following way:
    - A heap are mostly implemented using arrays, there are also cases in which it is represented using linked lists but it is preferable to implement them using arrays.
    - If a binary tree is represented in an array, then there should be no blank spaces in between the elements.
    
    ![Untitled](14%20-%20Heap%2034896/Untitled%202.png)
    
    - The elements are store based on the following formulas:
    
    ```markdown
    Node at index i
    leftChild at 2*i
    rightChild at 2*i+1
    ```
    

### How to insert in a heap?

- Let’s see how the insert procedure works on a Max Heap.
- The same procedure is applicable for Min Heap.
- For this example we have taken a max heap and it is also represented in an array.
    
    ![Untitled](14%20-%20Heap%2034896/Untitled%203.png)
    

So let us insert a few elements and analyze how insertion is executed for this type of tree:

- Let’s insert 40
    - Remember that because it is a max heap hten the root should always be the largest element in the tree.
    - We should insert 14 at the next free space in the array (i.e. at index 8) because we want to maintain a complete binary tree.
    - By index we can see that 40 will be the left child node of 5, why? becuase we cant find out who will be the parent by dividing the index by 2.
    
    ![Untitled](14%20-%20Heap%2034896/Untitled%204.png)
    
    - Ok cool, 40 is inserted but is the whole tree a max heap? No, because 5 is smaller than its descendant.
    - To tackle this problem it is real easy to resolve it, we simply move 40 up until it the whole tree becomes a max heap.
    - The procedure of rearranging the elements is as follows:
        - Compare 40 with its parent, if it is greater then we should store it inside a temporary variable and replace 5 into the node 40 and move 40 upwards.
        
        ![Untitled](14%20-%20Heap%2034896/Untitled%205.png)
        
        - Now we compare 40 with 20, it is greater than 20 also so we must bring 20 down.
        
        ![Untitled](14%20-%20Heap%2034896/Untitled%206.png)
        
        - Again let’s compare it with 30, it is also greater so bring 30 down.
        
        ![Untitled](14%20-%20Heap%2034896/Untitled%207.png)
        
        - And now there is nothing above so that means we have finished rearranging the elements.
    - Now let us see how rearranging is performed in an array:
        - We must take 40 in a temporary variable, we compare it to its pararent at index 4, in this case 5 is smaller so we should move it to index 8.
        
        ![Untitled](14%20-%20Heap%2034896/Untitled%208.png)
        
        - Now we bring i, to index 4 and starting from there again compare with the parent i.e. index 2. So 20 is smaller than 40 so we should move the elements to their corresponding positions.
        
        ![Untitled](14%20-%20Heap%2034896/Untitled%209.png)
        
        - Now we bring i to index 2, and make the comparison with 30, in this case 30 is smaller so we should therefore move it to the index 20.
        
        ![Untitled](14%20-%20Heap%2034896/Untitled%2010.png)
        
        - Now we bring i to index 1, we can see that there is no parent because i became 1, so we should copy 40 there.
        
        ![Untitled](14%20-%20Heap%2034896/Untitled%2011.png)
        
        - And now the heap size has increased to 8.
        
        ![Untitled](14%20-%20Heap%2034896/Untitled%2012.png)
        

The insert function written in C++ shall include the following parameters:

- A insert function that takes two parameters, the first parameter is an array and the second parameter is the element we want to insert.
- An integer pointer i that will jump through the array indexes checking the elements.

```cpp
void insert(int A[], int n){
    int temp, i = n;
    temp = A[n];
    while(i > 1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}
```

### How to create heap?

- Let us now focus on how to create heap with a given set of elements.
- We can use the same idea we used for inserting elements and extend it to create a binary heap.

Let’s see the procedure by taking the following numbers: $10, 20, 30, 25, 5, 40, 35$

- Let us first introduce 10 in the heap and adding the other elements as follows:

![Untitled](14%20-%20Heap%2034896/Untitled%2013.png)

- When we insert 20 diagrammatically it will become the left child of 10, and because it is greater than 10 it should move up, we should do the same rearranging within the array.

![Untitled](14%20-%20Heap%2034896/Untitled%2014.png)

- When we insert 30, diagrammatically it will belong to 20’s right child, but because it is greater than 20 then it must go up.

![Untitled](14%20-%20Heap%2034896/Untitled%2015.png)

- Now we insert 25, naturally it becomes the left child of 10, and because it is bigger its parent node then it will be swapped.

![Untitled](14%20-%20Heap%2034896/Untitled%2016.png)

- Now when we insert 5, it becomes the right child of 25 and because it is smaller then its parent node then there should be no change at all.
- Now if we insert 40, it becomes the left child of 20 and because it is greater than 20 it must be swapped and further compared with 30

![Untitled](14%20-%20Heap%2034896/Untitled%2017.png)

- The last element to be inserted in this case is 35, now it becomes the right child of 30, it must be swapped with 30 and nothing else should be modified.

![Untitled](14%20-%20Heap%2034896/Untitled%2018.png)

The procedure for creating a heap is as follows:

```cpp
void createHeap(){
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    for(i = 2; i <= 7; i++)
        insert(A, i);
}

int main() {
    createHeap();
    return 0;
}
```

### How to delete from a heap?

To understand this procedure we will take the following heap as an example:

![Untitled](14%20-%20Heap%2034896/Untitled%2019.png)

- We need to remember the following statement about deletions in heap**: From Heap we can only the delete the root element**.
- The root element is the largest element because it is a max heap.
- This means we can only delete the highest priority element.

So let’s see how deletion works:

Let’s try to delete 40 and see how we conduct this procedure:

- Ok we take out 40 and store it inside a temporary variable, and now which element should fill in the empty space of the root? If we use common sense then we would let 35 take its place, and let 15 take the place of 35.

![Untitled](14%20-%20Heap%2034896/Untitled%2020.png)

- But is it a heap? No because it is not a complete binary tree. So in conclusion common sense doesn’t work on heap and it doesn’t work for any other data structure.
- So the real procedure for deleting elements in a heap is the following:
1. We must copy the last element from the array or the heap and place it at the vacant node. If we do the same on the array the result would be first storing the root element in a variable, moving the last element to the root node and as a result our heap will only have 6 indexes and the seven location would be empty.
    
    ![Untitled](14%20-%20Heap%2034896/Untitled%2021.png)
    
2. Until now we have created a complete binary tree but not a max heap so we need to rearrange the elements so that it becomes a max heap. The first step is compare and see which element is greater from the two children of the new root i.e. 35 and 30. In this case 35 is greater and now compare it with the new root, in this case the root is smaller so we need to interchange these two.
    
    ![Untitled](14%20-%20Heap%2034896/Untitled%2022.png)
    
3. From here we repeat the same process but this time with the newly interchanged value which is 5 now i.e. compare whether 15 or 10 is greater and then compare with the parent element. Because there is no left or right child for this node we stop.
    
    ![Untitled](14%20-%20Heap%2034896/Untitled%2023.png)
    

The this procedure is translated in the following way into c++:

```cpp
void deleteHeap(int A[], int n){
    // n is the last index
    int x, i, j;
    // the last element is copied into x
    x = A[n];
    // we copy the last element at the root
    A[i] = A[n];
    // i must be placed at index one and j at its left child
    i = 1, j = 2 * i;
    // this procedure just repeats so we need to write a while loop
    while(j < n - 1){
        // 1. compare left and right child, the element that is greater will point on j
        if(A[j + 1] > A[j])
            j = j + 1;
        /* 2. if the parent element is smaller than the child
         element then interhcange the parent and the child */
        if(A[i] < A[j]){
            swap(A[i], A[n]);
            i = j;
            j = 2 * j;
        } else
            break;
    }
}
```

### What is heap sort?

- Let’s take the previous example to understand what heap sort is.
- What happened to the variable that was storing the element we wanted to delete? Well it is located at the index 7 from the array, and we can keep it and we should also not worry if it takes place in the memory because it really does not belong to the heap, so it becomes an outsider per se.
    
    ![Untitled](14%20-%20Heap%2034896/Untitled%2024.png)
    
- If we continue deleting elements until we delete all the elements in the array, what happens to the array? It becomes sorted. This is heap sort.
- The definition of heap sort is: from the heap we delete elements and as we go deleting the elements one by one we’ll get free space at the end of the array and we can use that free space to store the deleted elements therefore we will get elements that will be arranged in descending order.
- We can add this functionality on the delete function with the following line of code after the closing brace of break;

```cpp
A[n] = x;
```

## Heapify

- Heapify is a faster method for creating a heap.
- Heapify is a procedure related to the creation of heap, not just the insertion of one element but instead inserting all the elements one by one and creating a heap.
- To understand it let us observe the insert and delete procedure.

### Insert and Delete

- Remember that if we want to insert a new element in a max heap we plug it in the next binary tree order position and reorder the elements by sending the element from leaf towards the root.

![Untitled](14%20-%20Heap%2034896/Untitled%2025.png)

- Remember that for deleting we need to take the root element out and store it inside a variable , the last element will take its place and because it is not a max heap we must do some adjusting on the elements and we start by comparing which element is bigger the left child or the right child? We compare the bigger element with the parent node and interchange the elements, once again we repeat this procedure.

![Untitled](14%20-%20Heap%2034896/Untitled%2026.png)

- Now we are ready to understand what heapify is, in both the case of the insert and delete procedure we are adjusting the elements to form a max heap. **But the sole difference betweeen these two procedures is the direction of adjustment.**

### How heapify works?

To understand how heapify works we have the following array of elements:

![Untitled](14%20-%20Heap%2034896/Untitled%2027.png)

We will create a heap in the standard method and then in the heapify method:

### Standard

- We start  inserting the elements, because it is not a max heap we will start by swapping 5 with 10, then swap 30 with 10, then we swap 20 with 5, then swap 35 with 20, then swap 35 with 30 once again, then 40 should swap with 10 and 35, and there should not be a change at all because 15 is smaller than 35.

![Untitled](14%20-%20Heap%2034896/Untitled%2028.png)

- The time taken for this procedure is $_nlog_n$

### Heapify

- First we generate a binary tree first, in this case we won’t start from the first element, instead we will start from the last element i.e not from 5 but instead from 15.

![Untitled](14%20-%20Heap%2034896/Untitled%2029.png)

- We won’t work from the leaf towards the root but instead from root towards leaf.
- 15 does it have any children? No so it must be a heap. Finished.
- Same for 40 there is nothing below so it is also a heap.
- The same goes for 35 and 20.
- Now we go to 30. Until now we haven’t made no modifications but now we will modify something. We compare with its children and we can see that it is smaller than 40 so we must swap them. Finished

![Untitled](14%20-%20Heap%2034896/Untitled%2030.png)

- Now 10 is smaller is smaller than 35 so let’s swap both and finished.

![Untitled](14%20-%20Heap%2034896/Untitled%2031.png)

- Now let’s see 5, we should sent 40 up and 5 down, send 30 up and 5 down and finished.
- That’s all! This is a max heap simple as this we have generated a heap. We have done very few adjustement. This procedure is faster because it take $O(n)$

### Heap as a priority queue

- A priority queue is related to the insertion and deletion of elements.
- Elements will have their priority and they are inserted along with the priority.
- When we are deleting always the highest priority elements will be deleted.
- Let’s take the following list of elements 4, 9, 5, 10, 6, 20, 8. The numbers themselves are the priority.
- **Larger the element higher the priority.**

The implementation is as follows:

- The insertion phase means just copying the elements from the list into an array:

![Untitled](14%20-%20Heap%2034896/Untitled%2032.png)

- Now if we want to delete we must search and find out which is element is the largest in order to proceed onto shifting the elements if needed and then deleting the element:

![Untitled](14%20-%20Heap%2034896/Untitled%2033.png)

- The time analysis for this will be:
    - Insertion $O(1)$
    - Deletion $O(n)$

This is kind of inefficient so let us see element by element how the heap will help us make this process a bit more faster:

- Let’s represent 4, 9, 5, 10, 6, 20
- We insert an element for 4
- We insert 9 as the left child of 4, because 9 is greater then 9 will move up and 4 will come down:

![Untitled](14%20-%20Heap%2034896/Untitled%2034.png)

- Then we insert 5 as the right child of 9, it is smaller than 9 so no problem
- Then we insert 10 as the right cihld of 4, it is greater than 4 and 9 so it must go up:

![Untitled](14%20-%20Heap%2034896/Untitled%2035.png)

- Then 6 comes on the right side of 9, because it is smaller then there is no problem at all.
- Then comes 20 which will be on the left side of 5, it is greater so it must go up:

![Untitled](14%20-%20Heap%2034896/Untitled%2036.png)

- Then if we want to delete the element we should delete from the priority queue in this case is the uppermost element i.e. 20 the root element.
- Now we can see that the time analysis when we use heap to implement priority queues is:
    - Insertion takes $O(\log_n)$ time.
    - Deletiong takes $O(\log_n)$ time.
- **If we change the rule to make the smaller element to have higher priority then we can use a Min Heap.**

**In conclusion we see that Heap is the best data structure for implementin priority queues.**