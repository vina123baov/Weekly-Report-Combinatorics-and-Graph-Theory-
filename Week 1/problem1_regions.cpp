#include <iostream>

using namespace std;

long long countRegions(int n) {
    return 1 + (long long)n * (n + 1) / 2;
}

void testProblem1() {
    cout << "=== Problem 1: So vung tao boi n duong thang ===\n";
    cout << "Bai toan: Cho n duong thang khong song song va khong co 3 duong nao dong quy.\n";
    cout << "Tim so vung ma n duong thang chia mat phang.\n\n";
    
    cout << "Cong thuc: f(n) = 1 + n(n+1)/2\n";
    cout << "Giai thich:\n";
    cout << "- Khi n = 0: Mat phang co 1 vung\n";
    cout << "- Moi duong thang them vao cat tat ca duong thang truoc do\n";
    cout << "- Duong thang thu i cat i-1 duong thang, tao i vung moi\n";
    cout << "- Tong so vung = 1 + 1 + 2 + ... + n = 1 + n(n+1)/2\n\n";
    
    cout << "Bang gia tri:\n";
    cout << "n\tf(n)\n";
    cout << "---\t----\n";
    for (int n = 0; n <= 10; n++) {
        cout << n << "\t" << countRegions(n) << "\n";
    }
}

int main() {
    testProblem1();
    
    cout << "\nNhap so duong thang n: ";
    int n;
    cin >> n;
    
    cout << n << " duong thang chia mat phang thanh " 
         << countRegions(n) << " vung\n";
    
    return 0;
}