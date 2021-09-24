/*
 * @Author: FANG
 * @Date: 2021-09-24 23:45:26
 */
#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, p;
int main() {
    cin >> a >> b >> p;
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % p;
        b >>= 1;
        a = a * 2 % p;
    }
    cout << res << endl;
    return 0;
}