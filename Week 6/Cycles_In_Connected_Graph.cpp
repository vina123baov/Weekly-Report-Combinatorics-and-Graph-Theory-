#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

// P 10.2.14
int cyclesInConnectedGraph(int n, int m) {
    return m - n + 1;
}

int main() {
    cout << "P 10.2.14: Number of cycles in a connected graph with n vertices and m edges: " << cyclesInConnectedGraph(5, 5) << endl;
    return 0;
}