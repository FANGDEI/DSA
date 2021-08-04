//P3368 【模板】树状数组 2
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll; // 不开longlong见祖宗
const int N = 500005;
ll n, m;
ll sum[N], a[N];
ll lowbit(ll x) {
    return x & -x;
}
void update(ll i, ll k) {
    while (i <= n) {
        sum[i] += k;
        i += lowbit(i);
    }
}
ll ask(ll i) {
    ll ans = 0;
    while (i > 0) {
        ans += sum[i];
        i -= lowbit(i);
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        update(i, a[i] - a[i-1]);
    }
    while (m--) {
        int op, x, y, k;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            update(x, k);
            update(y+1, -k);
        } else if (op == 2) {
            cin >> x;
            cout << ask(x) << endl;
        }
    }
    return 0;
}