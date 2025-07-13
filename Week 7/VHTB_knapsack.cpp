#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Câu (a):
int knapsack_weight_1(vector<int>& values, int W) {
    sort(values.rbegin(), values.rend());
    int total_value = 0;
    int items_taken = min(W, (int)values.size());
    
    for (int i = 0; i < items_taken; i++) {
        total_value += values[i];
    }
    
    return total_value;
}

// Câu (b):
int knapsack_equal_weight(vector<int>& values, int W, int w) {
    if (w > W) return 0;
    
    sort(values.rbegin(), values.rend());
    int total_value = 0;
    int max_items = W / w;
    int items_taken = min(max_items, (int)values.size());
    
    for (int i = 0; i < items_taken; i++) {
        total_value += values[i];
    }
    
    return total_value;
}

// Câu (c):
int knapsack_01_dp(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            }
        }
    }
    
    return dp[n][W];
}

void print_selected_items(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            }
        }
    }
    
    cout << "Cac item duoc chon: ";
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << "Item " << i-1 << " (weight=" << weights[i-1] 
                 << ", value=" << values[i-1] << ") ";
            w -= weights[i-1];
        }
    }
    cout << endl;
}

// Câu (d):
void analyze_complexity() {
    cout << "\n=== PHAN TICH DO PHUC TAP THOI GIAN ===" << endl;
    cout << "Cau (a) - Weight = 1: O(n log n) do sort" << endl;
    cout << "Cau (b) - Weight = w: O(n log n) do sort" << endl;
    cout << "Cau (c) - DP 0-1: O(n * W)" << endl;
    cout << "Space complexity cua DP: O(n * W)" << endl;
    cout << "Co the toi uu space xuong O(W) bang 1D array" << endl;
}

int knapsack_01_optimized(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<int> dp(W + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    
    return dp[W];
}

int main() {
    cout << "=== BAI TOAN KNAPSACK ===" << endl;
    
    int W = 6;
    vector<int> test_values = {4, 5, 6, 7, 2, 3, 8, 1, 9, 10};
    vector<int> test_weights = {2, 3, 1, 4, 2, 1, 3, 2, 2, 1};
    
    cout << "\nTest case: W = " << W << endl;
    cout << "Values: ";
    for (int v : test_values) cout << v << " ";
    cout << "\nWeights: ";
    for (int w : test_weights) cout << w << " ";
    cout << endl;
    
    // Câu (a):
    cout << "\n--- CAU (a): Weight = 1 cho tat ca items ---" << endl;
    vector<int> values_copy = test_values;
    int result_a = knapsack_weight_1(values_copy, W);
    cout << "Ket qua: " << result_a << endl;
    
    // Câu (b):
    cout << "\n--- CAU (b): Weight = 2 cho tat ca items ---" << endl;
    values_copy = test_values;
    int w = 2;
    int result_b = knapsack_equal_weight(values_copy, W, w);
    cout << "Ket qua voi weight = " << w << ": " << result_b << endl;
    
    // Câu (c):
    cout << "\n--- CAU (c): Knapsack 0-1 DP ---" << endl;
    int result_c = knapsack_01_dp(test_weights, test_values, W);
    cout << "Ket qua: " << result_c << endl;
    print_selected_items(test_weights, test_values, W);
    
    // So sánh
    int result_optimized = knapsack_01_optimized(test_weights, test_values, W);
    cout << "Ket qua (space optimized): " << result_optimized << endl;
    
    // Câu (d):
    analyze_complexity();
    
    cout << "\n=== TEST CASE KHAC ===" << endl;
    vector<int> weights2 = {1, 3, 4, 5};
    vector<int> values2 = {1, 4, 5, 7};
    int W2 = 7;
    
    cout << "W = " << W2 << endl;
    cout << "Weights: ";
    for (int w : weights2) cout << w << " ";
    cout << "\nValues: ";
    for (int v : values2) cout << v << " ";
    cout << endl;
    
    int result2 = knapsack_01_dp(weights2, values2, W2);
    cout << "Ket qua: " << result2 << endl;
    print_selected_items(weights2, values2, W2);
    
    return 0;
}