#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

// ==================== Bài toán 35: Graphical Sequence ====================

// Kiểm tra tổng bậc chẵn (Định lý Euler)
bool checkEulerTheorem(vector<int>& degrees) {
    int sum = 0;
    for (int d : degrees) {
        sum += d;
    }
    return sum % 2 == 0;
}

// Thuật toán Havel-Hakimi
bool havelHakimi(vector<int> degrees) {
    while (!degrees.empty()) {
        // Sắp xếp giảm dần
        sort(degrees.begin(), degrees.end(), greater<int>());
        
        // Loại bỏ các phần tử 0
        while (!degrees.empty() && degrees.back() == 0) {
            degrees.pop_back();
        }
        
        // Nếu dãy rỗng, là graphic
        if (degrees.empty()) {
            return true;
        }
        
        int k = degrees[0];
        
        // Kiểm tra điều kiện
        if (k > degrees.size() - 1) {
            return false;
        }
        
        // Xóa phần tử đầu
        degrees.erase(degrees.begin());
        
        // Giảm k phần tử tiếp theo
        for (int i = 0; i < k; i++) {
            degrees[i]--;
            if (degrees[i] < 0) {
                return false;
            }
        }
    }
    
    return true;
}

// Hàm kiểm tra graphical sequence
bool isGraphicalSequence(vector<int> degrees) {
    // Kiểm tra định lý Euler
    if (!checkEulerTheorem(degrees)) {
        return false;
    }
    
    // Kiểm tra bậc max
    int n = degrees.size();
    for (int d : degrees) {
        if (d >= n) {
            return false;
        }
    }
    
    // Áp dụng Havel-Hakimi
    return havelHakimi(degrees);
}

// ==================== Bài toán Euler Candy ====================

// (a) Đếm nghiệm nguyên dương
long long countPositiveSolutions(int m, int n) {
    if (m < n) return 0;
    
    // C(m-1, n-1)
    long long result = 1;
    for (int i = 0; i < n - 1; i++) {
        result = result * (m - 1 - i) / (i + 1);
    }
    return result;
}

// (b) Đếm nghiệm nguyên không âm
long long countNonNegativeSolutions(int m, int n) {
    // C(m+n-1, n-1)
    long long result = 1;
    for (int i = 0; i < n - 1; i++) {
        result = result * (m + n - 1 - i) / (i + 1);
    }
    return result;
}

// ==================== House of Santa Claus ====================

class SantaHouse {
private:
    vector<vector<int>> adj;
    vector<pair<int,int>> edges;
    vector<bool> usedEdge;
    vector<string> allPaths;
    
    void dfs(int u, string path) {
        if (path.length() == 9) { // 8 cạnh + điểm đầu
            if (u == 2) { // Kết thúc ở đỉnh bậc lẻ khác
                allPaths.push_back(path);
            }
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
        // Khởi tạo đồ thị ngôi nhà
        adj.resize(6); // Đỉnh 1-5
        
        // Thêm các cạnh
        edges = {{1,2}, {1,3}, {1,5}, {2,3}, {2,4}, {3,4}, {3,5}, {4,5}};
        
        for (auto& e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        
        usedEdge.resize(edges.size(), false);
    }
    
    void findAllEulerPaths() {
        // Bắt đầu từ đỉnh 1 (bậc lẻ)
        dfs(1, "1");
        
        // In kết quả
        sort(allPaths.begin(), allPaths.end());
        for (const string& path : allPaths) {
            cout << path << endl;
        }
    }
};

// ==================== Prime Path ====================

class PrimePath {
private:
    vector<bool> isPrime;
    
    void sievePrimes() {
        isPrime.assign(10000, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i < 10000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < 10000; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    
    vector<int> getNeighbors(int num) {
        vector<int> neighbors;
        string s = to_string(num);
        
        for (int i = 0; i < 4; i++) {
            for (char d = '0'; d <= '9'; d++) {
                if (i == 0 && d == '0') continue; // Không cho phép số 0 ở đầu
                
                string temp = s;
                temp[i] = d;
                int newNum = stoi(temp);
                
                if (newNum != num && isPrime[newNum]) {
                    neighbors.push_back(newNum);
                }
            }
        }
        
        return neighbors;
    }
    
public:
    PrimePath() {
        sievePrimes();
    }
    
    int findShortestPath(int start, int end) {
        if (start == end) return 0;
        
        queue<pair<int, int>> q;
        set<int> visited;
        
        q.push({start, 0});
        visited.insert(start);
        
        while (!q.empty()) {
            int current = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            vector<int> neighbors = getNeighbors(current);
            
            for (int next : neighbors) {
                if (next == end) {
                    return dist + 1;
                }
                
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push({next, dist + 1});
                }
            }
        }
        
        return -1; // Không tìm thấy đường đi
    }
};

// ==================== Main function ====================

int main() {
    // Test Graphical Sequence
    cout << "=== Graphical Sequence Test ===" << endl;
    
    // Đọc input từ file
    ifstream input("graphical_sequence.inp");
    ofstream output("graphical_sequence.out");
    
    int t;
    input >> t;
    
    while (t--) {
        int n;
        input >> n;
        vector<int> degrees(n);
        
        for (int i = 0; i < n; i++) {
            input >> degrees[i];
        }
        
        if (isGraphicalSequence(degrees)) {
            output << "1" << endl;
        } else {
            output << "0" << endl;
        }
    }
    
    input.close();
    output.close();
    
    // Test Euler Candy Problem
    cout << "\n=== Euler Candy Problem ===" << endl;
    cout << "Nghiệm dương của x1 + x2 + x3 = 10: " 
         << countPositiveSolutions(10, 3) << endl;
    cout << "Nghiệm không âm của x1 + x2 + x3 = 10: " 
         << countNonNegativeSolutions(10, 3) << endl;
    
    // Test House of Santa Claus
    cout << "\n=== House of Santa Claus ===" << endl;
    SantaHouse house;
    house.findAllEulerPaths();
    
    // Test Prime Path
    cout << "\n=== Prime Path ===" << endl;
    PrimePath primePath;
    
    // Test cases từ đề bài
    cout << "1033 -> 8179: " << primePath.findShortestPath(1033, 8179) << endl;
    cout << "1373 -> 8017: " << primePath.findShortestPath(1373, 8017) << endl;
    cout << "1033 -> 1033: " << primePath.findShortestPath(1033, 1033) << endl;
    
    return 0;
}

// ==================== Giải thích các thuật toán ====================

/*
1. Graphical Sequence:
   - Kiểm tra định lý Euler: tổng bậc phải chẵn
   - Thuật toán Havel-Hakimi: loại bỏ đỉnh bậc cao nhất và giảm bậc các đỉnh kề
   - Độ phức tạp: O(n²) trong trường hợp xấu nhất

2. Euler Candy Problem:
   - Sử dụng công thức tổ hợp "stars and bars"
   - Chuyển đổi điều kiện bằng cách đặt biến phụ
   - Áp dụng nguyên lý bao hàm - loại trừ cho điều kiện phức tạp

3. House of Santa Claus:
   - Tìm đường Euler trong đồ thị
   - Sử dụng DFS với backtracking
   - Kiểm tra đỉnh bậc lẻ để xác định điểm đầu và cuối

4. Prime Path:
   - BFS để tìm đường đi ngắn nhất
   - Sàng Eratosthenes để tìm số nguyên tố
   - Mỗi đỉnh có tối đa 36 hàng xóm (4 vị trí × 9 chữ số)
*/