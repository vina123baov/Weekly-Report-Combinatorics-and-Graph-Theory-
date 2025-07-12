#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <functional>

using namespace std;

// ==================== MỆNH ĐỀ 1 ====================

// Tính hệ số C(n,k) - tổ hợp
long long toHop(int n, int k) {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k; // Tối ưu
    
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

// Câu a: Tính hệ số của x^r trong (1 + x + x^2 + ...)^n
long long heSoCauA(int n, int r) {
    return toHop(r + n - 1, r);
}

// Câu b: Hệ số của x^k trong (1 - x^m)^n
long long heSoCauB(int n, int m, int k) {
    if (k % m != 0) return 0;
    int j = k / m;
    if (j > n) return 0;
    long long heSo = toHop(n, j);
    if (j % 2 == 1) heSo = -heSo;
    return heSo;
}

// ==================== MỆNH ĐỀ 2 ====================

// Tính hệ số của x^r trong tích A(x)B(x)
long long heSoTichHamSinh(const vector<long long>& A, const vector<long long>& B, int r) {
    long long result = 0;
    for (int i = 0; i <= r && i < A.size(); i++) {
        int j = r - i;
        if (j < B.size()) {
            result += A[i] * B[j];
        }
    }
    return result;
}

// Nhân hai đa thức (trả về vector hệ số)
vector<long long> nhanDaThuc(const vector<long long>& A, const vector<long long>& B) {
    int degA = A.size() - 1;
    int degB = B.size() - 1;
    vector<long long> C(degA + degB + 1, 0);
    
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j];
        }
    }
    return C;
}

// ==================== BÀI TOÁN DÃY SỐ ====================

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

// ==================== CÔNG THỨC EULER ====================

// Đếm nghiệm bằng vét cạn (brute force)
int demNghiemVetCan(int n, const vector<int>& m_vals, const vector<int>& M_vals) {
    int m = m_vals.size();
    vector<int> x(m);
    int count = 0;

    std::function<void(int)> thuGiaTri = [&](int idx) {
        if (idx == m) {
            int sum = 0;
            for (int i = 0; i < m; i++) sum += x[i];
            if (sum == n) count++;
            return;
        }

        for (int val = m_vals[idx]; val <= M_vals[idx]; val++) {
            x[idx] = val;
            thuGiaTri(idx + 1);
        }
    };

    thuGiaTri(0);
    return count;
}

// Đếm nghiệm bằng (dynamic programming)
int demNghiemDP(int n, const vector<int>& m_vals, const vector<int>& M_vals) {
    int m = m_vals.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = m_vals[i-1]; k <= M_vals[i-1] && k <= j; k++) {
                dp[i][j] += dp[i-1][j-k];
            }
        }
    }
    return dp[m][n];
}

// ==================== HÀM TIỆN ÍCH ====================

void inDaThuc(const vector<long long>& coeffs, const string& ten = "P(x)") {
    cout << ten << " = ";
    bool first = true;
    
    for (int i = 0; i < coeffs.size(); i++) {
        if (coeffs[i] != 0) {
            if (!first && coeffs[i] > 0) cout << " + ";
            if (coeffs[i] < 0) cout << " - ";
            if (abs(coeffs[i]) != 1 || i == 0) cout << abs(coeffs[i]);
            if (i == 1) cout << "x";
            else if (i > 1) cout << "x^" << i;
            first = false;
        }
    }
    if (first) cout << "0";
    cout << endl;
}

// ==================== MAIN ====================

int main() {
    cout << "=== TUẦN 5 - CÁC THUẬT TOÁN ===" << endl << endl;

    // Test Mệnh đề 1
    cout << "1. MỆNH ĐỀ 1 - HÀM SINH" << endl;
    cout << "Hệ số của x^5 trong (1 + x + x^2 + ...)^3:" << endl;
    cout << "a_5 = C(5+3-1, 5) = C(7,5) = " << heSoCauA(3, 5) << endl;

    cout << "\nHệ số trong (1 - x^2)^4:" << endl;
    for (int k = 0; k <= 8; k += 2) {
        cout << "Hệ số của x^" << k << " = " << heSoCauB(4, 2, k) << endl;
    }

    // Test Mệnh đề 2
    cout << "\n2. MỆNH ĐỀ 2 - TÍCH HÀM SINH" << endl;
    vector<long long> A = {1, 2, 3};  // 1 + 2x + 3x^2
    vector<long long> B = {4, 5};     // 4 + 5x

    cout << "A(x) = ";
    inDaThuc(A, "A(x)");
    cout << "B(x) = ";
    inDaThuc(B, "B(x)");

    vector<long long> C = nhanDaThuc(A, B);
    cout << "A(x)B(x) = ";
    inDaThuc(C, "A(x)B(x)");

    // Test Bài toán dãy số
    cout << "\n3. BÀI TOÁN DÃY SỐ" << endl;
    vector<int> day = {1, 2, 3, 4, 5};
    int N = 10;
    cout << "Dãy: ";
    for (int x : day) cout << x << " ";
    cout << "\nN = " << N << endl;
    cout << "Tổng = " << tinhTongDaySo(N, day) << endl;

    // Test Công thức Euler
    cout << "\n4. CÔNG THỨC EULER - ĐẾM NGHIỆM" << endl;
    cout << "Giải: x1 + x2 + x3 = 10" << endl;
    cout << "Điều kiện: 1 <= x1 <= 4, 2 <= x2 <= 5, 1 <= x3 <= 4" << endl;

    vector<int> m_vals = {1, 2, 1};
    vector<int> M_vals = {4, 5, 4};
    int n = 10;

    int soNghiem1 = demNghiemVetCan(n, m_vals, M_vals);
    int soNghiem2 = demNghiemDP(n, m_vals, M_vals);

    cout << "Số nghiệm (vét cạn): " << soNghiem1 << endl;
    cout << "Số nghiệm (quy hoạch động): " << soNghiem2 << endl;

    cout << "\nVí dụ 2: x1 + x2 + x3 + x4 = 20" << endl;
    cout << "Điều kiện: 2 <= xi <= 8 với mọi i" << endl;

    vector<int> m_vals2 = {2, 2, 2, 2};
    vector<int> M_vals2 = {8, 8, 8, 8};
    int n2 = 20;

    int soNghiem3 = demNghiemDP(n2, m_vals2, M_vals2);
    cout << "Số nghiệm: " << soNghiem3 << endl;

    int tongMin = 0, tongMax = 0;
    for (int i = 0; i < m_vals2.size(); i++) {
        tongMin += m_vals2[i];
        tongMax += M_vals2[i];
    }
    cout << "Kiểm tra: " << tongMin << " <= " << n2 << " <= " << tongMax;
    cout << " => " << (tongMin <= n2 && n2 <= tongMax ? "Khả thi" : "Không khả thi") << endl;

    return 0;
}
