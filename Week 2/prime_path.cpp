#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

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
                if (i == 0 && d == '0') continue;
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
            for (int next : getNeighbors(current)) {
                if (next == end) return dist + 1;
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, dist + 1});
                }
            }
        }
        return -1;
    }
};

int main() {
    PrimePath primePath;
    cout << "1033 -> 8179: " << primePath.findShortestPath(1033, 8179) << endl;
    cout << "1373 -> 8017: " << primePath.findShortestPath(1373, 8017) << endl;
    cout << "1033 -> 1033: " << primePath.findShortestPath(1033, 1033) << endl;
    return 0;
}