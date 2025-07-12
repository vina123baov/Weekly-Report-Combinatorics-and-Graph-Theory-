#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> adj = {
    {{2, 4}, {1, 2}},        // 0
    {{0, 2}, {2, 1}, {3, 7}},// 1
    {{0, 4}, {1, 1}, {4, 3}},// 2
    {{1, 7}, {4, 2}},        // 3
    {{2, 3}, {3, 2}}         // 4
};

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (pii neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int start = 0;
    vector<int> result = dijkstra(start, 5);

    cout << "Shortest distances from node " << start << ":" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "To node " << i << ": " << result[i] << endl;
    }
    return 0;
}