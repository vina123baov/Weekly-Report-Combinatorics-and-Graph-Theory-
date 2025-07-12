#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int demNghiemVetCan(int n, const vector<int>& m_vals, const vector<int>& M_vals) {
    int m = m_vals.size();
    vector<int> x(m);
    int count = 0;

    std::function<void(int)> thuGiaTri = [&](int idx) {
        if (idx == m) {
            int sum = 0;
            for (int i = 0; i < m; i++) sum += x[i];
            if (sum == n) count++;
            return;
        }

        for (int val = m_vals[idx]; val <= M_vals[idx]; val++) {
            x[idx] = val;
            thuGiaTri(idx + 1);
        }
    };

    thuGiaTri(0);
    return count;
}

int demNghiemDP(int n, const vector<int>& m_vals, const vector<int>& M_vals) {
    int m = m_vals.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = m_vals[i-1]; k <= M_vals[i-1] && k <= j; k++) {
                dp[i][j] += dp[i-1][j-k];
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << "=== EULER FORMULA - COUNT SOLUTIONS ===" << endl;
    
    cout << "Example 1: x1 + x2 + x3 = 10" << endl;
    cout << "Constraints: 1 <= x1 <= 4, 2 <= x2 <= 5, 1 <= x3 <= 4" << endl;

    vector<int> m_vals = {1, 2, 1};
    vector<int> M_vals = {4, 5, 4};
    int n = 10;

    int soNghiem1 = demNghiemVetCan(n, m_vals, M_vals);
    int soNghiem2 = demNghiemDP(n, m_vals, M_vals);

    cout << "Number of solutions (brute force): " << soNghiem1 << endl;
    cout << "Number of solutions (dynamic programming): " << soNghiem2 << endl;

    cout << "\nExample 2: x1 + x2 + x3 + x4 = 20" << endl;
    cout << "Constraints: 2 <= xi <= 8 for all i" << endl;

    vector<int> m_vals2 = {2, 2, 2, 2};
    vector<int> M_vals2 = {8, 8, 8, 8};
    int n2 = 20;

    int soNghiem3 = demNghiemDP(n2, m_vals2, M_vals2);
    cout << "Number of solutions: " << soNghiem3 << endl;

    int tongMin = 0, tongMax = 0;
    for (int i = 0; i < m_vals2.size(); i++) {
        tongMin += m_vals2[i];
        tongMax += M_vals2[i];
    }
    cout << "Check: " << tongMin << " <= " << n2 << " <= " << tongMax;
    cout << " => " << (tongMin <= n2 && n2 <= tongMax ? "Feasible" : "Infeasible") << endl;

    return 0;
}