#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

struct Edge {
    int u, v;
    Edge(int u, int v) : u(min(u,v)), v(max(u,v)) {}
    bool operator<(const Edge& other) const {
        if (u != other.u) return u < other.u;
        return v < other.v;
    }
};

bool isTree(vector<Edge>& edges, int n) {
    if (edges.size() != n - 1) return false;

    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        adj[e.u].push_back(e.v);
        adj[e.v].push_back(e.u);
    }
    
    vector<bool> visited(n, false);
    int count = 0;
    
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        count++;
        for (int v : adj[u]) {
            if (!visited[v]) dfs(v);
        }
    };
    
    dfs(0);
    return count == n;
}

vector<vector<Edge>> generateSpanningTrees() {
    vector<vector<Edge>> spanningTrees;
    vector<Edge> allEdges;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            allEdges.push_back(Edge(i, j));
        }
    }

    int n = allEdges.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) == 3) {
            vector<Edge> subset;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subset.push_back(allEdges[i]);
                }
            }
            if (isTree(subset, 4)) {
                spanningTrees.push_back(subset);
            }
        }
    }
    
    return spanningTrees;
}

bool areIsomorphic(vector<Edge>& tree1, vector<Edge>& tree2) {
    vector<int> deg1(4, 0), deg2(4, 0);
    for (auto& e : tree1) {
        deg1[e.u]++;
        deg1[e.v]++;
    }
    for (auto& e : tree2) {
        deg2[e.u]++;
        deg2[e.v]++;
    }
    
    sort(deg1.begin(), deg1.end());
    sort(deg2.begin(), deg2.end());
    
    return deg1 == deg2;
}

int main() {
    cout << "P 10.2.22 - Phân tích cây khung của K4\n\n";
    
    auto trees = generateSpanningTrees();
    
    cout << "(a) Số cây khung không đẳng cấu của K4:\n";

    vector<vector<Edge>> representatives;
    for (auto& tree : trees) {
        bool found = false;
        for (auto& rep : representatives) {
            if (areIsomorphic(tree, rep)) {
                found = true;
                break;
            }
        }
        if (!found) {
            representatives.push_back(tree);
        }
    }
    
    cout << "K4 có " << representatives.size() << " cây khung không đẳng cấu:\n\n";

    for (int i = 0; i < representatives.size(); i++) {
        cout << "Cây " << i + 1 << ":\n";
        vector<int> degrees(4, 0);
        for (auto& e : representatives[i]) {
            cout << "  Cạnh (" << e.u << ", " << e.v << ")\n";
            degrees[e.u]++;
            degrees[e.v]++;
        }
        cout << "  Dãy bậc: ";
        sort(degrees.begin(), degrees.end(), greater<int>());
        for (int d : degrees) cout << d << " ";
        cout << "\n\n";
    }
    
    cout << "(b) Số cây khung có gán nhãn của K4:\n";
    cout << "Theo công thức Cayley: n^(n-2) = 4^2 = 16\n";
    cout << "Hoặc đếm trực tiếp: " << trees.size() << " cây khung\n";
    
    return 0;
}