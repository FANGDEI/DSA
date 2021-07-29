//897. 最长公共子序列[https://www.acwing.com/problem/content/description/899/]
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
char a[1005], b[1005];
int f[1005][1005];
int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> b[i];
    // int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}