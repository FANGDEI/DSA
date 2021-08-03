//P1803 凌乱的yyy / 线段覆盖
#include <bits/stdc++.h>
using namespace std;
struct A {
    int a, b;
    bool operator < (const A x) {
        return this->b < x.b;
    }
} a[1000005];
int n;
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i].a >> a[i].b;
    sort(a+1, a+n+1);
    int ans = 1;
    int m = a[1].b;
    for (int i=1; i<=n; i++) if (a[i].a >= m) ans++, m = a[i].b;
    cout << ans << endl;
    return 0;
}