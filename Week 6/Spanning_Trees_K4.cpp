#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

// P 10.2.22:
long long spanningTreesK4() {
    return pow(4, 2);
}

// P 10.2.22a
int nonIsomorphicSpanningTreesK4() {
    return 2;
}

int main() {
    cout << "P 10.2.22: Number of spanning trees of K4: " << spanningTreesK4() << endl;
    cout << "P 10.2.22a: Number of non-isomorphic spanning trees of K4: " << nonIsomorphicSpanningTreesK4() << endl;
    return 0;
}