//P3373 【模板】线段树 2 30
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll n, m, mod;
ll a[N], add[N << 2], mul[N << 2], d[N << 2];
ll read() {
  ll w = 1, q = 0;
  char ch = ' ';
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') q = (ll)q * 10 + ch - '0', ch = getchar();
  return (ll)w * q;
}
void up(ll p) {
    d[p] = (d[p << 1] + d[p << 1 | 1]) % mod;
}
void pushdown(ll i, ll s, ll t) {
    ll m = (s + t) >> 1, l = (i << 1), r = (i << 1) | 1;
    if (mul[i] != 1) {
        mul[l] *= mul[i];
        mul[l] %= mod;
        mul[r] *= mul[i];
        mul[r] %= mod;
        add[l] *= mul[i];
        add[l] %= mod;
        add[r] *= mul[i];
        add[r] %= mod;
        d[l] *= mul[i];
        d[l] %= mod;
        d[r] *= mul[i];
        d[r] %= mod;
        mul[i] = 1;
    }
    if (add[i]) {
        d[l] += add[i] * (m - s + 1);
        d[l] %= mod;
        d[r] += add[i] * (t - m);
        d[r] %= mod;
        add[l] += add[i];
        add[l] %= mod;
        add[r] += add[i];
        add[r] %= mod;
        add[i] = 0;
    }
}
void build(ll l, ll r, ll p) {
    mul[p] = 1;
    if (l == r) {
        d[p] = a[l];
        return ;
    }
    ll m = l + ((r - l) >> 1);
    build(l, m, p << 1);
    build(m + 1, r, p << 1 | 1);
    up(p);
}
void Add(ll l, ll r, ll s, ll t, ll c, ll p) {
    ll m = s + ((t - s) >> 1);
    if (l <= s && t <= r) {
        d[p] += (t - s + 1) * c;
        d[p] %= mod;
        add[p] += c;
        add[p] %= mod;
        return ;
    }
    pushdown(p, s, t);
    if (l <= m) Add(l, r, s, m, c, p << 1);
    if (m + 1 <= r) Add(l, r, m + 1, t, c, p << 1 | 1);
    up(p);
}
void Mult(ll l, ll r, ll s, ll t, ll c, ll p) {
    ll m = s + ((t - s) >> 1);
    if (l <= s && t <= r) {
        mul[p] *= c;
        mul[p] %= mod;
        add[p] *= c;
        add[p] %= mod;
        d[p] *= c;
        d[p] %= mod;
        return ;
    }
    pushdown(p, s, t);
    if (l <= m) Mult(l, r, s, m, c, p << 1);
    if (m + 1 <= r) Mult(l, r, m + 1, r, c, p << 1 | 1);
    up(p);
}
ll getsum(ll l, ll r, ll s, ll t, ll p) {
    if (l <= s && t <= r) return d[p];
    ll m = s + ((t - s) >> 1);
    pushdown(p, s, t);
    ll ans = 0;
    if (l <= m) ans += getsum(l, r, s, m, p << 1);
    ans %= mod;
    if (m + 1 <= r) ans += getsum(l, r, m + 1, t, p << 1 | 1);
    return ans % mod;
}
int main() {
    int i, j, x, y, bh;
    ll z;
    n = read();
    m = read();
    mod = read();
    for (int i=1; i<=n; i++) a[i] = read();
    build(1, n, 1);
    for (int i=1; i<=m; i++) {
        bh = read();
        if (bh == 1) {
            x = read();
            y = read();
            z = read();
            Mult(x, y, 1, n, z, 1);
        } else if (bh == 2) {
            x = read();
            y = read();
            z = read();
            Add(x, y, 1, n, z, 1);
        } else if (bh == 3) {
            x = read();
            y = read();
            printf("%lld\n", getsum(x, y, 1, n, 1));
        }
    }
    return 0;
}