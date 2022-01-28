//
//  main.cpp
//  Graphs
//
//  Created by Felipe Vallejo on 26/1/22.
//

#include <iostream>
#include <queue>
using namespace std;

void breadthFirstSearch(int vertix, int A[][8], int n){
    int visited[8] {0};
    queue<int> q;
    int u;
    // Visit the starting vertex
    cout << vertix;
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
                cout << v;
                visited[v] = 1;
                q.emplace(v);
            }
    }
    cout << endl;
}

void depthFirstSearch(){
    
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
    
    cout << "Vertex: 1 -> " << flush;
    breadthFirstSearch(1, A, 8);
    
    cout << "Vertex: 4 -> " << flush;
    breadthFirstSearch(4, A, 8);
    
    return 0;
}
