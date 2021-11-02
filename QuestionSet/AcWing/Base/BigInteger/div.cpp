/*
 * @Author: FANG
 * @Date: 2021-11-02 18:40:37
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C;

    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }

    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main() {
    vector<int> A;
    int b, r = 0;
    string a;
    cin >> a >> b;
    for (int i = a.length() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout <<  endl << r << endl;
    return 0;
}