#include <iostream>
#include <vector>

using namespace std;

void countDivisibleNumbers() {
    cout << "=== Vi du 1: So nguyen tu 1 den 100 chia het cho 2, 3 hoac 5 ===\n";
    
    int n = 100;
    
    // Đếm số chia hết cho từng số
    int div2 = n / 2;
    int div3 = n / 3;
    int div5 = n / 5;

    int div23 = n / 6;
    int div25 = n / 10;
    int div35 = n / 15;

    int div235 = n / 30;

    int result = div2 + div3 + div5 - div23 - div25 - div35 + div235;
    
    cout << "\nChi tiet tinh toan:\n";
    cout << "- Chia het cho 2: " << div2 << "\n";
    cout << "- Chia het cho 3: " << div3 << "\n";
    cout << "- Chia het cho 5: " << div5 << "\n";
    cout << "- Chia het cho 2 va 3: " << div23 << "\n";
    cout << "- Chia het cho 2 va 5: " << div25 << "\n";
    cout << "- Chia het cho 3 va 5: " << div35 << "\n";
    cout << "- Chia het cho 2, 3 va 5: " << div235 << "\n";
    
    cout << "\nCong thuc: |A ∪ B ∪ C| = |A| + |B| + |C| - |A ∩ B| - |A ∩ C| - |B ∩ C| + |A ∩ B ∩ C|\n";
    cout << "Ket qua: " << div2 << " + " << div3 << " + " << div5 
         << " - " << div23 << " - " << div25 << " - " << div35 
         << " + " << div235 << " = " << result << "\n";

    cout << "\nDanh sach cac so (kiem tra):\n";
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
            if (count < 20) cout << i << " ";
            count++;
        }
    }
    cout << "...\nTong cong: " << count << " so\n";
}

void derangementByInclusion(int n) {
    cout << "\n\n=== Vi du 2: Derangement bang nguyen ly bu tru ===\n";
    cout << "Dem so hoan vi cua {1,2,...," << n << "} khong co diem co dinh\n\n";

    long long factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    
    cout << "Tong so hoan vi: " << factorial << "\n";
    cout << "\nAp dung nguyen ly bu tru:\n";
    
    long long result = 0;
    for (int k = 0; k <= n; k++) {
        long long term = 1;

        for (int i = 0; i < k; i++) {
            term = term * (n - i) / (i + 1);
        }

        for (int i = 1; i <= n - k; i++) {
            term *= i;
        }
        
        if (k % 2 == 0) {
            cout << "+ ";
            result += term;
        } else {
            cout << "- ";
            result -= term;
        }
        
        cout << "C(" << n << "," << k << ") * " << (n-k) << "! = " << term << "\n";
    }
    
    cout << "\nKet qua: D_" << n << " = " << result << "\n";
}

void countNumbersWithSeven() {
    cout << "\n\n=== Vi du 3: So co 3 chu so chua it nhat mot chu so 7 ===\n";

    int total = 900;
    int without7 = 8 * 9 * 9;

    int with7 = total - without7;
    
    cout << "Tong so co 3 chu so: " << total << "\n";
    cout << "So khong chua chu so 7: " << without7 << "\n";
    cout << "So chua it nhat 1 chu so 7: " << with7 << "\n";
    
    cout << "\nKiem tra bang cach khac:\n";
    cout << "- Co 7 o hang tram: 100 so (700-799)\n";
    cout << "- Co 7 o hang chuc (khong o hang tram): 8 * 10 = 80 so\n";
    cout << "- Co 7 o hang don vi (khong o 2 vi tri tren): 8 * 9 = 72 so\n";
    cout << "Tong: 100 + 80 + 72 = " << 100 + 80 + 72 << "\n";
}

int main() {
    cout << "=== MINH HOA NGUYEN LY BU TRU ===\n";
    cout << "(Inclusion-Exclusion Principle)\n\n";
    
    cout << "Nguyen ly: |A1 ∪ A2 ∪ ... ∪ An| = \n";
    cout << "  Σ|Ai| - Σ|Ai ∩ Aj| + Σ|Ai ∩ Aj ∩ Ak| - ... + (-1)^(n+1)|A1 ∩ ... ∩ An|\n";

    countDivisibleNumbers();

    derangementByInclusion(4);

    countNumbersWithSeven();
    
    return 0;
}