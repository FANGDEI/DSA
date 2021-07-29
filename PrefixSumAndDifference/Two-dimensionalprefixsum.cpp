/*
    [最大子矩阵]https://vjudge.net/problem/HDU-1559
*/
#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], s[1005][1005];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                cin >> a[i][j];
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                s[i][j] = s[i-1][j] + s[i][j-1] -s[i-1][j-1] + a[i][j];
        int ans = -1e-9;
        for (int i=1; i+x-1<=m; i++) {
            for (int j=1; j+y-1<=n; j++) {
                int ti = i+x-1, tj = j+y-1;
                int t = s[ti][tj] - s[i-1][tj] - s[ti][j-1] + s[i-1][j-1];
                ans = max(ans, t);
            }
        }
        cout << ans << endl;
    }
    return 0;
}