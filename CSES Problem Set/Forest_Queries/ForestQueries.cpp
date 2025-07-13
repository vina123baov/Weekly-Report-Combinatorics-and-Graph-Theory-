#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1005;

int n, q;
int prefix[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    vector<string> forest(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> forest[i];
        forest[i] = ' ' + forest[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (forest[i][j] == '*');
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int res = prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1];
        cout << res << '\n';
    }

    return 0;
}
