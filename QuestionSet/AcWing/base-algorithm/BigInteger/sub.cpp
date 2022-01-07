/*
 * @Author: FANG
 * @Date: 2021-11-02 18:39:22
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i--) if (a[i] != b[i]) return a[i] > b[i];
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;

    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}
string a, b;
vector<int> A, B;
int main() {
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if (cmp(A, B)) {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
        cout << endl;
    } else {
        cout << "-";
        auto C = sub(B, A);
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
        cout << endl;
    }

    return 0;
}
