/*
 * @Author: FANG
 * @Date: 2021-11-03 13:16:14
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
int sum[N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        sum[i] = sum[i - 1] + t;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}