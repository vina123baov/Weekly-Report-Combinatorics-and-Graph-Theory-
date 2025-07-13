#include <iostream>
#include <limits>

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

int findFactorialOverflow() {
    long long max_val = numeric_limits<long long>::max();
    long long fact = 1;
    
    cout << "Kiem tra factorial overflow:\n";
    cout << "Gia tri max cua long long: " << max_val << "\n\n";
    
    for (int n = 1; n <= 100; n++) {
        if (fact > max_val / n) {
            cout << (n-1) << "! = " << fact << " (OK)\n";
            cout << n << "! se overflow (> " << max_val << ")\n";
            return n;
        }
        fact *= n;

        if (n >= 15 && n <= 20) {
            cout << n << "! = " << fact << "\n";
        }
    }
    return -1;
}

int findCatalanOverflow() {
    long long max_val = numeric_limits<long long>::max();
    
    cout << "\n\nKiem tra Catalan overflow:\n";
    cout << "Gia tri max cua long long: " << max_val << "\n\n";
    
    for (int n = 1; n <= 100; n++) {
        long long c = 1;
        bool overflow = false;

        for (int i = 1; i <= n; i++) {
            if (c > max_val / (n + i)) {
                overflow = true;
                break;
            }
            c = c * (n + i) / i;
        }
        
        if (overflow) {
            cout << "Catalan(" << (n-1) << ") = " 
                 << combination(2*(n-1), n-1)/(n) << " (OK)\n";
            cout << "Catalan(" << n << ") se overflow\n";
            return n;
        }

        if (n <= 10 || n == 15 || n == 20 || n == 25 || n == 30) {
            cout << "Catalan(" << n << ") = " << c/(n+1) << "\n";
        }
    }
    return -1;
}

int main() {
    cout << "=== KIEM TRA OVERFLOW ===\n";
    cout << "Kiem tra diem overflow cho cac ham tinh toan\n";
    cout << "Su dung kieu du lieu: long long\n";
    cout << "Kich thuoc: " << sizeof(long long) << " bytes\n\n";
    
    int factOverflow = findFactorialOverflow();
    int catalanOverflow = findCatalanOverflow();
    
    cout << "\n=== KET QUA ===\n";
    cout << "Factorial overflow tai n = " << factOverflow << "\n";
    cout << "Catalan overflow tai n = " << catalanOverflow << "\n";
    
    cout << "\nGhi chu:\n";
    cout << "- Voi n >= " << factOverflow << ", can su dung BigInteger hoac thu vien so lon\n";
    cout << "- Hoac su dung modulo arithmetic neu chi can ket qua modulo\n";
    
    return 0;
}