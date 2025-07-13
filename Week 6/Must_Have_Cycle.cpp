#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

// P 10.2.15
bool mustHaveCycle(int n, int m) {
    return m >= n;
}

int main() {
    cout << "P 10.2.15: Must have cycle for graph with 5 vertices and 5 edges: " << (mustHaveCycle(5, 5) ? "Yes" : "No") << endl;
    return 0;
}