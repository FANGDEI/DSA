//P3406 海底高铁
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n, m, a[N], b[N], c[N], p[N], vis[N];
int main() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) cin >> p[i];
    for (int i=1; i<=n-1; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i=1; i<=m-1; i++) {
        int x, y;
        if (p[i] < p[i+1]) {
            x = p[i];
            y = p[i+1];
        } else {
            x = p[i+1];
            y = p[i];
        }
        vis[x]++;
        vis[y]--;
    }
    for (int i=1; i<=n-1; i++) {
        vis[i] += vis[i-1];
    }
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ans += min(a[i]*vis[i], b[i]*vis[i]+c[i]);
    }
    cout << ans << endl;
    return 0;
}