#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SantaHouse {
private:
    vector<vector<int>> adj;
    vector<pair<int,int>> edges;
    vector<bool> usedEdge;
    vector<string> allPaths;
    
    void dfs(int u, string path) {
        if (path.length() == 9) {
            if (u == 2) allPaths.push_back(path);
            return;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (!usedEdge[i]) {
                int v = -1;
                if (edges[i].first == u) v = edges[i].second;
                else if (edges[i].second == u) v = edges[i].first;
                if (v != -1) {
                    usedEdge[i] = true;
                    dfs(v, path + to_string(v));
                    usedEdge[i] = false;
                }
            }
        }
    }
    
public:
    SantaHouse() {
        adj.resize(6);
        edges = {{1,2}, {1,3}, {1,5}, {2,3}, {2,4}, {3,4}, {3,5}, {4,5}};
        for (auto& e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        usedEdge.resize(edges.size(), false);
    }
    
    void findAllEulerPaths() {
        dfs(1, "1");
        sort(allPaths.begin(), allPaths.end());
        for (const string& path : allPaths) {
            cout << path << endl;
        }
    }
};

int main() {
    SantaHouse house;
    house.findAllEulerPaths();
    return 0;
}