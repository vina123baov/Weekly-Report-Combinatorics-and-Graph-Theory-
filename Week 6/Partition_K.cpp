#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

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

int main() {
    cout << "P 10.2: Partition p_5(3) = " << partitionK(5, 3) << endl;
    return 0;
}