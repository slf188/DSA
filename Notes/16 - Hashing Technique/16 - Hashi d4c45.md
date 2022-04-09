# 16 - Hashing Technique

### What is hashing?

- Hashing is a tecnique that is used for searching a particular element we desire.
- Hashing is used to search keys in less than $\log n$ time i.e. almost constant time.
- For searching we’ve already seen two methods: binary and linear search, from which binary search is the fastest one the two. But could there be a method that is faster than the two? Their time complexity is:
    - Linear $O(n)$
        - The requirement for performing this tecnique is that the elements musnt’ be sorted.
        
        ![Untitled](16%20-%20Hashi%20d4c45/Untitled.png)
        
    - Binary $O(\log n)$
        - The requirement for performing this tecnique is that the elements must be sorted i.e. we need some extra effort to apply this method.
        
        ![Untitled](16%20-%20Hashi%20d4c45/Untitled%201.png)
        
    - Hashing $O(1)$
        - Hashing on the other hand works the following way: if we have a set of keys $8,3,6,10,15,18,4$ we should store them in their corresponding indexes e.g. 8 should be at index 8 and so on..., the remaining empty elements are filled with zeros, this makes searching extremely easy that the algorithm takes place at constant time.
        - The only drawback of hashing is that let’s say largest element in a list is 20, so we need to create an array up to index 20. So a lot of space is required, and a lot of space is wasted.
        
        ![Untitled](16%20-%20Hashi%20d4c45/Untitled%202.png)
        
- To reduce this huge consumption of space, let us look at a mathematical model we can use to represent hashing:

![Untitled](16%20-%20Hashi%20d4c45/Untitled%203.png)

- Let us take this graph, we have the keys stored at key space and we have a table where we can store our elements.
- The keys should be mapped on the hash table, we need to find a relation that we can use to link those elements to their corresponding indexes. Which will be:

![Untitled](16%20-%20Hashi%20d4c45/Untitled%204.png)

- The function for mapping the elements is $h(x)=x$, we plug a index and we get the element at the index. In conclusion this is called **ideal hashing** because the timetable for searching an element is constant.
- Now let’s talk about the enourmour size of the hash table, even though we only have 7 elements the table’s size is 19, it is really inefficient because imagine we have an element 100, then we would need to create a hash table of size 101. The only one to blame for such atrocity is the hash function. But we could achieve the same thing in limited space by modifying the hash function by using the modulo function:

$$
h(x)=x\%10
$$

- By making this modification the hash function will never give us values greater than 9. Let’s say we want to store 10, then it must be stored at index 0 and 15 should be stored at index 5.

![Screen Shot 2022-01-14 at 16.32.12.png](16%20-%20Hashi%20d4c45/Screen_Shot_2022-01-14_at_16.32.12.png)

- The only drawback of using the modulus function is if we have 25, it should be mapped at index 5 where 15 is already present and **when two keys are mapped at the same location it is called collision.**
- There are a number of mapping cases:
    - one-one: Standard hash function
    - one-many
    - many-one: Modulus function
    - many-many
- For resolving collison we can use:
    - Open Hashing: We can consume extra space in the hash table.
        - Chaining
    - Closed Hashing: We are constrained to the size given of the hash table.
        - Open addressing: We will not store an element strictly at the index given, we can use an empty space
            1. Linear Probing
            2. Quadratic Probing
            3. Double hashing

## Chaining

- Chaining will be our solution for avoiding collusions whenever two elements map on the same location when we use the modulus hash function.
- Chaining is one of the methods to avoid collusions and it is under the Open Hashing section.
- To understand chaining we will see:
    1. Insertion
    2. Search
    3. Analysis
    4. Deletion

### Insertion

To being learning about chaining we will take the following set of keys where we have a key space and a hash table of size 10:

![Untitled](16%20-%20Hashi%20d4c45/Untitled%205.png)

- When we insert keys this time we will create nodes that will be linked to every single index in the table. If we insert the keys using the hash function we will get:

![Untitled](16%20-%20Hashi%20d4c45/Untitled%206.png)

- Now we see that there is a collison between keys 16 and 6, but fear not because we are using nodes we can link the two nodes, the nodes should be order in ascending order.
- Again we will encounter the same situation between 122 and 12; and 5, 25 and 75, so we apply the same rule on the three cases.

![Untitled](16%20-%20Hashi%20d4c45/Untitled%207.png)

- Now we’ve seen how insertion works, we conclude that there is no limit for the size we can take in this array.

### Search

- Let’s say I want to search for key 12, we must first plug in 12 in the modulus hash function and at index 2 we should look for 12, 12 is found in one comparasion.
- Now let’s search for 75, we plug 75 in the function and head over to index 5, there we compare the nodes and find which node includes 75, if not we go to the next node.
- If we search for 64 the search will be unsuccesful because 65 is smaller and greater than 25 so we end the search.

### Analysis

- Because there is not limit to the number of elements we can insert in this type of hash table it becomes extremely efficient.
- The loading factor is also another thing we should consider because it measures the number of keys divided by the size of the table:

$$
Loading \ Factor\ \lambda = \frac{n}{size}
$$

- The analysis in this case should be based on loading factor, not on elements.
    - So let’s say we have 100 elements and the size is 10, so the loading factor in this case is 10.
    - This means that at each location there ten keys. So in conclusion we say that the 100 keys will be uniformly distributed at each location.
- The average time for a succesful search is:

$$
t=1+\frac{\lambda}{2}
$$

- The avarage time for an unsuccesful search is:

$$
t=1+\lambda
$$

### Deletion

- This is a similar procedure to how search works.
- Suppose I want to delete 12, we plug it in the hash function and go to index 2, we find it and delete the node.

### Problem with chaining

- Let’s say we have a list of 9 keys, all the keys will be mapped at the same index 5 and the rest of the indexes will be completely empty and therefore the assumption that all elements will be uniformly distributed according to the loading factor fails.
- The responsible for this problem is the programmer because we should always take in consideration this situation so we need to select the right hash function.

## Linear Probing

- Linear Probing is a collision resolution technique.
- Linear probing comes as under closed hashing, so it means that this technique consume any extra space and it will only stick to the given size of the hash table.
- To understand linear probing again we have to understand how the four operations are conducted.

To understand linear probing we have taken the following set of keys:

![Untitled](16%20-%20Hashi%20d4c45/Untitled%208.png)

### Insertion

- One thing we need to remember is that whereas in the previous techniques the hash function was $h(x)=x \% 10$, this time the hash function will be:

$$
h(x)=(h(x)+f(i))\%10 \\ where \ f(i)=i \\ i=0,1,2,...
$$

- The procedure of inserting the keys is very simple, all we need to do is just plug in the values in the standard hash function.
- Whenever there is a collison we have to store the extra element at the next free space.
- The explanation of the linear probing function is take 25 for example:
    - We got 5 as a result but the problem is that index has already been taken so we need to search for a free space in the next index.
        
        $$
        h'(25)=(h(25)+f(0))\%10 \\h'(25)=(5+0)\%10=5
        $$
        
    - Because index 5 was already taken we should now do i++. And again 6 has already been taken so again i++.
    
    $$
    h'(25)=(h(25)+f(1))\%10\\h'(25)=(5+1)\%10=6
    $$
    
    - Now i = 2 so the result this time is 7, so index 7 is free now so we can take that index to place 25 there. Every single time we are trying with a new value i starts from 0 every single time.
    
    $$
    h'(25)=(h(25)+f(2))\%10\\h'(25)=(5+2)\%10=7
    $$
    
- In a hypothetical case where index 9 is already occupied, then the next value where we should place our key should be index 0, so this is cyclic in other words.

If we insert the remaining keys the final output will be:

![Untitled](16%20-%20Hashi%20d4c45/Untitled%209.png)

### Search

- For searching we use the same hash function.
- Let’s consider the following examples:
    - Let’s search 45, we plug it in the standard hash function and get it at index 5.
    - Let’s search 74, we plug it in the standard has function and get index 4 but it is not there so we must use the linear probing hash function and after 5 failed comparisons we finally get it at index 8.
    - Let’s search 40, we use the standard function and it isn’t at index 0 so if we continue we might find ourselves at index 2 where there is no key found, so that means 40 is not present at the hash table. So this becomse unsuccesful.

### Analysis

- Analysis of hashing is done based on loading factor not based on the number of elements.
- The loading factor in this case is $\lambda = \frac9{10} = 0.9$
- The loading factor should never exceed $\lambda \le0.5$, this means that if the hash table is size 10 then we should never place more than 5 keys.
- Time is dependent on the loading factor so the avg succesful search is $t=\frac1\lambda \ln(\frac1{1-\lambda})$ and the avg unsuccesful search is $t=\frac1{1-\lambda}$.

### Deletion

Let’s consider the following examples:

- 25, using the hash function we go to index 5 and from there we search for 25, in case 25 is not there we use the linear probing hash function and if we get it we delete it and besides that we should move the element next to it onto the current position i.e. 74 should move to index 7 because it belonged to index 4 initially. This process is called Rehashing.
- Deletion takes a lot of work to do in linear probing that’s why it is not suggested to be performed instead we could use rehashing but that is also extremely time consuming.

## Quadratic Probing

To understand quadratic probing we have used the following set of keys:

![Untitled](16%20-%20Hashi%20d4c45/Untitled%2010.png)

- We will only take 4 keys because as previously mentioned the loading factor should not exceed 5.

The hash function for quadratic probing in this case is somewhat similar to the previous hash function:

$$
h'(x)=(h(x)+f(i))\%10 \\ where \ f(i)=i^2 \\ i=0,1,2,...
$$

This means that in linear probing if there was a collison we would try to insert an element at the next free space but here we will be giving a little gap and then store the element.

### Insertion

- Again every single time we want to insert an element we must use the standard hash function and for example element 23 will go at index 3.
- Now 43 wil have a collision so we plug it in the quadratic hash function, when i = 0 we will get 3, 3 is already taken so i++, then i = 1 will give us 4 so there is a free space so 43 wil be at index 4.
- Now 13 will have a collision at index 3 so again i will only work until i = 2, so it wil belong to index 7. $(3+4)\%10=7$
- And 27 will be stored at index 8.

## Double Hashing

To understand double hashing we must use the following example:

![Untitled](16%20-%20Hashi%20d4c45/Untitled%2011.png)

- The hash function used in double hashing is the following one:
    - R is a primary number that is smaller than the size of the hash table, we can use 7.
    - The first requirement of using this hash function is that it should never give us a result of 0.
    - The second requirement is that it should try to cover all the indices.

$$
h1(x) = x\%10\\ h2(x)=R-(x\%R)\\h'(x)=(h_1(x)+i*h_2(x))\%10\\where \ i=0,1,2...
$$

### Insertion

- 5, we plug it in the standard hash function, we insert it at index 5.
- 25, will get mapped at the same location where 5 is at. Because there is a collision we should use the modified hash function it will be: So it means that 25 should be stored at index 8.
    
    $h2(25)=7-(25\%7)\\h2(25)=7-4=3\\h'(25)=(5+1*3)\%10=8$
    
- All the remaining keys will have a collision at index 5 so we must continue using the aux hash function to mapped them in their right positions.
    
    $h'(15)=(5+1*6)\%10=1\\h'(35)=(5+1*7)\%10=2\\h'(95)=(5+1*3)\%10=8$
    
- Because 95 using i = 1 gives us index 8 that has already been taken then we should do i++ and continue searching for a suitable index.
    
    $h'(95)=(5+2*3)\%10=3\\h'(95)=5+3*3)\%10=4$
    
- Index 4 is vacant so we can use it in this case. The final output is:

![Untitled](16%20-%20Hashi%20d4c45/Untitled%2012.png)

## Hash Function Ideas

There are three main hash function we can use

1. Mod: It is always suggested that the size of the hash table should always be a prime number.

![Untitled](16%20-%20Hashi%20d4c45/Untitled%2013.png)

1. Midsquare: Whatever the key is, we square that key and take the middle digit (e.g. 11 it should be inserted at 2 because the square is 121 and the middle digit is 2)
2. Folding
- The hash funciton should be selected such that the values in the table must be uniformlly distributed, no matter what method we are using we should respect this requirement.
- Based on the date we are going to insert in the table then we can select the size as well as the type of the hash function so that collisions as avoided.
- If we are using chaining then the hash table size can be anything but if we are using linear probing then the hash table size should be double the number of elements that we are going to insert i.e. the loading factor should not exceed 5.
- A suitable hash function is one that it should always give you the key at the same index where we stored it initially.
- Languages like java or .net provide built-in hashing, whenever we create an object a hash code is given for that same object.