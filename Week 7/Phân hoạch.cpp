#include <iostream>
#include <vector>
using namespace std;

// Hàm tính p_k(n)
long long partition_k(int n, int k) {
    if (k > n) return 0;
    if (k == 1 || k == n) return 1;
    
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
    
    for (int i = 0; i <= n; i++) {
        dp[i][1] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            if (i == j) {
                dp[i][j] = 1;
            } else if (j > i) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-j][j] + dp[i-1][j-1];
            }
        }
    }
    
    return dp[n][k];
}

//kiểm tra điều kiện p_k(n) < n!/k!
bool check_condition(int n, int k) {
    long long pk = partition_k(n, k);
    
    // Tính n!/k!
    long long factorial_ratio = 1;
    for (int i = n; i > k; i--) {
        factorial_ratio *= i;
    }
    
    return pk < factorial_ratio;
}

int main() {
    int n = 5;
    for (int k = 1; k <= n; k++) {
        cout << "p_" << k << "(" << n << ") = " << partition_k(n, k);
        if (check_condition(n, k)) {
            cout << " < " << n << "!/" << k << "!" << endl;
        } else {
            cout << " >= " << n << "!/" << k << "!" << endl;
        }
    }
    
    return 0;
}