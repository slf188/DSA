//
//  main.cpp
//  Graphs
//
//  Created by Felipe Vallejo on 26/1/22.
//

#include <iostream>
#include <queue>
#include <stack>
#define V 8
#define I 32767
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

void PrintMST(int T[][V-2], int G[V][V]){
    cout << "Minimum Spanning Tree Edges:" << endl;
    int sum {0};
    for (int i {0}; i<V-2; i++){
        int c = G[T[0][i]][T[1][i]];
        cout << "[" << T[0][i] << "]-[" << T[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << "Total cost of MST: " << sum << endl;
}

void PrimsMST(int G[V][V], int n){
    int u;
    int v;
    int min {I};
    int track [V];
    int T[2][V-2] {0};
    
    // Initial: Find min cost edge
    for (int i {1}; i<V; i++){
        track[i] = I;  // Initialize track array with INFINITY
        for (int j {i}; j<V; j++){
            if (G[i][j] < min){
                min = G[i][j];
                u = i;
                v = j;
            }
        }
    }
    T[0][0] = u;
    T[1][0] = v;
    track[u] = track[v] = 0;
    
    // Initialize track array to track min cost edges
    for (int i {1}; i<V; i++){
        if (track[i] != 0){
            if (G[i][u] < G[i][v]){
                track[i] = u;
            } else {
                track[i] = v;
            }
        }
    }
    
    // Repeat
    for (int i {1}; i<n-1; i++){
        int k;
        min = I;
        for (int j {1}; j<V; j++){
            if (track[j] != 0 && G[j][track[j]] < min){
                k = j;
                min = G[j][track[j]];
            }
        }
        T[0][i] = k;
        T[1][i] = track[k];
        track[k] = 0;
        
        // Update track array to track min cost edges
        for (int j {1}; j<V; j++){
            if (track[j] != 0 && G[j][k] < G[j][track[j]]){
                track[j] = k;
            }
        }
    }
    PrintMST(T, G);
}

int main() {
    int cost [V][V] {
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I},
    };
    
    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
    
    PrimsMST(cost, n);
    return 0;
}
