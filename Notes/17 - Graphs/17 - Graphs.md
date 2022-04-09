# 17 - Graphs

### What is a graph?

- A graph is a collection of vertices and edges i.e. the vertices are the nodes and the edges are the links.
- A graph is $G=(V,E)$

### What is the terminology for graphs?

![Untitled](17%20-%20Graph%20eda7c/Untitled.png)

- **Directed Graph:** It happens when the edges have directions.
- **Self Loop:** It happens in a directed graph if there is an edge connecting to the same vertex then it is called a self loop.
- **Parallel Edges:** It happens when there are a pair of edges connected viceversa.
- **Indegree:** It’s the number of edges connecting to an vertex (e.g. in the case of vertex 3, 2 vertices point on it).
- **Outdegree:** It’s the number of edges going out.

![Untitled](17%20-%20Graph%20eda7c/Untitled%201.png)

- **Simple Diagraph:** It only is possible if there are no parallel edges and no self loops. Diagraph means directed.

![Untitled](17%20-%20Graph%20eda7c/Untitled%202.png)

- **Graph**/**Non-directed Graph:** There are no directed edges, we can call it simply graph or non directed graph. Graph means indirected.
- **Degree:** The number of edges connected to a vertex is called as degree.

![Untitled](17%20-%20Graph%20eda7c/Untitled%203.png)

- **Non-connected:** A non connected graph is where there are more than one components and they are not connected. If we connect vertex 4 and 6 then the graph becomes connected.
- **Components:** Components are individual graphs.

![Untitled](17%20-%20Graph%20eda7c/Untitled%204.png)

- **Strongly Connected:** A directed graph that allows us to start from any vertex and reach any vertex (e.g from 4 we can reach to 5, 2 or 3).
- **Path**: All the set of vertices in between a pair of vertices (e.g. from 1 to 5 the path is 1 to 2 and 2 to 5)
- **Cycle:** We start at one vertex and end at the same vertex (e.g. the vertex 2 goes around 5 and 4 and then it returns to the origin).

![Untitled](17%20-%20Graph%20eda7c/Untitled%205.png)

- **DAG:** There are no cycles in this graph, if we start from a particular vertex we cannot return in any way possible.

![Untitled](17%20-%20Graph%20eda7c/Untitled%206.png)

- **Topological Ordering:** We can rearrange the DAG graph such that they are positioned linearly such that the edges are going only in forward direction, the edges are not going back.

## Representation of Undirected Graph

- For representing a graph we need to represent a few things including the vertices and also the set of edges.
- For representing them there are the following methods for doing so:
    1. Adjacency Matrix
    2. Adjacency List
    3. Compact List

Now let us check every single one of these methods:

### Adjacency Matrix

![Untitled](17%20-%20Graph%20eda7c/Untitled%207.png)

- We need to represent this graph that is represented with vertices and edges. The number of vertices is represented as n that is 5, and the number of edges that are represented with a symbol e are 7.
- For representing the keys in the matrix we need to take a matrix of 5x5.
- To represent the elements we need to mark 0 if there is no edge and 1 if there is an edge. In the case of vertex 1 no edges appear in 1 and 5 so the matrix will be:

![Untitled](17%20-%20Graph%20eda7c/Untitled%208.png)

- Now for the second vertex only 1 and 3 and the remaining ones are zero:

![Untitled](17%20-%20Graph%20eda7c/Untitled%209.png)

- Once we fill the rest it will be:

![Untitled](17%20-%20Graph%20eda7c/Untitled%2010.png)

### Adjacency List

- In this method we need to do the corresponding representation we need an array of linked list. So we need an array of size 5.
- Each location will represent a vertex, for every location we have to write down the set of connected vertices (e.g. if we take 1 then the connected vertices are 2, 3, and 4).

![Untitled](17%20-%20Graph%20eda7c/Untitled%2011.png)

- Similarly the rest of the elements will be:

![Untitled](17%20-%20Graph%20eda7c/Untitled%2012.png)

### Weighted List

- There is also another type of graph called Weighted Graph which would look like:

![Screen Shot 2022-01-26 at 19.58.13.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-26_at_19.58.13.png)

- If weights are given then we need to store those weights also. In this case the result will be:

![Screen Shot 2022-01-26 at 20.00.05.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-26_at_20.00.05.png)

- In the case of an adjecency list the result will be storing the vertices and also the weights:

![Untitled](17%20-%20Graph%20eda7c/Untitled%2013.png)

### Compact List

- In this method we will only have a single dimension array for representing a single graph, the size of the array should be:

$$
V+2E+1\\5+2(7)+1=21
$$

- This means we need to create an array of size 21:

- From index 1 to 5 we need to represent the vertices, then after an empty space we need to store the adjacent vertices of vertex 1 and we continue doing so by then storing the adjacent vertices of 2 and so on:
    - At index 1 we need to write down the starting index where the adjacent vertices are stored i.e. in this case it will be 7.
    - At index 2 we need to write down the starting index where the second adjacent verties are stored.

![Untitled](17%20-%20Graph%20eda7c/Untitled%2014.png)

- If we pay attention to the vertices section of the array we can see that we have divided each group, after the vertices we need to write down the size of the array + 1.

![Untitled](17%20-%20Graph%20eda7c/Untitled%2015.png)

## Representation of Directed Graphs

Let’s try to understand this by using an adjacency matrix.

![Untitled](17%20-%20Graph%20eda7c/Untitled%2016.png)

- Each row or column represents a vertex.
- Same as before we need to mark with 1 whenever there is an edge.

So the output will be:

![Untitled](17%20-%20Graph%20eda7c/Untitled%2017.png)

If we want to represent this using adjacency list then:

- Each location must represent a vertex.

So the output will be:

![Screen Shot 2022-01-26 at 21.14.44.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-26_at_21.14.44.png)

## Breadth First Search

- As a graph is a nonlinear data structure, there are two graph traversal methods like:
    1. Breadth First Search
    2. Depth First Search
- Breadth First Search is similar to the level order of a binary tree, here we will not get a binary tree, instead we will just get a tree.

BFS is similar in level order because of the following reasons, let’s take the following example:

![Screen Shot 2022-01-27 at 17.57.09.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-27_at_17.57.09.png)

- This graph can be converted into a the form of a tree, you see a graph without any edges is a tree.
- To create a tree we start with the following steps:
    - The vertices start from 1 to 7 so we must start with vertex 1, the connected vertices are 2, 3 and 4 so the tree will be:
    
    ![Untitled](17%20-%20Graph%20eda7c/Untitled%2018.png)
    
    - Now we must find which vertices are adjacent to 2, only 3 but 3 is already connected to 1 and if we mistakenly link 2 and 3 then we will create a graph which is not what we want. Instead we must create a dotted edge like this:
    
    ![Untitled](17%20-%20Graph%20eda7c/Untitled%2019.png)
    
    - Next we must find the adjacent of the rest of the elements, now 3 is connected to vertex 5 and 4 so it will be:
    
    ![Untitled](17%20-%20Graph%20eda7c/Untitled%2020.png)
    
    - Now the final output wil be:
    
    ![Untitled](17%20-%20Graph%20eda7c/Untitled%2021.png)
    
- Now this is not a binary tree, because there is a node that has three children so it is a tree. The BFS for this tree is $BFS: 1,2,3,4,5,6,7$
- Now the question is, Is this the only tree that can be created? No we can change the order of the nodes, at any order it doesn’t make any difference. But the level order will obviously change for sure.

![Screen Shot 2022-01-27 at 18.12.05.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-27_at_18.12.05.png)

- Is it necessary for us to start from vertex 1 only? No, we can start from any vertex.

![Screen Shot 2022-01-27 at 18.14.30.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-27_at_18.14.30.png)

### BFS explanation

- BFS states that we can start traversal from any starting vertex we want.
- Once we have visited a vertex, we must explode that vertex completely, by exploration it means if we have selected 4 then we have visited all the other adjacent vertices.
- BFS can be defined using two terms:
    1. Visiting: Means going upon a particular vertex.
    2. Exploring: Means if we are on a particular vertex we also visit all the other adjacent vertices.

![Screen Shot 2022-01-27 at 17.57.09.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-27_at_17.57.09.png)

- The procedure is the following if we take this graph:
1. Select the starting vertex, visit it and drop it in the queue:
    
    ![Screen Shot 2022-01-27 at 18.22.50.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-27_at_18.22.50.png)
    
2. Select another vertex from the queue and explore. Take out the vertex from the queue and explore its adjacent vertices
    
    ![Screen Shot 2022-01-27 at 18.24.36.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-27_at_18.24.36.png)
    
3. We continue this procedure and at last we will get:
    
    ![Screen Shot 2022-01-27 at 18.26.44.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-27_at_18.26.44.png)
    

### BFS program

- For creating a bfs program we can use an adjacency matrix that will help us see which vertices we have visited and which ones we have yet to visit. We musn’t use index zeroes, we must start from index 1 upwards:
    
    ![Screen Shot 2022-01-27 at 18.52.31.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-27_at_18.52.31.png)
    
- 1 and 0 will tell which vertices are visited and which are not so in addition we must use an array queue where we enqueue and dequeue elements from the vertices, and we will also need a visited array, where we take into account which elements have been visited:
    
    ![Screen Shot 2022-01-27 at 18.52.55.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-27_at_18.52.55.png)
    

## Depth First Search

- This is another graph traversal method.
- This is method is similar to preorder traversal of a binary tree.
- The main idea of DFS is **“Start from any vertex you want, then you have to explore it. And once you got a new vertex, suspend its exploration and start exploring the new vertex.”**
- To understand this we need to keep two terms:
    1. **Visited:** When we have reached or visited a vertex.
    2. **Exploring:** Visiting all adjacent vertices

![Screen Shot 2022-01-27 at 17.57.09.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-27_at_17.57.09.png)

Let’s perform DFS upon this graph:

- In this case we will make use of a stack.
- We can use any vertex as a starting vertex.
- Let’s pick 1, and take the vertices adjacent to 1 which are 2, 3 and 4. But we only add 2 to the tree and suspend everything else.
- Then we can finally push 1 to the stack. To continue the exploration afterwards. Until this point DFS is $DFS: 1,2$

![Untitled](17%20-%20Graph%20eda7c/Untitled%2022.png)

- Now we can start exploring 2, we can then continue to go onto 3, suspend the exploration of 2 and start exploring 3. 2 should be pushed into the stack.

![Untitled](17%20-%20Graph%20eda7c/Untitled%2023.png)

- So this means that whenever we get a new vertex, we suspend the current vertex, push it into the stack and explore the new vertex. That is the approach of Depth First Search.
- There is also no particular order of following the vertices i.e. it is ok to take 5 and then 4.

![Untitled](17%20-%20Graph%20eda7c/Untitled%2024.png)

- If we encounter the following situation where from 7 we cannot go anywhere, then this means 7 is completely explored. If we have finished visiting all the adjacents then we can go back to explore the previous vertex, 5 so pop out, explore it again and the next vertex is 6. Again push 5 into the stack and start exploring 6. From 6 we cannot go anywhere so pop out 5, from 5 we can go to 4 also so add 4 and push 5 again into the stack and start exploring 4, from 4 we can go to 3 or 1, which are both already visited. So pop out 5 and go back and see what options we have from there, apparently we have already finished visiting 6 and 7 so 5 is already explored which makes us go back to 3, we draw a dotted edge with 1, go back to 2 and finally go back to 1 and we have finished popping out all the elements from the stack.

![Untitled](17%20-%20Graph%20eda7c/Untitled%2025.png)

### Program for DFS

- DFS uses a stack so we need to take it into consideration. So we can use a recursive function.
- Again we will use an adjacency matrix for representation as we did on BFS. And we will also need a visited array.

# Spanning Trees

- A spanning tree is a subgraph of a graph, having all the vertices of a graph included but $n-1$ edges. So that there is no cycle formed by those edges and the graph must be connected.

$$
G=(V,E)\\n=V\\e=E\\S/G\\S=(V',E')\\V'=V\\E'=V-1
$$

So if we represent this statement graphically then it will be:

![Untitled](17%20-%20Graph%20eda7c/Untitled%2026.png)

- There are four vertices, we should therefore only take 3 edges.
- The place where the edges are located can vary, so the order can differ.
- But we have to make sure that there is no cycle because that is not a spanning tree. We must connect all the vertices.

### Can we calculate how many spanning trees can be generated?

We can do this for sure by using the following formula:

$$
^EC_{V-1}-cycles
$$

- If we use this formula as an example it will look like this:

$$
V=4\\E=6\\\\^6C_3-4=20-4=16
$$

- This means there are 16 possible spanning trees that can be generated for a case where we have 4 vertices and 6 edges.

### What is a Minimum Cost Spanning Tree?

- For understanding this concept let’s put some weights on the graph.
- The main idea behind this new concept is that we want to generate a spanning tree such that the total cost of the spanning tree must be minimal. By cost we mean the total weight of all the edges included in the newly generated spanning tree.
- We can generate all the possible spanning trees and select the best one.

There are a few algorithms that help us do the job of finding the best spanning tree including:

1. Prim’s Algorithm
2. Krustal’s Algorithm

## Prim’s Algorithm

To understand this algorithm we will take the following graph and see how Prim’s Algorithm can be used here:

![Screen Shot 2022-01-28 at 18.32.48.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-28_at_18.32.48.png)

- All the vertices are connected in this graph so we can absolutely make a spanning tree or a minimum cost spanning tree.

The steps for executing Prim’s Algorithm is the following:

1. Select a minimum cost edge from the graph, in this case it will 1 - 6. From now on we need to repeat this step over and over again.

![Untitled](17%20-%20Graph%20eda7c/Untitled%2027.png)

1. Now select a minimum cost edge, but it must be connected to the already picked vertices i.e. 1 and 6. If we analyze we can only compare 5 and 2, so 5 is the smaller one so we pick that one.

![Untitled](17%20-%20Graph%20eda7c/Untitled%2028.png)

1. Now again select a minimum that is connected to the current vertices.

![Untitled](17%20-%20Graph%20eda7c/Untitled%2029.png)

1. If we continue until we reach the end of the loop the graph will be:

![Untitled](17%20-%20Graph%20eda7c/Untitled%2030.png)

1. The total cost will be 60 if we add up all the weights in our graph.
2. Now why did Prim’s suggested that the graph must be connected? Because we need to achieve 2 things:
    1. It must be a spanning tree, it must be connected and it must not have cycles.
    2. We want the minimum cost possible, we need to always have to maintain a tree and then focus on achieving the cost.
- If we do some analysis on Prim’s algorithm we will see that it will take $o(n\log n)$.

### Prim’s Program

- Remember that the main rule of DSA is: **for converting any algorithm into a program we must identify two things, what is the data structure required and the instructions.**
- For this algorithm we will use a 2D array that is an adjacency matrix for the graph that will store the cost of the edges.
- The graph includes keys that range from 1 to 7, and in C++ array start from 0 upwards so we must ignore 0 on the column and row sense. And in the places where there are no edges we can fill them with a hyphen symbol.
- Whatever the spanning tree that we are getting we should store it inside a 2d array called t.
- Plus we need an array called near that should start being filled with hyphens on all indexes and it will help us keep track of which vertices have already been included by using 0. And store the vertices that are nearer to any of the already taken vertices.

![Screen Shot 2022-01-28 at 19.22.30.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-28_at_19.22.30.png)

The steps are the following ones:

1. As a first step we pick the smaller vertex and store it inside t so it will be and mark 0 on the array near at index 1 and 6.
    
    ![Screen Shot 2022-01-28 at 19.27.42.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-28_at_19.27.42.png)
    
2. Next we need to find all the other vertices and check whether they are near to 1 or 6. So index to is near to 1, so we mark it with 1, next vertex 3 where both 1 and 6 is infinity so we write 6, next vertex 4 again we write 6, at index 5 again we write 6 and finally write 6 at index 7.
3. Now the repeating steps will start. Every single time we add a new pair at t we need to update the near array and repeat the same process again and again. The final output wil be:
    
    ![Screen Shot 2022-01-28 at 19.51.38.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-28_at_19.51.38.png)
    

## Kurstal’s Algorithm

- This method is a bit simpler than Prim’s method, to understand this method we will use the following graph as an example:

![Screen Shot 2022-01-29 at 20.18.21.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-29_at_20.18.21.png)

- There is no initial step in Kurstal’s algorithm, all the steps are repeating.
- The repeating step for this algorithm is **“Always select the minimum cost edge, but make sure they are not forming a cycle.”.**
- The minimum cost edge in this graph will be 5.
- Then the next minimum is 6 and then 9, and then 10. But here is the tricky part because if we then select 11 we will form a cycle. So instead of taking 11 we should skip that part.
- So to avoid that part we need to select 12, from there if we take 16 it will form a cycle so skip that part. Instead grab 18 and finish the algorithm is concluded.

![Screen Shot 2022-01-29 at 20.26.37.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-29_at_20.26.37.png)

- The total cost of this graph is 60.
- If we want to perform this algorithm in a non connected graph, it will always avoid a cycle.

### Analysis

- The time taken to complete this algorithm depends on the edges selected, that means we are only selecting $V-1$ edges. In conclusion this algorithm take $O(n^2)$ time. Independent of the data structure used we are only analysing based on the work that is performed.
- But we can actually improve this algorithm by using a data structure that always provides the minimum or maximum value i.e. Heap. By using heap the algorithm will take $O(n\log n)$ time to complete.

### Disjoint Subsets

- This is useful for detecting cycles in a graph.
- Imagine we have a set that contains $u=[1,2,3,4,5,6,7,8,9,10]$, if we take that set and create to subsets we end up having $A=[3,5,9] ~~~B=[4,7,8,10]$, if we analyze the two subsets we will see that we have an intersection of 5.
- For representing this the best data structure is an array.
- We have to use nodes, and the best way to represent the subsets is by making them point on the first element of those subsets, per say:

![Screen Shot 2022-01-29 at 20.55.34.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-29_at_20.55.34.png)

- So to represent this in an array we can write it like this:

![Screen Shot 2022-01-29 at 20.56.23.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-29_at_20.56.23.png)

- So index 3’s -3 means it contains 3 elements inside, and the ones with a positive 3 means they belong to 3. And that applies the same to element 4. The remaining elements can be set as -1.
- From here on we can perform 2 operations: Union and Find

The program for performing Union is:

```cpp
void union(int u, int v){
	if(s[u]<s[v]){
		s[u]=s[u]+s[v];
		s[v]=u;
	}else{
		s[v]=s[u]+s[v];
		s[u]=v;
	}
}
```

The program for performing Find is useful for finding who is the parent of every node, that means if we find a negative value in the array then, Bingo! That is the parent node.

```cpp
int find(int u){
	int x = u;
	while(s[x]>0)
		x = s[x];
	return x;
}
```

### Kruskal’s Program

![Screen Shot 2022-01-29 at 20.18.21.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-29_at_20.18.21.png)

- We are going to use the exact same graph for demonstrating how we can make a program.
- We are going to need:
    - Array of edges: We are not using an adjacency matrix anymore, instead we are using a list of edges. The array is of 3 rows and 9 columns. 9 because there are 9 edges. The first row contains the first vertex number, the second row contains the second vertex number and last row contains the cost.
    
    ![Screen Shot 2022-01-30 at 11.48.55.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-30_at_11.48.55.png)
    
    - included array: This array will help us see which vertices have been already included or which ones haven’t been included. It must be of size 9 starting with values of 0 and whichever edge is included we shall mark them with 1.
        
        ![Screen Shot 2022-01-30 at 11.57.11.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-30_at_11.57.11.png)
        
    - t array: This array will help us store the result, it must be a 2d array containing 2 rows and 6 columns.
        
        ![Screen Shot 2022-01-30 at 11.56.52.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-30_at_11.56.52.png)
        
    - set array: This will be used to detect a cycle, in order to detect those we need to perform union and find operations. It must be of size 7, all of the indexes will be marked with -1, except for index 0 that will be x.
        
        ![Untitled](17%20-%20Graph%20eda7c/Untitled%2031.png)
        
    
    Procedure:
    
    1. We first find the lowest cost at the third row of the array of edges array, it is located at index 1, we set a variable j at index 1. We check if it is included at the included array, if it is not we can then proceed onto checking if it is forming a cycle so we check every number at index 1 from the edges array, 1 is -1 at the set array, 6 is -1 so that means they are parents of themselves. Then we go to array t and set a variable i at index 0 and place 1 and 6 inside the array t. Now we can mark 1 in the included array at index 1. Now we can perform weighted union so where index 1 and 6 was -1 at the set array we should write 6 at index 1 and -2 at index 6. -2 means 6 is the parent of itself and 1 will be pointing towards it.
    2. Again we must first check which elements is the minimum at the edges array, it will be index 4, it is not included so mark 1 at index 3 and 4, then find 3 and 4 at the set array, they are -1 so we can put 4 at index 3 and -2 at index 4. Then we will include 3 and 4 at index 2 of the array t.
    3. Again we repeat this procedure until we are finished checking all possible options.
    4. At last this is what we will get:
    
    ![Screen Shot 2022-01-30 at 12.10.43.png](17%20-%20Graph%20eda7c/Screen_Shot_2022-01-30_at_12.10.43.png)