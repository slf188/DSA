//
//  main.cpp
//  Graphs
//
//  Created by Felipe Vallejo on 26/1/22.
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void breadthFirstSearch(int vertix, int A[][8], int n){
    int visited[8] {0};
    queue<int> q;
    int u;
    // Visit the starting vertex
    cout << vertix << " ";
    // Mark is as visited
    visited[vertix] = 1;
    // Enqueue the vertex in the queue
    q.emplace(vertix);
    // Repeat the loop until we have visited all the pending vertices
    while(!q.empty()){
        // Take out the vertex from the queue
        u = q.front();
        q.pop();
        // Visit the adjacent vertices
        for(int v = 1; v<=n; v++)
            // Check if it has been visited or not
            if(A[u][v]==1 && visited[v]==0){
                // Visit and enqueue the vertex
                cout << v << " ";
                visited[v] = 1;
                q.emplace(v);
            }
    }
    cout << endl;
}

void depthFirstSearch(int vertex, int A[][8], int n){
    int u;
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(vertex);
    
    while(!stk.empty()){
        u = stk.top();
        stk.pop();
        if(visited[vertex] != 1){
            cout << vertex << " ";
            visited[vertex] = 1;
            
            for (int v=n-1; v>=0; v--){
                if (A[vertex][v] == 1 && visited[v] == 0){
                    stk.emplace(v);
                }
            }
        }
    }
}

int main() {
    int A[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0}
    };
    
    int u = 5;
    cout << "dfs Vertex: " << u << " -> " << flush;
    depthFirstSearch(u, A, 8);
    cout << endl;
    return 0;
}
