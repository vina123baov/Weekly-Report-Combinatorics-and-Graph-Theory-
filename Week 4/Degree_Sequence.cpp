#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isTreeDegreeSequence(vector<int>& degrees) {
    int n = degrees.size();

    int sum = 0;
    for (int d : degrees) {
        if (d <= 0) return false;
        sum += d;
    }
    
    if (sum != 2 * (n - 1)) return false;

    vector<int> deg = degrees;
    sort(deg.begin(), deg.end(), greater<int>());

    for (int i = 0; i < n - 1; i++) {
        sort(deg.begin() + i, deg.end(), greater<int>());
        
        if (deg[i] <= 0) return false;
        if (i + deg[i] >= n) return false;

        for (int j = 1; j <= deg[i]; j++) {
            deg[i + j]--;
            if (deg[i + j] < 0) return false;
        }
        deg[i] = 0;
    }

    return deg[n - 1] == 0;
}

void constructTree(vector<int>& degrees) {
    int n = degrees.size();
    vector<pair<int, int>> nodes;
    
    for (int i = 0; i < n; i++) {
        nodes.push_back({degrees[i], i});
    }
    
    cout << "\nXây dựng cây từ dãy bậc:\n";
    vector<pair<int, int>> edges;
    
    while (nodes.size() > 1) {
        sort(nodes.begin(), nodes.end(), greater<pair<int, int>>());

        auto v = nodes[0];
        nodes.erase(nodes.begin());

        for (int i = 0; i < v.first && i < nodes.size(); i++) {
            edges.push_back({v.second, nodes[i].second});
            nodes[i].first--;
        }

        nodes.erase(
            remove_if(nodes.begin(), nodes.end(), 
                     [](const pair<int, int>& p) { return p.first == 0; }),
            nodes.end()
        );
    }
    
    cout << "Các cạnh của cây:\n";
    for (auto& e : edges) {
        cout << "(" << e.first << ", " << e.second << ") ";
    }
    cout << "\n";
}

int main() {
    cout << "Kiểm tra dãy bậc của cây (Bài P 10.2.17)\n\n";

    vector<vector<int>> testCases = {
        {3, 2, 2, 1, 1, 1},
        {4, 3, 2, 1, 1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 1, 1},
        {1, 1},
        {5, 4, 2, 1, 1, 1, 1, 1, 1, 1}
    };
    
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test " << i + 1 << ": ";
        for (int d : testCases[i]) cout << d << " ";
        cout << "\n";
        
        int sum = 0;
        for (int d : testCases[i]) sum += d;
        cout << "n = " << testCases[i].size() << ", tổng bậc = " << sum;
        cout << ", 2(n-1) = " << 2 * (testCases[i].size() - 1) << "\n";
        
        if (isTreeDegreeSequence(testCases[i])) {
            cout << "=> LÀ dãy bậc của một cây\n";
            constructTree(testCases[i]);
        } else {
            cout << "=> KHÔNG PHẢI dãy bậc của cây\n";
        }
        cout << "\n" << string(50, '-') << "\n\n";
    }
    
    return 0;
}