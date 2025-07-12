#include <iostream>
using namespace std;

// Tính tổ hợp C(n, k)
long long C(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (k > n) return 0;
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main() {
    int n;
    cout << "Nhập n: ";
    cin >> n;

    long long even_sum = 0, odd_sum = 0, alternating_sum = 0;
    for (int i = 0; i <= n; i++) {
        long long val = C(n, i);
        alternating_sum += ((i % 2 == 0) ? val : -val);
        if (i % 2 == 0) even_sum += val;
        else odd_sum += val;
    }

    cout << "Tổng luân phiên: " << alternating_sum << endl;
    cout << "Tổng chẵn = " << even_sum << ", Tổng lẻ = " << odd_sum << endl;

    if (alternating_sum == 0)
        cout << "=> Tổng các hệ số chẵn = Tổng các hệ số lẻ" << endl;
    else
        cout << "=> Hai tổng không bằng nhau" << endl;

    return 0;
}