//[https://vjudge.ppsucxtt.cn/problem/POJ-3468]
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll n, q;
ll a[N], d[N << 2], b[N << 2];
void build(ll l, ll r, ll p) {
    if (l == r) {
        d[p] = a[l];
        return ;
    }
    ll m = l + (r - l >> 1);
    build(l, m, p << 1);
    build(m + 1, r, p << 1 | 1);
    d[p] = d[p << 1] + d[p << 1 | 1];
}
void update(ll l, ll r, ll s, ll t, ll c, ll p) {
    if (l <= s and t <= r) {
        d[p] += (t - s + 1) * c;
        b[p] += c;
        return ;
    }
    ll m = s + (t - s >> 1);
    if (b[p] && s != t) {
        d[p << 1] += b[p] * (m - s + 1), d[p << 1 | 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p];
        b[p] = 0;
    }
    if (l <= m) update(l, r, s, m, c, p << 1);
    if (r > m) update(l, r, m + 1, t, c, p << 1 | 1);
    d[p] = d[p << 1] + d[p << 1 | 1];
}
ll getsum(ll l, ll r, ll s, ll t, ll p) {
    if (l <= s and t <= r) return d[p];
    ll m = s + (t - s >> 1);
    if (b[p]) {
        d[p << 1] += b[p] * (m - s + 1), d[p << 1 | 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p];
        b[p] = 0;
    }
    ll sum = 0;
    if (l <= m) sum += getsum(l, r, s, m, p << 1);
    if (r > m) sum += getsum(l, r, m + 1, t, p << 1 | 1);
    return sum;
}
int main() {
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> a[i];
    build(1, n, 1);
    char s;
    while (q--) {
        cin >> s;
        ll x, y, k;
        if (s == 'Q') {
            cin >> x >> y;
            cout << getsum(x, y, 1, n, 1) << endl;
        } else {
            cin >> x >> y >> k;
            update(x, y, 1, n, k, 1);
        }
    }
    return 0;
}