#include <iostream>

using namespace std;

long long countNonConsecutiveSubsets(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;

    long long f1 = 2, f2 = 3;
    
    for (int i = 3; i <= n; i++) {
        long long fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    
    return (n == 1) ? f1 : f2;
}

void testProblem6() {
    cout << "=== Problem 6: Tap con khong chua 2 so lien tiep ===\n";
    cout << "Bai toan: Dem so tap con cua {1,2,...,n} khong chua 2 so lien tiep.\n\n";
    
    cout << "Cong thuc de quy: f(n) = f(n-1) + f(n-2)\n";
    cout << "Voi f(0) = 1 (tap rong), f(1) = 2 ({}, {1})\n\n";
    
    cout << "Giai thich:\n";
    cout << "- Xet phan tu n:\n";
    cout << "  + Neu n khong thuoc tap con: co f(n-1) cach\n";
    cout << "  + Neu n thuoc tap con: n-1 khong duoc thuoc, co f(n-2) cach\n";
    cout << "- Do do: f(n) = f(n-1) + f(n-2)\n\n";
    
    cout << "Vi du voi n=3:\n";
    cout << "Cac tap con thoa man: {}, {1}, {2}, {3}, {1,3}\n";
    cout << "Tong cong: 5 tap con\n\n";
    
    cout << "Bang gia tri:\n";
    cout << "n\tf(n)\tGhi chu\n";
    cout << "---\t----\t--------\n";
    for (int n = 0; n <= 15; n++) {
        cout << n << "\t" << countNonConsecutiveSubsets(n);
        if (n >= 2) {
            cout << "\t= f(" << n-1 << ") + f(" << n-2 << ")";
        }
        cout << "\n";
    }
    
    cout << "\nNhan xet: Day so nay la day Fibonacci lech 1 don vi!\n";
    cout << "f(n) = Fibonacci(n+2)\n";
}

int main() {
    testProblem6();
    
    cout << "\nNhap n: ";
    int n;
    cin >> n;
    
    cout << "So tap con cua {1,2,...," << n 
         << "} khong chua 2 so lien tiep: " 
         << countNonConsecutiveSubsets(n) << "\n";

    if (n <= 4) {
        cout << "\nVi du cac tap con thoa man:\n";
        cout << "- Tap rong: {}\n";
        for (int i = 1; i <= n; i++) {
            cout << "- Tap don: {" << i << "}\n";
        }
        if (n >= 3) {
            cout << "- Cac tap khac: ";
            for (int i = 1; i <= n-2; i++) {
                for (int j = i+2; j <= n; j++) {
                    cout << "{" << i << "," << j << "} ";
                }
            }
            cout << "\n";
        }
    }
    
    return 0;
}