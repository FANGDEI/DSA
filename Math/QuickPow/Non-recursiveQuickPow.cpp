#include <iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll quickPow(ll a, ll b) {
    ll ans = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
ll a, b;
int main() {
    cin >> a >> b;
    cout << quickPow(a, b) << endl;
    return 0;
}