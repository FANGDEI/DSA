/*
 * @Author: FANG
 * @Date: 2021-11-02 18:39:44
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> A;
vector<int> mult(vector<int> &a, int b) {
    vector<int> res;
    int t = 0; // 进位
    for (int i = 0; i < a.size(); i++) {
        t += a[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }
    while (t) { // 进位直到进位为0
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}
int main() {
    string a;
    int b;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    auto C = mult(A, b);
    if (C[C.size() - 1] == 0) cout << "0"; // 判断得到的结果是否为0
    else for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl;
    return 0;
}