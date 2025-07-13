#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

// P 10.2.9
int countLeaves(vector<vector<int>>& adj, int n) {
    int leaves = 0;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) degree++;
        }
        if (degree == 1) leaves++;
    }
    return leaves;
}

int main() {
    vector<vector<int>> adj(5, vector<int>(5, 0));
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;
    cout << "P 10.2.9: Number of leaves in a tree with 5 vertices: " << countLeaves(adj, 5) << endl;
    return 0;
}