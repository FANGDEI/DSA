/*
 * @Author: FANG
 * @Date: 2021-09-08 20:50:06
 * @LastEditTime: 2021-09-08 20:56:33
 * @Description: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_D
 * @FilePath: \DSA\QuestionSet\AOJ\Maximum Profit.cpp
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int minVal, ans = -0x3f3f3f3f;
    cin >> minVal;
    for (int i = 0; i < n - 1; i++) {
        int t;
        cin >> t;
        ans = max(ans, t - minVal);
        minVal = min(minVal, t);
    }
    cout << ans << endl;
    return 0;
}