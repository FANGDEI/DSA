/*
 * @Author: FANG
 * @Date: 2021-11-02 18:38:31
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> add(vector<int> &A, vector<int> &B) {
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t != 0) C.push_back(t);
    return C;
}
string a, b;
vector<int> A, B;
int main() {
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl;
    return 0;
}