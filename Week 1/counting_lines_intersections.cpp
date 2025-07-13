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

long long countLines(int n) {
    return combination(n, 2);
}

long long countIntersections(int n) {
    return combination(n, 2);
}

void testCountingProblems() {
    cout << "=== DEM DUONG THANG VA GIAO DIEM ===\n\n";
    
    cout << "1. DEM SO DUONG THANG TU n DIEM:\n";
    cout << "   - Gia su khong co 3 diem nao thang hang\n";
    cout << "   - Moi cap diem tao 1 duong thang\n";
    cout << "   - So duong thang = C(n,2) = n(n-1)/2\n\n";
    
    cout << "n diem\tSo duong thang\n";
    cout << "------\t--------------\n";
    for (int n = 2; n <= 10; n++) {
        cout << n << "\t" << countLines(n) << "\n";
    }
    
    cout << "\n2. DEM SO GIAO DIEM CUA n DUONG THANG:\n";
    cout << "   - Gia su khong co 2 duong nao song song\n";
    cout << "   - Gia su khong co 3 duong nao dong quy\n";
    cout << "   - Moi cap duong thang tao 1 giao diem\n";
    cout << "   - So giao diem = C(n,2) = n(n-1)/2\n\n";
    
    cout << "n duong\tSo giao diem\n";
    cout << "-------\t------------\n";
    for (int n = 2; n <= 10; n++) {
        cout << n << "\t" << countIntersections(n) << "\n";
    }
}

int main() {
    testCountingProblems();
    
    cout << "\n=== TINH TOAN CU THE ===\n";

    cout << "\nNhap so diem: ";
    int points;
    cin >> points;
    cout << points << " diem tao " << countLines(points) << " duong thang\n";

    cout << "\nNhap so duong thang: ";
    int lines;
    cin >> lines;
    cout << lines << " duong thang tao " << countIntersections(lines) << " giao diem\n";

    cout << "\n=== VI DU UNG DUNG ===\n";
    cout << "1. Giai bong da vong tron:\n";
    cout << "   - " << 20 << " doi thi dau => " << countLines(20) << " tran dau\n";
    
    cout << "\n2. Bai toan bac tay:\n";
    cout << "   - " << 10 << " nguoi => moi nguoi bat tay " << 9 << " lan\n";
    cout << "   - Tong so lan bat tay = " << countLines(10) << "\n";
    
    return 0;
}