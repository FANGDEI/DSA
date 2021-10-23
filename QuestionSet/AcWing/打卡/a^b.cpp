/*
 * @Author: FANG
 * @Date: 2021-09-24 23:59:01
 */
#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, p;
ll quickPow(ll a, ll b) {
    ll res = 1;
    // a %= p;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}
int main() {
    cin >> a >> b >> p;
    cout << quickPow(a, b) << endl;
    return 0;
}