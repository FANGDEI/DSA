//P3817 å°Açç³æ
#include <iostream>
using namespace std;
typedef long long ll;
ll n, x, a[100005];
int main() {
    cin >> n >> x;
    ll ans = 0;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<n; i++) {
        if (a[i] + a[i+1] > x) {
            ans += a[i] + a[i+1] - x;
            a[i+1] = x - a[i];
        }
    }
    cout << ans << endl;
    return 0;
}