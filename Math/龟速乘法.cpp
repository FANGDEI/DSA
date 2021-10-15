/*
 * @Author: FANG
 * @Date: 2021-10-14 22:23:12
 */
#include <iostream>
using namespace std;
typedef long long ll;
ll p;
ll Mult(ll a, ll b) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % p;
        b >>= 1;
        a = a * 2 % p;
    }
    return res;
}
int main() {
    ll a, b;
    cin >> a >> b >> p;
    cout << Mult(a, b) << endl;
    return 0;
}