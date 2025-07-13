#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long dp[MAXN];
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[i] = (1LL * (i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
    }

    cout << dp[n] << endl;
    return 0;
}
