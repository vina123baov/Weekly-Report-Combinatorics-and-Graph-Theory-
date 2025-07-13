#include <iostream>
#include <iomanip>
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

long long derangement(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;

    long long d0 = 1, d1 = 0;
    long long dn;
    
    for (int i = 2; i <= n; i++) {
        dn = (i - 1) * (d1 + d0);
        d0 = d1;
        d1 = dn;
    }
    
    return dn;
}

double derangementExact(int n) {
    double result = factorial(n);
    double sum = 0;
    
    for (int i = 0; i <= n; i++) {
        sum += pow(-1, i) / factorial(i);
    }
    
    return result * sum;
}

void testProblem5() {
    cout << "=== Problem 5: DERANGEMENT ===\n";
    cout << "Bai toan: Dem so hoan vi cua n phan tu ma khong co phan tu nao\n";
    cout << "         o dung vi tri ban dau (khong co diem co dinh).\n\n";
    
    cout << "Cong thuc:\n";
    cout << "1. De quy: D_n = (n-1) * (D_{n-1} + D_{n-2})\n";
    cout << "2. Cong thuc: D_n = n! * Σ((-1)^i / i!) voi i tu 0 den n\n";
    cout << "3. Xap xi: D_n ≈ n!/e khi n lon\n\n";
    
    cout << "Vi du:\n";
    cout << "- n=3 (1,2,3): Co 2 derangement: (2,3,1) va (3,1,2)\n";
    cout << "- n=4: Co 9 derangement\n\n";
    
    cout << fixed << setprecision(2);
    cout << "Bang gia tri:\n";
    cout << "n\tD_n\tD_n (exact)\tn!/e\n";
    cout << "---\t-----\t-----------\t------\n";
    
    for (int n = 0; n <= 10; n++) {
        double exact = derangementExact(n);
        double approx = factorial(n) / exp(1.0);
        cout << n << "\t" << derangement(n) << "\t" 
             << exact << "\t\t" << approx << "\n";
    }
    
    cout << "\nNhan xet: Khi n lon, D_n xap xi bang n!/e\n";
}

int main() {
    testProblem5();
    
    cout << "\nNhap n: ";
    int n;
    cin >> n;
    
    cout << "So derangement cua " << n << " phan tu: " 
         << derangement(n) << "\n";
    
    cout << "Ty le derangement/hoan vi: " 
         << fixed << setprecision(4)
         << (double)derangement(n) / factorial(n) << " ≈ 1/e = "
         << 1.0/exp(1.0) << "\n";
    
    return 0;
}