#include <iostream>

using namespace std;

long long combination(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    if (k > n - k) k = n - k;
    
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result = result * (n - i) / (i + 1);
    }
    return result;
}

void binomialExpansion(int n) {
    cout << "(a+b)^" << n << " = ";
    
    for (int k = 0; k <= n; k++) {
        long long coef = combination(n, k);
        
        if (k > 0) cout << " + ";
        
        cout << coef;

        if (n - k > 0) {
            cout << "*a";
            if (n - k > 1) cout << "^" << n - k;
        }

        if (k > 0) {
            cout << "*b";
            if (k > 1) cout << "^" << k;
        }
    }
    cout << "\n";
}

int main() {
    cout << "=== KHAI TRIEN NHI THUC ===\n";
    
    // Ví dụ
    cout << "Vi du:\n";
    for (int n = 0; n <= 5; n++) {
        binomialExpansion(n);
    }

    cout << "\nNhap bac cua nhi thuc (n): ";
    int n;
    cin >> n;
    binomialExpansion(n);
    
    return 0;
}