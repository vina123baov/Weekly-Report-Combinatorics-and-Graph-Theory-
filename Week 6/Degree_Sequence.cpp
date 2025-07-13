#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

// P 10.2.11:
bool hasCycleFromDegreeSequence(vector<int> degrees) {
    int n = degrees.size();
    int sum = 0;
    for (int d : degrees) sum += d;
    int edges = sum / 2;

    return edges > n - 1;
}

int main() {
    vector<int> degrees = {3, 3, 3, 2, 1};
    cout << "P 10.2.11: Has cycle from degree sequence {3,3,3,2,1}: " << (hasCycleFromDegreeSequence(degrees) ? "Yes" : "No") << endl;
    return 0;
}