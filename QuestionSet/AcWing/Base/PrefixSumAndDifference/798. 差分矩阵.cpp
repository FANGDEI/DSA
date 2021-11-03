/*
 * @Author: FANG
 * @Date: 2021-11-03 21:04:39
 */
#include <iostream>
using namespace std;
const int N = 1005;
int a[N][N], b[N][N];
void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            insert(i, j, i, j, a[i][j]);
        }
    }
    while (q--) {
        int a, b, c, d, r;
        cin >> a >> b >> c >> d >> r;
        insert(a, b, c, d, r);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}