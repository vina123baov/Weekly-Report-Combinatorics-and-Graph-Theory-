#include <iostream>
using namespace std;

long long countPositiveSolutions(int m, int n) {
    if (m < n) return 0;
    long long result = 1;
    for (int i = 0; i < n - 1; i++) {
        result = result * (m - 1 - i) / (i + 1);
    }
    return result;
}

long long countNonNegativeSolutions(int m, int n) {
    long long result = 1;
    for (int i = 0; i < n - 1; i++) {
        result = result * (m + n - 1 - i) / (i + 1);
    }
    return result;
}

int main() {
    cout << "Nghiệm dương của x1 + x2 + x3 = 10: " 
         << countPositiveSolutions(10, 3) << endl;
    cout << "Nghiệm không âm của x1 + x2 + x3 = 10: " 
         << countNonNegativeSolutions(10, 3) << endl;
    return 0;
}