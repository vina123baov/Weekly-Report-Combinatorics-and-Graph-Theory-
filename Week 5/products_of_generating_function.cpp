#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    cout << "=== PRODUCT OF GENERATING FUNCTIONS ===" << endl;
    vector<long long> A = {1, 2, 3};
    vector<long long> B = {4, 5};

    cout << "A(x) = ";
    inDaThuc(A, "A(x)");
    cout << "B(x) = ";
    inDaThuc(B, "B(x)");

    vector<long long> C = nhanDaThuc(A, B);
    cout << "A(x)B(x) = ";
    inDaThuc(C, "A(x)B(x)");

    return 0;
}