#include <iostream>
#include <cmath>

using namespace std;

long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long permutation(int n, int k) {
    if (k > n) return 0;
    long long result = 1;
    for (int i = n; i > n - k; i--) {
        result *= i;
    }
    return result;
}

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

// Tính số Catalan
long long catalan(int n) {
    if (n <= 1) return 1;

    long long c = combination(2*n, n);
    return c / (n + 1);
}

int main() {
    cout << "=== TEST CAC HAM CO BAN ===\n";
    cout << "5! = " << factorial(5) << "\n";
    cout << "A(5,3) = " << permutation(5, 3) << "\n";
    cout << "C(5,3) = " << combination(5, 3) << "\n";
    cout << "Catalan(5) = " << catalan(5) << "\n";
    
    return 0;
}