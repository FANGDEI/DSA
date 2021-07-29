#include <iostream>
#include <algorithm>
/*[最大正方形]https://www.luogu.com.cn/problem/P1387*/
using namespace std;
int a[105][105], s[105][105]; // 前缀和
int main() {
    int n, m;
    cin >> n >> m;
    int maxSideLength = min(n, m); // 正方形的最大边长
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1]; // 前缀和预处理
        }
    }
    int ans = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int sideLength = 1; sideLength <= maxSideLength; sideLength++) {
                int ii = i + sideLength - 1;
                int jj = j + sideLength - 1;
                if (ii > n || jj > m || s[ii][jj]-s[i-1][jj]-s[ii][j-1]+s[i-1][j-1] != sideLength * sideLength) break;
                ans = max(ans, sideLength);
            }
        }
    }
    cout << ans << endl;
    return 0;
}