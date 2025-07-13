#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

bool checkEulerTheorem(vector<int>& degrees) {
    int sum = 0;
    for (int d : degrees) {
        sum += d;
    }
    return sum % 2 == 0;
}

bool havelHakimi(vector<int> degrees) {
    while (!degrees.empty()) {
        sort(degrees.begin(), degrees.end(), greater<int>());
        while (!degrees.empty() && degrees.back() == 0) {
            degrees.pop_back();
        }
        if (degrees.empty()) return true;
        int k = degrees[0];
        if (k > degrees.size() - 1) return false;
        degrees.erase(degrees.begin());
        for (int i = 0; i < k; i++) {
            degrees[i]--;
            if (degrees[i] < 0) return false;
        }
    }
    return true;
}

bool isGraphicalSequence(vector<int> degrees) {
    if (!checkEulerTheorem(degrees)) return false;
    int n = degrees.size();
    for (int d : degrees) {
        if (d >= n) return false;
    }
    return havelHakimi(degrees);
}

int main() {
    ifstream input("graphical_sequence.inp");
    ofstream output("graphical_sequence.out");
    int t;
    input >> t;
    while (t--) {
        int n;
        input >> n;
        vector<int> degrees(n);
        for (int i = 0; i < n; i++) {
            input >> degrees[i];
        }
        output << (isGraphicalSequence(degrees) ? "1" : "0") << endl;
    }
    input.close();
    output.close();
    return 0;
}