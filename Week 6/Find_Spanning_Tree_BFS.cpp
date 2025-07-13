#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

//BFS 
vector<pair<int,int>> findSpanningTreeBFS(vector<vector<int>>& adj, int n) {
    vector<pair<int,int>> tree;
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(0);
    visited[0] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                tree.push_back({u, v});
                q.push(v);
            }
        }
    }
    
    return tree;
}

int main() {
    vector<vector<int>> adj = {{0, 1, 0, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}, {0, 0, 1, 0}};
    vector<pair<int,int>> tree = findSpanningTreeBFS(adj, 4);
    cout << "P 10.2: Spanning tree edges (BFS): ";
    for (auto edge : tree) cout << "(" << edge.first << "," << edge.second << ") ";
    cout << endl;
    return 0;
}