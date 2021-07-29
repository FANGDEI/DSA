//最长公共子序列 50
#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int N = 100000 + 5;
int a[N], b[N], f[1001][1001];
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout << f[n][n] << endl;
    return 0;
}