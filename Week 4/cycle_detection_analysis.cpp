#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    
public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool hasCycleDFS(int v, int parent, vector<bool>& visited) {
        visited[v] = true;
        
        for (int u : adj[v]) {
            if (!visited[u]) {
                if (hasCycleDFS(u, v, visited))
                    return true;
            }
            else if (u != parent) {
                return true;
            }
        }
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (hasCycleDFS(i, -1, visited))
                    return true;
            }
        }
        return false;
    }

    int countComponents() {
        vector<bool> visited(V, false);
        int count = 0;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    
                    for (int u : adj[v]) {
                        if (!visited[u]) {
                            visited[u] = true;
                            q.push(u);
                        }
                    }
                }
            }
        }
        return count;
    }

    int cyclomaticNumber() {
        int E = 0;
        for (int i = 0; i < V; i++) {
            E += adj[i].size();
        }
        E /= 2;
        
        int C = countComponents();
        return E - V + C;
    }
};

void demonstrateWalkTrailCycle() {
    cout << "=== WALK, TRAIL, CYCLE ===\n\n";
    
    cout << "Bài P 10.2.21:\n";
    cout << "(a) Closed walk chứa x,y => Tồn tại closed trail chứa x,y? CÓ\n";
    cout << "    Giải thích: Loại bỏ các cạnh lặp từ walk.\n\n";
    
    cout << "(b) Closed trail chứa x,y => Tồn tại cycle chứa x,y? KHÔNG\n";
    cout << "    Phản ví dụ: Hai chu trình rời nhau chia sẻ 1 đỉnh.\n\n";
    
    cout << "Bài P 10.2.22: Circuit chứa x => Cycle chứa x? CÓ\n";
    cout << "    Giải thích: Circuit không lặp cạnh. Nếu lặp đỉnh,\n";
    cout << "    phần giữa 2 lần xuất hiện tạo thành cycle.\n\n";
}

int main() {
    cout << "=== PHÂN TÍCH CHU TRÌNH TRONG ĐỒ THỊ ===\n\n";
    
    // Bài P 10.2.13
    cout << "Bài P 10.2.13: Cây 20 đỉnh + cạnh {v4, v18}\n";
    Graph g1(20);
    for (int i = 0; i < 19; i++) {
        g1.addEdge(i, i+1);
    }
    cout << "Cây ban đầu có chu trình: " << (g1.hasCycle() ? "CÓ" : "KHÔNG") << "\n";

    g1.addEdge(3, 17);
    cout << "Sau khi thêm cạnh {v4, v18}: " << (g1.hasCycle() ? "CÓ" : "KHÔNG") << "\n";
    cout << "Số chu trình cơ bản: " << g1.cyclomaticNumber() << "\n\n";
    
    // Bài P 10.2.14
    cout << "Bài P 10.2.14: Đồ thị liên thông 47 đỉnh, 47 cạnh\n";
    cout << "Cây cần: 46 cạnh\n";
    cout << "Thừa: 47 - 46 = 1 cạnh\n";
    cout << "=> Có ít nhất 1 chu trình\n\n";
    
    // Bài P 10.2.15
    cout << "Bài P 10.2.15: n đỉnh, ≥n cạnh => có chu trình\n";
    cout << "Chứng minh: Nếu k thành phần đều là cây:\n";
    cout << "  Số cạnh = n - k < n (mâu thuẫn)\n\n";

    demonstrateWalkTrailCycle();
    
    return 0;
}