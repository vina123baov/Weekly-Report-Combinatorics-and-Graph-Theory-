#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

// P 10.2.17
bool isTreeDegreeSequence(vector<int> degrees) {
    int n = degrees.size();
    int sum = 0;
    for (int d : degrees) {
        if (d < 1) return false;
        sum += d;
    }
    return sum == 2 * n - 2;
}

int main() {
    vector<int> treeDegrees = {3, 2, 1, 1, 1};
    cout << "P 10.2.17: Is degree sequence of a tree: " << (isTreeDegreeSequence(treeDegrees) ? "Yes" : "No") << endl;
    return 0;
}