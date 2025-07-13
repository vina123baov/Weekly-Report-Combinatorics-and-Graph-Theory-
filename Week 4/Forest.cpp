#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bài P 10.2.8
int forestEdges(int n, int t) {
    return n - t;
}

// Bài P 10.2.9
void proveTreeHasAtLeastTwoLeaves() {
    cout << "Chứng minh mọi cây hữu hạn (≥2 đỉnh) có ít nhất 2 lá:\n\n";
    
    cout << "Giả sử cây T có n đỉnh (n ≥ 2) và n-1 cạnh.\n";
    cout << "Gọi d_i là bậc của đỉnh i.\n\n";
    
    cout << "Ta có: Σd_i = 2|E| = 2(n-1) = 2n - 2\n\n";
    
    cout << "Giả sử có k lá (đỉnh bậc 1).\n";
    cout << "Các đỉnh không phải lá có bậc ≥ 2.\n\n";
    
    cout << "Do đó: Σd_i ≥ k × 1 + (n-k) × 2 = 2n - k\n\n";
    
    cout << "Từ Σd_i = 2n - 2, ta có:\n";
    cout << "2n - 2 ≥ 2n - k\n";
    cout << "=> k ≥ 2\n\n";
    
    cout << "Vậy mọi cây có ít nhất 2 lá. □\n";
}

// Bài P 10.2.10
int minLeavesWithDegree4Vertex(int degree4Count = 1) {
    cout << "\nBài P 10.2.10: Cây có " << degree4Count << " đỉnh bậc 4\n";
    cout << "Số lá tối thiểu: 4\n";
    cout << "Cấu trúc: 1 đỉnh bậc 4 nối với 4 lá (cây sao K_{1,4})\n";
    
    return 4;
}

// Bài P 10.2.11
void proveCycleFromDegreeSequence() {
    cout << "\nBài P 10.2.11: Đồ thị với dãy bậc (3,3,3,2,1)\n\n";
    
    vector<int> degrees = {3, 3, 3, 2, 1};
    int n = degrees.size();
    int sum = 0;
    for (int d : degrees) sum += d;
    
    cout << "Số đỉnh n = " << n << "\n";
    cout << "Tổng bậc = " << sum << "\n";
    cout << "Số cạnh = " << sum/2 << "\n\n";
    
    cout << "Nếu đồ thị là cây, cần có n-1 = " << n-1 << " cạnh\n";
    cout << "Nhưng đồ thị có " << sum/2 << " cạnh\n\n";
    
    cout << "Vì " << sum/2 << " > " << n-1 << ", đồ thị có chu trình. □\n";
}

// Bài P 10.2.7
void checkIf5Vertices4EdgesIsTree() {
    cout << "\nBài P 10.2.7: Đồ thị đơn với 5 đỉnh và 4 cạnh\n\n";
    
    cout << "Một cây với 5 đỉnh phải có đúng 5-1 = 4 cạnh ✓\n";
    cout << "Nhưng điều này chỉ là điều kiện cần.\n\n";
    
    cout << "Có thể là cây nếu:\n";
    cout << "- Đồ thị liên thông\n";
    cout << "- Không có chu trình\n\n";
    
    cout << "Không nhất thiết là cây nếu:\n";
    cout << "- Đồ thị không liên thông (ví dụ: K3 + 2 đỉnh cô lập)\n";
    cout << "- Có chu trình (ví dụ: C3 + P2)\n\n";
    
    cout << "Kết luận: KHÔNG nhất thiết phải là cây.\n";
}

int main() {
    cout << "=== CÁC BÀI TOÁN VỀ CÂY VÀ RỪNG ===\n\n";
    
    // Bài P 10.2.8
    cout << "Bài P 10.2.8: Rừng với t cây và n đỉnh\n";
    cout << "Số cạnh = n - t\n";
    cout << "Ví dụ: n=10, t=3 => số cạnh = " << forestEdges(10, 3) << "\n";
    cout << string(50, '-') << "\n";
    
    // Bài P 10.2.9
    proveTreeHasAtLeastTwoLeaves();
    cout << string(50, '-') << "\n";
    
    // Bài P 10.2.10
    minLeavesWithDegree4Vertex();
    cout << string(50, '-') << "\n";
    
    // Bài P 10.2.11
    proveCycleFromDegreeSequence();
    cout << string(50, '-') << "\n";
    
    // Bài P 10.2.7
    checkIf5Vertices4EdgesIsTree();
    
    return 0;
}