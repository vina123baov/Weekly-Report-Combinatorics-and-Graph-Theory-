#include <iostream>
#include <vector>

using namespace std;

double tinhTongDaySo(int N, const vector<int>& n_vals) {
    double tong = 0;
    int size = n_vals.size();
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            tong += n_vals[i] - N + n_vals[j] + 3;
        }
    }
    return tong;
}

int main() {
    cout << "=== SEQUENCE SUM ===" << endl;
    vector<int> day = {1, 2, 3, 4, 5};
    int N = 10;
    cout << "Sequence: ";
    for (int x : day) cout << x << " ";
    cout << "\nN = " << N << endl;
    cout << "Sum = " << tinhTongDaySo(N, day) << endl;

    return 0;
}