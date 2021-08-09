//P2910 [USACO08OPEN]Clear And Present Danger S
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
const int M = 1e4 + 5;
int Map[N][N], a[M];
int n, m;
int main() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> Map[i][j];
        }
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i=2; i<=m; i++) {
        ans += Map[a[i-1]][a[i]];
    }
    cout << ans << endl;
    return 0;
}