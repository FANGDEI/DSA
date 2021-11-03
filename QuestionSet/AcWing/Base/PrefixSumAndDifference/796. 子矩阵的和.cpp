/*
 * @Author: FANG
 * @Date: 2021-11-03 13:16:32
 */
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, q;
int a[1005][1005], s[1005][1005];
int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << s[c][d] - s[c][b - 1] - s[a - 1][d] + s[a - 1][b - 1] << endl;
    }
    return 0;
}