#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

// P 10.2.13: So cycle sau khi them 1 canh vao cay
int cyclesAfterAddingEdge() {
    // Cay ban dau khong co cycle
    // Them 1 canh tao dung 1 cycle
    return 1;
}

// P 10.2.14: So cycle cua do thi lien thong n dinh n canh
int cyclesInConnectedGraph(int n, int m) {
    // So cycle = m - n + 1 (cong thuc Euler)
    return m - n + 1;
}

// P 10.2.15: Kiem tra do thi n dinh >= n canh co cycle
bool mustHaveCycle(int n, int m) {
    return m >= n;
}

// P 10.2.17: Kiem tra day la day bac cua cay
bool isTreeDegreeSequence(vector<int> degrees) {
    int n = degrees.size();
    int sum = 0;
    for (int d : degrees) {
        if (d < 1) return false;
        sum += d;
    }
    return sum == 2 * n - 2;
}

// P 10.2.18: So cay khung cua mot cay
int spanningTreesOfTree() {
    return 1;
}

// P 10.2.19: So canh cua cac cay khung
bool spanningTreesSameEdges(int n) {
    // Moi cay khung cua do thi n dinh deu co n-1 canh
    return true;
}

// P 10.2.22: So cay khung cua K4
long long spanningTreesK4() {
    // Cong thuc Cayley: n^(n-2)
    return pow(4, 2);
}

// P 10.2.22a: So cay khung khong dang cau cua K4
int nonIsomorphicSpanningTreesK4() {
    // Cay 4 dinh: path va star
    return 2;
}

// Ham phu: Tim cay khung bang BFS
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

// Ham phu: Tim cay khung bang DFS
void dfsSpanningTree(int u, vector<vector<int>>& adj, vector<bool>& visited, 
                     vector<pair<int,int>>& tree) {
    visited[u] = true;
    
    for (int v = 0; v < adj.size(); v++) {
        if (adj[u][v] && !visited[v]) {
            tree.push_back({u, v});
            dfsSpanningTree(v, adj, visited, tree);
        }
    }
}

// Bai toan phan hoach: Tinh p_k(n)
long long partitionK(int n, int k) {
    if (k > n || k == 0) return 0;
    if (k == 1 || k == n) return 1;
    
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
    
    for (int i = 0; i <= n; i++) {
        dp[i][1] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            if (i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
            }
        }
    }
    
    return dp[n][k];
}

// Ham sinh: Tinh he so cua x^n
long long coefficientOfXn(int n, int k) {
    // He so cua x^n trong (1 + x + x^2 + ... + x^k)^m
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j >= 1; j--) {
            dp[i] += dp[i-j];
        }
    }
    
    return dp[n];
}

// Ham sinh cho bai toan chia keo
long long candyDistribution(int total, int oddMin, int evenMax, int camMin, int camMax, int daoMin, int daoMax) {
    vector<long long> dp(total+1, 0);
    dp[0] = 1;
    
    // Tab (so le)
    for (int i = 1; i <= total; i += 2) {
        for (int j = total; j >= i; j--) {
            dp[j] += dp[j-i];
        }
    }
    
    // Chan (so chan)
    vector<long long> temp(total+1, 0);
    for (int i = 0; i <= total; i++) {
        for (int j = 0; j <= total - i; j += 2) {
            temp[i+j] += dp[i];
        }
    }
    dp = temp;
    
    // Cam
    temp.assign(total+1, 0);
    for (int i = 0; i <= total; i++) {
        for (int j = camMin; j <= camMax && i+j <= total; j++) {
            temp[i+j] += dp[i];
        }
    }
    dp = temp;
    
    // Dao
    temp.assign(total+1, 0);
    for (int i = 0; i <= total; i++) {
        for (int j = daoMin; j <= daoMax && i+j <= total; j++) {
            temp[i+j] += dp[i];
        }
    }
    
    return temp[total];
}

// USD Problem: Tinh tong day
long long sumSequence(int n, int k) {
    // Sum from s=0 to n of a_s where a_s = C(s+k-1, k-1)
    long long sum = 0;
    
    for (int s = 0; s <= n; s++) {
        // Tinh C(s+k-1, k-1)
        long long c = 1;
        for (int i = 0; i < k-1; i++) {
            c = c * (s + k - 1 - i) / (i + 1);
        }
        sum += c;
    }
    
    return sum;
}

// Main function de test
int main() {
    // Test P 10.2.7
    cout << "P 10.2.7: Graph 5 dinh 4 canh\n";
    vector<vector<int>> adj(5, vector<int>(5, 0));
    // Tao cay
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;
    cout << "La cay: " << (isTree(adj, 5, 4) ? "Co" : "Khong") << "\n\n";
    
    // Test P 10.2.8
    cout << "P 10.2.8: Forest 20 dinh 3 cay\n";
    cout << "So canh: " << forestEdges(20, 3) << "\n\n";
    
    // Test P 10.2.10
    cout << "P 10.2.10: So la toi thieu khi co dinh bac 4\n";
    cout << "So la: " << minLeavesWithDegree4(10) << "\n\n";
    
    // Test P 10.2.11
    cout << "P 10.2.11: Day bac 3,3,3,2,1\n";
    vector<int> degrees = {3, 3, 3, 2, 1};
    cout << "Co cycle: " << (hasCycleFromDegreeSequence(degrees) ? "Co" : "Khong") << "\n\n";
    
    // Test P 10.2.17
    cout << "P 10.2.17: Kiem tra day bac cua cay\n";
    vector<int> treeDegrees = {3, 2, 1, 1, 1};
    cout << "La day bac cua cay: " << (isTreeDegreeSequence(treeDegrees) ? "Co" : "Khong") << "\n\n";
    
    // Test P 10.2.22
    cout << "P 10.2.22: Cay khung cua K4\n";
    cout << "So cay khung: " << spanningTreesK4() << "\n";
    cout << "So cay khung khong dang cau: " << nonIsomorphicSpanningTreesK4() << "\n\n";
    
    // Test phan hoach
    cout << "Phan hoach p_5(3) = " << partitionK(5, 3) << "\n\n";
    
    return 0;
}

// P 10.2.7: Kiem tra graph 5 dinh 4 canh co phai tree khong
bool isTree(vector<vector<int>>& adj, int n, int m) {
    if (m != n - 1) return false;
    
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int count = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
                count++;
            }
        }
    }
    
    return count == n;
}

// P 10.2.8: Tinh so canh cua forest
int forestEdges(int n, int t) {
    return n - t;
}

// P 10.2.9: Dem so la cua cay
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

// P 10.2.10: So la toi thieu khi co dinh bac 4
int minLeavesWithDegree4(int n) {
    // Tong bac = 2(n-1)
    // 1 dinh bac 4, k dinh bac 1, (n-k-1) dinh bac >= 2
    // 4 + k + 2(n-k-1) <= 2(n-1)
    // 4 + k + 2n - 2k - 2 <= 2n - 2
    // 2 - k <= -2
    // k >= 4
    return 4;
}

// P 10.2.11: Kiem tra graph co cycle tu day bac
bool hasCycleFromDegreeSequence(vector<int> degrees) {
    int n = degrees.size();
    int sum = 0;
    for (int d : degrees) sum += d;
    int edges = sum / 2;
    
    // Neu so canh > n-1 thi co cycle
    return edges > n - 1;
}

// P 10.2.