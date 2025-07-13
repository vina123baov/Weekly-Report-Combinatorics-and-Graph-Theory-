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

long long countBinarySequences(int n, int m) {

    if (2 * m > n + 1) return 0;

    return combination(n - m + 1, m);
}

void testProblem3() {
    cout << "=== Problem 3: Day nhi phan khong co 2 so 0 lien tiep ===\n";
    cout << "Bai toan: Dem so day nhi phan do dai n co dung m so 0\n";
    cout << "         va khong co 2 so 0 lien tiep.\n\n";
    
    cout << "Cong thuc: C(n-m+1, m) voi dieu kien 2m <= n+1\n";
    cout << "Giai thich:\n";
    cout << "- Giua cac so 0 phai co it nhat 1 so 1\n";
    cout << "- Co n-m so 1, tao n-m+1 vi tri de dat m so 0\n";
    cout << "- Chon m vi tri trong n-m+1 vi tri\n\n";
    
    cout << "Vi du:\n";
    cout << "n=5, m=2: " << countBinarySequences(5, 2) << " cach\n";
    cout << "Cac day: 10101, 10110, 01101, 01011, 11010, 01110\n\n";
    
    cout << "n=6, m=3: " << countBinarySequences(6, 3) << " cach\n";
    cout << "Cac day: 101010, 101101, 110101, 011010\n\n";
    
    cout << "Bang gia tri:\n";
    cout << "n\tm\tSo cach\n";
    cout << "---\t---\t-------\n";
    for (int n = 3; n <= 8; n++) {
        for (int m = 1; m <= (n+1)/2; m++) {
            cout << n << "\t" << m << "\t" 
                 << countBinarySequences(n, m) << "\n";
        }
        cout << "\n";
    }
}

int main() {
    testProblem3();
    
    cout << "Nhap do dai day (n): ";
    int n;
    cin >> n;
    
    cout << "Nhap so luong so 0 (m): ";
    int m;
    cin >> m;
    
    long long result = countBinarySequences(n, m);
    if (result == 0) {
        cout << "Khong the tao day nhi phan thoa man yeu cau!\n";
        cout << "(Dieu kien: 2m <= n+1)\n";
    } else {
        cout << "So day nhi phan do dai " << n << " co " << m 
             << " so 0 va khong co 2 so 0 lien tiep: " << result << "\n";
    }
    
    return 0;
}