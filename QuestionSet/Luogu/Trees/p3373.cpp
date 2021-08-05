//P3373 【模板】线段树 2 30
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll n, m, mod;
ll a[N], add[N << 3], mul[N << 3], d[N << 3];
void build(ll l, ll r, ll p) {
    mul[p] = 1;
    if (l == r) {
        d[p] = a[l];
        return ;
    }
    ll m = l + (r - l >> 1);
    build(l, m, p << 1);
    build(m + 1, r, p << 1 | 1);
    d[p] = (d[p << 1] + d[p << 1 | 1]) % mod;
}
void Add(ll l, ll r, ll s, ll t, ll c, ll p) {
    if (l <= s and t <= r) {
        d[p] += (t - s + 1) * c;
        d[p] %= mod;
        add[p] += c;
        add[p] %= mod;
        return ;
    }
    ll m = s + (t - s >> 1);
    if (mul[p] != 1) {
        mul[p << 1] *= mul[p];
        mul[p << 1] %= mod;
        mul[p << 1 | 1] *= mul[p];
        mul[p << 1 | 1] %= mod;
        add[p << 1] *= mul[p];
        add[p << 1] %= mod;
        add[p << 1 | 1] *= mul[p];
        add[p << 1 | 1] %= mod;
        d[p << 1] *= mul[p];
        d[p << 1] %= mod;
        d[p << 1 | 1] *= mul[p];
        d[p << 1 | 1] %= mod;
        mul[p] = 1;
    }
    if (add[p]) {
        d[p << 1] += add[p] * (m - s + 1), d[p << 1 | 1] += add[p] * (t - m);
        d[p << 1] %= mod, d[p << 1 | 1] %= mod;
        add[p << 1] += add[p], add[p << 1 | 1] += add[p];
        add[p << 1] %= mod, add[p << 1 | 1] %= mod;
        add[p] = 0;
    }
    if (l <= m) Add(l, r, s, m, c, p << 1);
    if (r > m) Add(l, r, m + 1, t, c, p << 1 | 1);
    d[p] = d[p << 1] + d[p << 1 | 1];
    d[p] %= mod;
}
void Mult(ll l, ll r, ll s, ll t, ll c, ll p) {
    if (l <= s and t <= r) {
        d[p] *= c;
        d[p] %= mod;
        mul[p] *= c;
        mul[p] %= mod;
        add[p] *= c;
        add[p] %= mod;
        return ;
    }
    ll m = s + (t - s >> 1);
    if (mul[p] != 1) {
        mul[p << 1] *= mul[p];
        mul[p << 1] %= mod;
        mul[p << 1 | 1] *= mul[p];
        mul[p << 1 | 1] %= mod;
        add[p << 1] *= mul[p];
        add[p << 1] %= mod;
        add[p << 1 | 1] *= mul[p];
        add[p << 1 | 1] %= mod;
        d[p << 1] *= mul[p];
        d[p << 1] %= mod;
        d[p << 1 | 1] *= mul[p];
        d[p << 1 | 1] %= mod;
        mul[p] = 1;
    }
    if (add[p]) {
        d[p << 1] += add[p] * (m - s + 1), d[p << 1 | 1] += add[p] * (t - m);
        d[p << 1] %= mod, d[p << 1 | 1] %= mod;
        add[p << 1] += add[p], add[p << 1 | 1] += add[p];
        add[p << 1] %= mod, add[p << 1 | 1] %= mod;
        add[p] = 0;
    }
    if (l <= m) Mult(l, r, s, m, c, p << 1);
    if (r > m) Mult(l, r, m + 1, r, c, p << 1 | 1);
    d[p] = (d[p << 1] + d[p << 1 | 1]) % mod;
}
ll getsum(ll l, ll r, ll s, ll t, ll p) {
    if (l <= s and t <= r) return d[p];
    ll m = s + (t - s >> 1);
    if (mul[p] != 1) {
        mul[p << 1] *= mul[p];
        mul[p << 1] %= mod;
        mul[p << 1 | 1] *= mul[p];
        mul[p << 1 | 1] %= mod;
        add[p << 1] *= mul[p];
        add[p << 1] %= mod;
        add[p << 1 | 1] *= mul[p];
        add[p << 1 | 1] %= mod;
        d[p << 1] *= mul[p];
        d[p << 1] %= mod;
        d[p << 1 | 1] *= mul[p];
        d[p << 1 | 1] %= mod;
        mul[p] = 1;
    }
    if (add[p]) {
        d[p << 1] += add[p] * (m - s + 1), d[p << 1 | 1] += add[p] * (t - m);
        d[p << 1] %= mod, d[p << 1 | 1] %= mod;
        add[p << 1] += add[p], add[p << 1 | 1] += add[p];
        add[p << 1] %= mod, add[p << 1 | 1] %= mod;
        add[p] = 0;
    }
    ll ans = 0;
    if (l <= m) ans += getsum(l, r, s, m, p << 1);
    ans %= mod;
    if (r > m) ans += getsum(l, r, m + 1, t, p << 1 | 1);
    ans %= mod;
    return ans;
}
int main() {
    scanf("%lld %lld %lld", &n, &m, &mod);
    for (int i=1; i<=n; i++) scanf("%lld", &a[i]);
    build(1, n, 1);
    while (m--) {
        ll o, x, y, k;
        scanf("%lld", &o);
        if (o == 1) scanf("%lld %lld %lld", &x, &y, &k), Mult(x, y, 1, n, k, 1);
        else if (o == 2) scanf("%lld %lld %lld", &x, &y, &k), Add(x, y, 1, n, k, 1);
        else if (o == 3) scanf("%lld %lld", &x, &y), printf("%lld\n", getsum(x, y, 1, n, 1));
    }
    return 0;
}