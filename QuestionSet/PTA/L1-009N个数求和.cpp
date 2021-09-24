/*
 * @Author: FANG
 * @Date: 2021-09-24 20:31:00
 */
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll gcb(ll a, ll b) {
    if (b == 0) return a;
    else return gcb(b, a % b);
}
int main() {
    int n;
    ll fz, fm;
    scanf("%d", &n);
    scanf("%lld/%lld", &fz, &fm);
    int tmp = gcb(fz, fm);
    fz /= tmp, fm /= tmp;
    for (int i=1; i<n; i++) {
        ll z, m;
        scanf("%lld/%lld", &z, &m);
        int lcm = fm / gcb(fm, m) * m;
        fz = fz * lcm / fm + z * lcm / m;
        fm = lcm;
        int t = gcb(fm, fz);
        fm /= t, fz /= t;
    }
    if (fz % fm == 0) printf("%lld", fz / fm);
    else if (fz > fm) printf("%lld %lld/%lld", fz / fm, fz % fm, fm);
    else printf("%lld/%lld", fz, fm);
}