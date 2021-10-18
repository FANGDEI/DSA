/*
 * @Author: FANG
 * @Date: 2021-10-18 13:15:37
 */
#include <iostream>
using namespace std;
int n, m;
int f[1005][1005];
int v[1005], w[1005];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}

/*
优化:
#include <iostream>
#include <algorithm>
using namespace std;
const int Max = 1e4 + 5;
int N, V;
int v[Max], w[Max], f[Max];
int main() {
    cin >> N >> V;
    for (int i=1; i<=N; i++) cin >> v[i] >> w[i];
    for (int i=1; i<=N; i++) {
        for (int j=V; j>=v[i]; j--) {
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}