/*
 * @Author: FANG
 * @Date: 2021-11-03 13:16:52
 */
#include <iostream>
using namespace std;
int main() {
    int n, m, s[100005], a[100005];
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = a[i] - a[i - 1];
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        s[l] += c;
        s[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = s[i] + a[i - 1];
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}