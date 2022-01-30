//
//  main.cpp
//  Graphs
//
//  Created by Felipe Vallejo on 26/1/22.
//

#include <iostream>
#include <queue>
#include <stack>
//#define V 8
#define I 32767
#define V 7  // # of vertices in Graph
#define E 9  // # of edges in Graph
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

void PrintMCST(int T[][V-1], int A[][E]){
    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    for (int i {0}; i<V-1; i++){
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}

// Set operations: Union and Find
void Union(int u, int v, int s[]){
    if (s[u] < s[v]){
        s[u] += s[v];
        s[v] = u;
    } else {
        s[v] += s[u];
        s[u] = v;
    }
}

int Find(int u, int s[]){
    int x = u;
    int v = 0;
    
    while (s[x] > 0){
        x = s[x];
    }
    
    while (u != x){
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}

void KruskalsMCST(int A[3][9]){
    int T[2][V-1];  // Solution array
    int track[E] {0};  // Track edges that are included in solution
    int set[V+1] = {-1, -1, -1, -1, -1, -1, -1, -1};  // Array for finding cycle
    
    int i {0};
    while (i < V-1){
        int min = I;
        int u {0};
        int v {0};
        int k {0};
        
        // Find a minimum cost edge
        for (int j {0}; j<E; j++){
            if (track[j] == 0 && A[2][j] < min){
                min = A[2][j];
                u = A[0][j];
                v = A[1][j];
                k = j;
            }
        }
        
        // Check if the selected min cost edge (u, v) forming a cycle or not
        if (Find(u, set) != Find(v, set)){
            T[0][i] = u;
            T[1][i] = v;
            
            // Perform union
            Union(Find(u, set), Find(v, set), set);
            i++;
        }
        track[k] = 1;
    }
    
    PrintMCST(T, A);
}



int main() {
    int edges[3][9] = {
        { 1, 1,  2,  2, 3,  4,  4,  5,  5},
        { 2, 6,  3,  7, 4,  5,  7,  6,  7},
        {25, 5, 12, 10, 8, 16, 14, 20, 18}
    };
    
    KruskalsMCST(edges);
    return 0;
}
