//895. 最长上升子序列[https://www.acwing.com/problem/content/897/]
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, a[N], f[N];
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        f[i] = 1;
        for (int j=1; j<=i; j++) {
            // f[i] = max(f[i], f[j]+1);
            if (a[i] > a[j]) f[i] = max(f[i], f[j]+1);
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) ans = max(f[i], ans);
    cout << ans << endl;
    return 0;
}