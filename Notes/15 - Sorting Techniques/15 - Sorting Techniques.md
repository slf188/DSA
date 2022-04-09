# 15 - Sorting Techniques

### What are sorting techniques?

- There are various sorting techniques out there including:
    1. Bubble Sort
    2. Insertion Sort
    3. Selection Sort
    4. Quick Sort
    5. Merge Sort
    6. Count Sort
    7. Bucket/Bin Sort
    8. Radix Sort
    9. Shell Sort
    10. *Heap Sort*
    11. *Tree Sort* 
- Each of these techniques has its own method of working, so there is no best sorting technique.
- According to our requirement we can select a particular sorting technique based on a criteria.

### Criteria used for analysis of sorting techniques

- The criteria for comparing these techniques are:
    - Number of comparasions: For sorting the elements a sorting technique may be comparing the elements and if so then how many comparasions are performed? This helps decide the time complexity of any of these techniques.
        - Number of swaps: For arranging them in a certain order which can be decreasing or increasing order the elements have to change their places, so it has to swap the elements, swapping is a common process performed in almost all of the 11 techniques.
    - Adaptive: When we try to keep elements in a sorted order, what happens if the elements are already sorted? If the elements are already in increasing order the technique should take minimum time or less amount of time because it doesn’t have to rearrange the elements. So we need to take in consideration if the technique adapts to any situation.
    - Stable: To understand this we should imagine a list of names and marks like the following image:
        
        ![Untitled](15%20-%20Sorti%202d34b/Untitled.png)
        
        - Actually these are records of students, each student has their own marks.
        - This list is already sorted based on names. Now we want to sort them based on marks.
        - If we analyze this we can already see that two students have the same marks i.e. C and E.
        - By taking this into account we should aim to use an algorithm that keeps their order preserved i.e. C and then E.
        - If an algorithm helps preserve the order of the elements then that algorithm is **Stable**.
        
        ![Untitled](15%20-%20Sorti%202d34b/Untitled%201.png)
        
        - The reason we need this is because initially this list was already sorted based on names, now if we sort them based on marks it will not be sorted based on names anymore, but if there are duplicate marks at least in those occasions names must be in a sorted order. This is a requirement that is commonly needed for databases.
    - Extra Memory: From the 11 techniques we will see that there are certain algorithms that require extra memory space for sorting the elements apart from the space that is being consumed. This is not the case for all the techniques but it happens for just a few ones.
    
    ### What is the main idea behind the 11 methods of sorting?
    
    ![Untitled](15%20-%20Sorti%202d34b/Untitled%202.png)
    

## Bubble Sort

Let’s take the following list of elements to understand bubble sort:

![Untitled](15%20-%20Sorti%202d34b/Untitled%203.png)

- To understand how this works we have drawn an array in horizontal and vertical form.
- Every time we will make a comparison between a pair of elements, if the first element is greater than the second element, then both elements need to be interchanged and the remaining elements as they are. We repeat this process until we reach the last element in the array:

![Untitled](15%20-%20Sorti%202d34b/Untitled%204.png)

- Whenever we finish comparing through all the pairs available in the array it is called a pass. We have now completed the first pass which results in 5, 7, 3, 2, 8. Only one element is sorted that is 8, we have performed 4 comparasions and swaps. Because only one element is sorted we need to perform a second pass.

![Untitled](15%20-%20Sorti%202d34b/Untitled%205.png)

- In total two elements are sorted now, we made three comparasions and two swaps. We still need to perform more passes so let’s get to it.

![Untitled](15%20-%20Sorti%202d34b/Untitled%206.png)

- Now three elements are sorted, we made two comparisons and two swaps, but we still need more passes.

![Untitled](15%20-%20Sorti%202d34b/Untitled%207.png)

- Now all the elements are sorted, we made one comparison and one swap. In total we needed four passes to sort the entire array.

![Untitled](15%20-%20Sorti%202d34b/Untitled%208.png)

- If we do some analysis we can get great insights about this whole process we have made with this array:
    - We had 5 elements: $n=5$
    - The number of passes has a formula that is: $n-1$
    - The number of passes and swaps has a formula that is: $1+2+3...+n-1=\frac{n(n-1)}{2}=O(n^2)$
- Bubble sort is called bubble sort because if we see the first pass we can see that:
    
    ![Untitled](15%20-%20Sorti%202d34b/Untitled%209.png)
    
    - Eight is the heaviest element, if we drop it from the top it will go down all the way down and settle at the bottom, and the other elements that are 5, 7, 3, 2 because they are lighter elements they are slowly moving up:
    - The effect is just like if we throw a stone in the water, because the stone is heavier the stone will go down but the bubbles that are lighter will go up.
    - [Here is a video of the algorithm performed on the go.](https://www.youtube.com/watch?v=Cq7SMsQBEUw)

```cpp
void bubbleSort(int A[], int n){
    int flag;
    // This for loop is reponsible for the passes
    for(int i = 0; i < n - 1; i++){
        flag = 0;
        // This for loop is reponsible to traverse through the whole array and swap the elements
        for(int j = 0; j < n - 1 - i; j++)
            if(A[j] > A[j + 1]){
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        /* By introducing flag we can identify whether there was any swapping in the past, if there is no swapping then the list is already sorted and can stop the whole algorithm.
         By introducing flag we have made bubble sort an adaptive technique, by nature is it not adaptive.
         */
    
        if(flag == 0)
            break;
    }
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    cout << endl;
}
```

## Insertion Sort

- To understand insertion sort we must first udnerstand what insertion is.

Let us take the following example to understand insertion:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2010.png)

- So we have taken a list of elements in an array which are already sorted, and in this list I want to insert the element 12 in a sorted position.
- So insertion basically means inseting an element in a sorted array, at a sorted position. That means 12 should be placed before 15 that means we have to move the elements to the right-hand side

We have two choices for solving performing insertion sort. We can either use an array or a linked list.

**Array**

The procedure for inserting 12 is the following one:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2011.png)

1. Compare 12 with the last index element, is 30 greater than 12? Yes so move it to the right.
2. Move to the next element, is 25 greater than 12? Yes so move it to the right.
3. Next element, is 20 greater than 12? Yes so move it to the right.
4. Next, is 15 greater than 12? Yes so move it to the right.
5. Now 10 is not greater than 12, so we keep this position free and we then store 12 inside there.

The time taken for insertion in this case depends on the number of elements so $O(1)...O(n)$

**Linked List**

The procedure for insreting 12 in a linear singly linked list is the following one:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2012.png)

1. In a linked list shifting is not required, instead we should only find out where 18 should go.
2. For finding that position we need the help of two pointers, q that will start before the first pointer and a p pointer starting from the first node.
3. Check p’s data 2 it is smaller than 18 so we bring q upon p and then move p to the next node.
4. 6 is smaller than 18, so again bring q upon p and then move p to the next node.
5. Again with 10 and 15.
6. Now 20 is greater than 18, so 18 should go after q, we should take a new temporary t pointer and create a new node, insert 18 then make it point to 20 and q’s next point on 18.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2013.png)

The time taken for this procedure is constant so $O(n)$, in conclusion insertion sort is more useful or compatible when using linked lists.

Now it is time to take a look at what insertion sort really is:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2014.png)

- We have taken the following array of five elements.
- The first thing we do to understand what insertion sort is assume that the first element in this case 8 is already sorted and the remaining elements are not sorted. So we have one sorted element and four not sorted elements now.
- So in the following steps the only thing we need to do is from the unsorted list take out the elements and insert them to the sorted side.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2015.png)

- The first pass we need is to extend the sorted list to two elements by inserting 5, for inserting 5 check whether 8 is greater than 5, if so we shift it to the right and insert five before it.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2016.png)

- In the second pass we need to extend the sorted list to three elements by inserting 7 this time, for inserting seven we should first check whether 8 is greater than 7, it is so 8 will move to the right side but 5 is lesser than 7 so it should stay where it is and 7 must be inserted in between both.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2017.png)

- In the third pass we shall insert 3, 8 is greater shift it, 7 is greater shift it, 5 is greater shift it and then insert 3.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2018.png)

- In the fourth pass we shall insert 2, all elements are greater so we shift them to the right and place 2 in the last spot.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2019.png)

- If we do some analysis we will see that there is a pattern with regards to the number of comparasisons and swaps performed.
    - In the first pass we made one comparison and swap.
    - In the second pass we made two comparisons and swaps.
    - In the third pass we made three comparisons and swaps.
    - In the fourht pass we made four comparions and swaps.
    - No. of passes $n-1$
    - No. of comparisons and swaps $1+2+3...+n-1=\frac{n(n-1)}{2}$

```cpp
void insertionSort(int A[], int n){
    /* For loop for passes
    1. We don't have to start from 0 because 0 is already sorted.
     2. We must check all the elements from the array.
     */
    int j, x;
    for(int i = 1; i < n; i++){
        j = i - 1;
        x = A[i];
        while(j > -1 && A[j] > x){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
        // We don't need the help of the flag variable becuase by nature insertion sort is adaptive.
    }
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    cout << endl;
}
```

## Comparing of bubble and insertion sort

The time complexities for both techniques is the following one:

- Only the two are adaptive out of the 11 techniques out there.
- One the two and merge sort are stable out of the 11 techniques available.
    
    ![Screen Shot 2022-01-07 at 17.14.46.png](15%20-%20Sorti%202d34b/Screen_Shot_2022-01-07_at_17.14.46.png)
    

## Selection Sort

To understand this technique we have taken the following array as an example:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2020.png)

- The selection sort algorithm also sorts the elements by passes. In each pass one element gets sorted.
- Let us perform the passes and see how selection sort works:
- Same as for the other techniques we have seen we need to make this array vertical.
- During the first pass we must select the first position in the index 0 with a variable i in this case where 8 is located, and select the smallest element in the array to take its place which in this case will be 2. For finding the minimum element we will take two pointers  k and j which will also be in the same place where i is pointing. Then we move j to the next element 6, is it smaller than k? Yes so move k to where 6 is located. Continue we move j to the next element 3, it is smaller than k? Yes so move k to where j is located. Continue we move j to the next element 2, is it smaller than k? Yes so move k to where j is located. We move j to the next element 5, is it smaller than k? No so we move j to the next location 4, is it smaller than k? No so move j to the next location, oh there is no other element at index 6 so we finish the first pass. Ok cool so we have saved the index of where the smalles element is with k, so we interchange i and k. And the new list will be:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2021.png)

- For the second pass again but this time we place i, j and k at index 1. We move j to the next element 3, is it smaller than k? Yes so move k to where j is. Next we move j to the next element 8, is it smaller than k? No so we move j to the next element 5, is it smaller than k? No so we move j to the next element 4, is it smaller than k? No so we finish interchange i and k and finish the second pass.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2022.png)

- For the third pass again we place i, j and k at index 2. We move j to the next element 8, is it smaller than k? No so move next until we reach 5, is it smaller than 6? Yes so move k to where j is, again we move j to the next element 4, is it smaller than k? Yes so we move k to where j is. Now we exchange the elements k and i.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2023.png)

- For the fourth pass we place i, j and k at index 3. We move j to the next element 5, it is smaller so we move k to where j is. Again we move j to 6, it is not smaller than k so we interchange i and k and finish the fourth pass.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2024.png)

- For the fifth pass we place i, j and k at index 4. We move j to the next element 6 it is smaller than k so we move k to where j is. Then we intechange i with k and finish the fifth and final pass. Now all the elements are now sorted:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2025.png)

- Selection sort is similar to when a teacher wants to sort students by height in their chairs, at first the students are not sorted but starting from the first row the smallest students must sit.
- If we do some analysis:
    - No. of swaps: $n-1$, this is the only algorithm that does the minimum number of swaps.
    - No. of comparisons: $\frac{n(n-1)}{2}$
- Selection sort isn’t adaptive nor stable.

[If we want to see the selection sort algorithm visually here is a great video to watch it!](https://www.youtube.com/watch?v=92BfuxHn2XE)

```cpp
void selectionSort(int A[], int n){
    // For the passes
    int j, k;
    for(int i = 0; i < n - 1; i++){
        // For j and k
        for(int j = k = i; j < n; j++){
            // Compare if j is smaller than k, if so move k to where j is
            if(A[j] < A[k])
                k = j;
        }
        // Swap i and k
        swap(A[i], A[k]);
    }
    
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    cout << endl;
}
```

## Quick Sort

### What is the idea behind quick sort?

- Quick sort is one of the most famous sorting techniques.

For understanding quick sort we have taken the following examples to illustrate how quick sort works?

$10, 30, 20, 70, 40, 90, 80$

- In this list which element is already sorted? The answer is 10, the rest of the elements aren’t.

$80, 70, 40, 30, 20, 10, 90$

- In this list which element is already sorted? The answer is 90, the rest of the elements aren’t.

$40, 30, 20, 50, 90, 70, 80$

- In this list which element is already sorted? The answer is 50, the rest of the elements aren’t.

Now on what basis do we say that these elements are already sorted?

- In the case of the third list is 50 because all of the elements before 50 are smaller than 50 and the elements after 50 are all greater than 50. That is why we say 50 is in a sorted position. If we sort the list 50 will occupy the fifth position in the list definitely.
- **Now the main idea for the quick sort technique is that an element is in a sorted position if all the elements before that elements are smaller and all the elements after that element are greater.**
- Quick sort doesn’t mean fastest sort, it actually means that quick sort is wholly based on the scenario where a teacher has a group of students and the teacher wishes those students to form a line in increasing order of their height. The first option for sorting them is to let the teacher sort them and the second option is to ask the students to arrange themselves. The faster method for sorting the students is the second option because is the same as when we’ve heard out teachers saying something like “Students quickly form a line in increasing order of your height”. If you want to be part of the line you must make sure that all of the students stading on your right side are shorter than you and all those that are taller than you are on your left side.
- So how do you confirm you are in a sorted position? You might say that you are in a sorted position if the person in front of you is shorter and the person standing behind you is taller, whether they are shorter or not it is not our business, we are in our respective position.

### How does quick sort works?

Let’s try to understand how quick sort works by using the following example:

$50, 70, 60, 90, 40,80,10,20,30$

- First we select the first element 50 as **pivot**, and now 50 has to find its place in the list. We must use an i variable that will help us look for greater elements than pivot, if it finds them it will stop and try to intechange elements with j, and we will use j that will start from the last index and it will help us find for smaller elements than pivot, if it finds any element that is smaller it will stop and interchange the elements with i.
    
    ![Untitled](15%20-%20Sorti%202d34b/Untitled%2026.png)
    
    - So now let us start with i, 70 is greater than 50, now j 30 is smaller than 50 now both must interchange their places. The list will look like:
    
    ![Untitled](15%20-%20Sorti%202d34b/Untitled%2027.png)
    
    - So now let us move on with i, 60 is greater than 50, and j 20 is smaller than 50 now both must interchange.
    
    ![Untitled](15%20-%20Sorti%202d34b/Untitled%2028.png)
    
    - 90 is greater than 50, and 10 is smaller than 50 so both must interchange.
    
    ![Untitled](15%20-%20Sorti%202d34b/Untitled%2029.png)
    
    - 40 is not greater than 50 so it shall continue moving to where 80 is, now 80 is greater than 50. Now j will decrement to where 80 is, because it isn’t smaller it should continue decrementing to where 40 is and now it is smaller so now we finished checking all the elements in the list.
        
        ![Screen Shot 2022-01-08 at 21.58.14.png](15%20-%20Sorti%202d34b/Screen_Shot_2022-01-08_at_21.58.14.png)
        
    - Now we shall interchange the pivot element with j and the remaining elements will stay as they are. But still we have to sort the rest of the elements but now we have identified the **partitioning position**. And on both groups we will apply quick sort once again. So we can say quick sort is a recursive function. The rule of thumb is that there should be at least two elements to perform quick sort.
        
        ![Screen Shot 2022-01-08 at 22.01.40.png](15%20-%20Sorti%202d34b/Screen_Shot_2022-01-08_at_22.01.40.png)
        
    - What we did here is just the partitioning procedure we have yet to write a program for recursive quick sort that will take care of the two remaining groups we see here.
    - The partition algorithm works for any type of list no matter how long the list is or even if the list is already sorted.

```cpp
int partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l, j = h;
    
    do{
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i < j)
            swap(A[i], A[j]);
    }while(i < j);
    swap(A[l], A[j]);
    return j;
    
}

void quickSort(int A[], int l, int h){
    // Quick sort is a recursive function that could be written inside the partition function.
    int j;
    if(l < h){
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);
    }
}

int main() {
    int A[] = {50, 70, 60, 90, 40, 80, 10, 20, 30, INT32_MAX}, n = 9;
    quickSort(A, 0, 8);
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    cout << endl;
    return 0;
}

» 10 20 40 50 60 70 80 90 30
```

## Merge Sort

Merge sort comes from the idea of merging, there are three scenarios for merging:

1. Merging two lists
    - Merging is a process of combining two sorted lists into a single sorted list.
        
        ![Untitled](15%20-%20Sorti%202d34b/Untitled%2030.png)
        
    - The sizes of the lists can differ, we can merge these two lists by comparing the elements and copying the elements in the third array. We can use i, j and k on the first index of the three respective arrays. If A[i] is smaller than B[j] we copy A[i] into C[k], and then i++ as well as k++ and again do the same process until we finish comparing the elements in the arrays.
    - In the case where we have finished traversing through the elements of one array but there are still elements in the array B, then we can just copy the remaining elements of B into C.
        
        ![Untitled](15%20-%20Sorti%202d34b/Untitled%2031.png)
        
    - We should take the size of array A as m, and the second array B as n.
    
    ```cpp
    void mergeTwoLists(int A[], int B[], int m, int n){
        int C[m + n];
        int i, j, k;
        i = j = k = 0;
        while(i < m && j < n){
            if(A[i] < B[j])
                C[k++] = A[i++];
            else
                C[k++] = A[j++];
        }
        // Copy the elements from array A if there are any elements remaining
        for(; i < m; i++)
            C[k++] = A[i];
        // Copy the elements from array B if there are any elements remaining
        for(; j < n; j++)
            C[k++] = B[j];
        // The time taken for this algorithm is O(m + n)
        for(int l = 0; l < m + n; l++)
            printf("%d ", C[l]);
        cout << endl;
    }
    ```
    
2. Merging two lists in a single array
    - Now we have a case where we apparently have a single array but in reality we have a single array that is there are two lists in a single array, both are split from the half of the whole list. We shall place two variables l at index 0, h at the last index and m at the middle of the list. For merging both we need an array B where we have the ordered list that we will use to then copy the elements back to the array A.
    - We also need the help of i, j and k for sure.
    
    ![Untitled](15%20-%20Sorti%202d34b/Untitled%2032.png)
    
    ```cpp
    void mergeTwoInASingleArray(int A[], int l, int mid, int h){
        int i, j, k;
        i = l, j = mid + 1, k = l;
        int B[100];
        while(i <= mid && j <= h)
            if(A[i] < A[j])
                B[k++] = A[i++];
            else
                B[k++] = A[j++];
        
        for(; i <= mid; i++)
            B[k++] = A[i];
        
        for(; j <= h; j++)
            B[k++] = A[j];
        
        for(i = l; i<=h;i++)
            A[i] = B[i];
        
        for(int i = 0; i < 8; i++)
            printf("%d ",A[i]);
        cout << endl;
    }
    
    int main() {
        int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
        mergeTwoInASingleArray(A, 0, 3, 7);
        return 0;
    }
    
    » 2 3 5 6 7 8 10 12
    ```
    
3. Merging multiple lists
    - Let’s take four sorted lists and try to merge the four into a single sorted list.
    - This case is tricky because we now have to compare the first element of the four lists and copy the smallest element inside the new sorted list. But we can solve this in another way using the **2-way sort.**
    - We first merge the A and B list and get another list, and again we merge the C and D list and get another list once again. And then finally merge the two new lists to get a final list.
    
    ![Untitled](15%20-%20Sorti%202d34b/Untitled%2033.png)
    

We need to understand these underlying concepts before tackling the merge sort technique.

- 2-way sort can be implemented in two different ways, iteratively or recursively.

### Iterative

- We must take an array containing 8 elements which we need to sort it. To apply merge sort we say that “There is an array containing 8 **lists,** how? every element in the list is a list”.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2034.png)

- This statement makes complete sense because if we take a list that only has one element then it is already sorted. This enables us to merge them, we will then get a sorted result.
- We need to compare pair by pair which element is greater and continue until the list is finished.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2035.png)

- Now the size of the list is 2, but we have to continue merging.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2036.png)

- Every single of these new results are also passes, so in total we needed four passes for this list. The time taken for this algorithm is $O(n\log n)$

```cpp
void iterativeMergeSort(int A[], int n){
    int p, i, l, mid, h;
    for(p = 2; p <= n; p = p * 2)
        for(i = 0; i + p - 1 < n; i = i + p){
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            mergeTwoInASingleArray(A, l, mid, h);
        }
    if(p/2 < n)
        mergeTwoInASingleArray(A, 0, p/2, n - 1);
}

int main() {
    int A[] = {8, 3, 7, 4, 9, 2, 6, 5};
    iterativeMergeSort(A, 8);
    return 0;
}

» 3 8 7 4 9 2 6 5 
3 8 4 7 9 2 6 5 
3 8 4 7 2 9 6 5 
3 8 4 7 2 9 5 6 
3 4 7 8 2 9 5 6 
3 4 7 8 2 5 6 9 
2 3 4 5 6 7 8 9
```

### Recursive

- For this approach we use a two way merge sort.
- It follows a top-down approach as it is recursive.
- So we have a 8 element list of elements which are not sorted, to start sorting the elements we divide the array in half and check if the first four elements are sorted? If they are not sorted then we can assume that the other half is also not sorted. Then check if the half of the half is sorted? In case it isn’t then we can assume that the other half is not sorted and we repeat the process once again.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2037.png)

- In two way merging, we need two sorted lists so that we can merge them and make a single sorted list.
- This is the main idea with recursive merge sort, **when a single large array is given, it will be broken into two halves and there won’t be no guarantee that those two will be sorted, then again break the two into halves and again until it reaches one single element. Now with one element means it is sorted so from there it will start merging the elements.**

```cpp
void recursiveMergeSort(int A[], int l, int h){
    int mid;
    if(l < h){
        mid = (l + h) / 2;
        // We repeat the function on the first half
        recursiveMergeSort(A, l, mid);
        // Perform merge sort on the right hand-side or second half
        recursiveMergeSort(A, mid + 1, h);
        // Merge the two lists in a single array with the help of auxiliary array B
        mergeTwoInASingleArray(A, l, mid, h);
    }
}

int main() {
    int A[] = {8, 2, 9, 6, 5, 3, 7, 4};
    recursiveMergeSort(A, 0, 7);
    return 0;
}

» 2 8 9 6 5 3 7 4 
2 8 6 9 5 3 7 4 
2 6 8 9 5 3 7 4 
2 6 8 9 3 5 7 4 
2 6 8 9 3 5 4 7 
2 6 8 9 3 4 5 7 
2 3 4 5 6 7 8 9
```

![Untitled](15%20-%20Sorti%202d34b/Untitled%2038.png)

## Count Sort

- This technique is one of the easiest ones to grasp but it is also one that consumes a lot of memory.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2039.png)

- Let’s take this list and make an attempt to sort it, for doing so we need another array named count and its size should be equal to the largest element in the A array i.e. the size should be 15. We should initialize this array with some empty values, in this case we can use zeroes.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2040.png)

- The procedure is the following: scan through all the elements in A array, if I go up on the first element 6 at the same index in the count array we increment by one, and repeat this process until we finish with the entire array. The final output looks like:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2041.png)

- Now we should copy the element from the count array back to the A array. We need to scan through the count array, if the value is more than 0 we write the index as a number for the same number of times i.e. if index three contains the number two then the array A should look like: 3 3 ...

![Untitled](15%20-%20Sorti%202d34b/Untitled%2042.png)

- We took duplicate elements to understand the meaning of count.

```cpp
int findMax(int A[], int n){
    int max=INT32_MIN;
    int i;
    for(i=0;i<n;i++)
        if(A[i]>max)
            max=A[i];
    return max;
}

void countSort(int A[], int n){
    int max = findMax(A, n), i;
    int *count = new int[max];
    for(int i=0; i<max + 1; i++)
        count[i] = 0;
    for(i = 0; i<n; i++)
        count[A[i]]++;
    i = 0;
    int j = 0;
    while(i < max + 1){
        if(count[i] > 0){
            A[j++] = i;
            count[i]--;
        } else {
            i++;
        }
    }
    
    for(int i = 0; i < n; i++)
        printf("%d ",A[i]);
    cout << endl;
}

int main() {
    int A[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    countSort(A, 10);
    return 0;
}

» 3 3 6 6 6 8 9 10 12 15
```

## Bin Bucket Sort

- This technique is very similar to count sort, the concepts are very similar in a way.
- So we take an A array that we wish to sort, to do se we need an extra bins array, its size should be equal to the largest element as the A array, and it must be initialized with null values or pointers. This means we are using an array of linked lists.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2043.png)

- And we need to scan the elements from the A array and copy them into the bins array, e.g. we are at index 0 of A, then we copy 6 at index 6 at the bins array. And we continue the same process until we finish scanning all the elements from A array.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2044.png)

- The final ouput will look like:

![Screen Shot 2022-01-12 at 17.24.41.png](15%20-%20Sorti%202d34b/Screen_Shot_2022-01-12_at_17.24.41.png)

- And now following this we have to empty these bins from left to right and copy the elements back in the array A. After copying the elements the array A will look like:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2045.png)

- Same as count sort the time taken to perform this algorithm is $O(n)$

```cpp
void binBucketSort(int A[], int n){
    int max, i, j;
    Node **bins;
    max = findMax(A, n);
    bins = new Node*[max + 1];
    for(i = 0; i < max + 1; i++)
        bins[i] = NULL;
    for(i = 0; i < n; i++)
        insert(bins[A[i]], A[i]);
    
    i = 0, j = 0;
    while(i < max + 1){
        while(bins[i] != nullptr)
            A[j++] = delete(bin[i]);
        i++;
    }
}
```

## Radix Sort

- This sorting method is similar to bin buck sort, but in bin bucket sort we were taking an array of bins equal to the largest element present in the array.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2046.png)

- In this case the largest element is 348, if we do the same for this case it will require excessive space and we will therefore create a huge array. To make this simple we will have to use Radix Sort instead.
- Radix sort doesn’t take 348 bins, but it will take only ten bins, why? The array elements are integer numbers, what number system? decimal number system, so in total we will need 10 digits so we need to create an array from 0 to 9.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2047.png)

- If the elements in the array were in binary form then we would only need two bins and that would be enough, or if they were in octal form then 8 bins would be enough.
- So to continue to radix sort algorithm we would then have to initialize then 10 bins to null. Now we need to sort the numbers.
- In this procedure we need to scan the elements in the array, every element for example 237 doesn’t have to be dropped in the bins array, instead it should be dropped in bin 7 i.e. we should only check the last digit of the number. We can get the last digit of a number by using:
    
    ```cpp
    A[i] % 10
    ```
    

![Untitled](15%20-%20Sorti%202d34b/Untitled%2048.png)

- The final output will look like:

![Screen Shot 2022-01-13 at 17.52.45.png](15%20-%20Sorti%202d34b/Screen_Shot_2022-01-13_at_17.52.45.png)

- If we empty the bins array and take out the elements they will look like:$152,62,163,235,146,36,237,348,48,259$. We finished the first pass but they are not sorted yet so we need to drop them again on the bins, **but this time we should drop them on the second digit on the right hand side** i.e. 152 should be dropped at index 5, 62 should be dropped at index 6 and so on. We can get a second digit by using:

```cpp
(A[i] / 10) % 10
```

![Screen Shot 2022-01-13 at 17.59.58.png](15%20-%20Sorti%202d34b/Screen_Shot_2022-01-13_at_17.59.58.png)

- If we empty the bins the second pass will be $235, 36, 237,146,348,48,152,259,62,163$ still they are not sorted so we should drop them again on the bins, but this time we should drop them on the third digit on the right hand side, but what should we do with numbers that only have 2 digits like 36 for example, then we should assume the third digit on the right hand side is 0. We can get the third digit by using:
    
    ```cpp
    (A[i]/100)%10
    ```
    

![Screen Shot 2022-01-13 at 18.06.27.png](15%20-%20Sorti%202d34b/Screen_Shot_2022-01-13_at_18.06.27.png)

- If we empty all the elements in the bins array they will look like: $36, 48, 62, 146, 152,163,235,237,259,348$.
- We can guess how many passes would be needed to get the elements sorted by counting the number of digits the largest element in the array. 348 has three digits so three passes are needed.
- The time needed for performing this algorithm is based on the number of digits of the largest element in the array $O(dn)$.

```cpp
void Insert(Node** ptrBins, int value, int idx){
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;
    
    if (ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

int Max(int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int countDigits(int x){
    int count = 0;
    while (x != 0){
        x = x / 10;
        count++;
    }
    return count;
}

void initializeBins(Node** p, int n){
    for (int i=0; i<n; i++){
        p[i] = nullptr;
    }
}

int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) % 10;
}

void radixSort(int A[], int n){
    int max = Max(A, n);
    int nPass = countDigits(max);
    
    // Create bins array
    Node** bins = new Node* [10];
    
    // Initialize bins array with nullptr
    initializeBins(bins, 10);
    
    // Update bins and A for nPass times
    for (int pass=0; pass<nPass; pass++){
        
        // Update bins based on A values
        for (int i=0; i<n; i++){
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }
        
        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10){
            while (bins[i] != nullptr){
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }
    
    // Delete heap memory
    delete [] bins;
    
    for(int i = 0; i < n; i++)
        printf("%d ",A[i]);
    cout << endl;
}

int main() {
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    radixSort(A, 10);
    return 0;
}
» 36 48 62 146 152 163 235 237 259 348
```

## Shell Sort

- This technique is perfect for sorting a very large sized list.
- The name of this technique comes from the person who introduced it

[Donald Shell - Wikipedia](https://en.wikipedia.org/wiki/Donald_Shell)

- This technique is an extension of insertion sort i.e. it is based on its main idea.

To understand this algorithm we are going to use the following array:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2049.png)

- Like in insertion sort the elements are inserted one after another consecutively, but in shell sort the elements are inserted but distanced apart, so ther is a gap between them.
- The gap between those elements is defined by the number of elements in the list divided by 2: $gap=\frac n 2$. So in this list the gap will be 5.
- So let us start with 9, the element with a gap of 5 is 6. So let’s take both elements and compare which one is lesser, the lesser element should be the first element so in this case 6 should be at index 0 and 9 should be at index 5. This is the main idea and we will continue performing this with the remaining elements of the list.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2050.png)

- Now we have to slide the link by one, so we will now compare 5 and 12, nothing happens so we continue so we end up interchanging 16 and 10:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2051.png)

- Again we keep sliding until we reach the final where we can compare three elements, because if we count 3 and 0 there is a gap of 5 and if we count from 6 to 9 there is also a gap of 5 so we should compare the three and position them in the right order:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2052.png)

- Again we need to sort the elements because they aren’t sorted yet, **but this time we need to divide the gap by 2 again so it is 5 / 2 which is 2.**

![Untitled](15%20-%20Sorti%202d34b/Untitled%2053.png)

- If we slide by one we will encounter a similar situtation once again we must first  interchange 10 and 2, but there is also a chance we can compare the element at index 0 because there is also a gap of two elements there

![Untitled](15%20-%20Sorti%202d34b/Untitled%2054.png)

- Again we can slide by one and compare 5 and 6 but nothing happens because they are already sorted and it is the same case until we finish comparing 6 and 16, but again 12 and 8 are the exception because 8 is smaller than 12, so we switch them and we can compare it with 10 also so we position them in the right order and once again we can compare them with 3 as well but there is nothing to sort so we continue:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2055.png)

- Again if we compare 16 and 13, 13 is smaller so we can therefore compare 6, 13 and 16 but there is nothing to sort so we continue.

![Untitled](15%20-%20Sorti%202d34b/Untitled%2056.png)

- Again if we compare 12 with 9, 9 is smaller so we can therefore compare 10, 9 and 12 and there is something to sort so we can continue comparing 8, 9, 10 and 12. This is the end of the second pass so now we continue for the third pass but this time the gap will be 1

![Untitled](15%20-%20Sorti%202d34b/Untitled%2057.png)

- There are very few shifts here in the third pass so the final pass is solved when we compare 16 and 12, which 12 is smaller but we can compare 13, 16 and 12 so it will be:

![Untitled](15%20-%20Sorti%202d34b/Untitled%2058.png)

```cpp
void shellSort(int A[],int n){
    int gap,i,j,temp;
    
    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp){
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d ",A[i]);
    cout << endl;
}

int main() {
    int A[] = {9, 5, 16, 8, 13, 6, 12, 10, 4, 2, 3};
    shellSort(A, 11);
    return 0;
}
» 2 3 4 5 6 8 9 10 12 13 16
```