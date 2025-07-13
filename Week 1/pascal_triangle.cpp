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

void printPascalTriangle(int n) {
    cout << "Tam giac Pascal voi " << n+1 << " dong:\n";
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }

        for (int j = 0; j <= i; j++) {
            cout << combination(i, j) << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "=== PASCAL TRIANGLE ===\n";
    printPascalTriangle(6);
    
    cout << "\nNhap so dong muon in (n): ";
    int n;
    cin >> n;
    printPascalTriangle(n-1);
    
    return 0;
}