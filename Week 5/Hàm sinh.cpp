#include <iostream>

using namespace std;

// Tính hệ số C(n,k) - tổ hợp
long long toHop(int n, int k) {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k;
    
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

long long heSoCauA(int n, int r) {
    return toHop(r + n - 1, r);
}

long long heSoCauB(int n, int m, int k) {
    if (k % m != 0) return 0;
    int j = k / m;
    if (j > n) return 0;
    long long heSo = toHop(n, j);
    if (j % 2 == 1) heSo = -heSo;
    return heSo;
}

int main() {
    cout << "=== GENERATING FUNCTION ===" << endl;
    cout << "Coefficient of x^5 in (1 + x + x^2 + ...)^3:" << endl;
    cout << "a_5 = C(5+3-1, 5) = C(7,5) = " << heSoCauA(3, 5) << endl;

    cout << "\nCoefficients in (1 - x^2)^4:" << endl;
    for (int k = 0; k <= 8; k += 2) {
        cout << "Coefficient of x^" << k << " = " << heSoCauB(4, 2, k) << endl;
    }

    return 0;
}