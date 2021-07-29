//公路维修问题
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m;
ll p[15005], diff[15005];
bool cmp(const ll x, const ll y) {
    return x > y;
}
int main() {
    cin >> n >> m;
    int i;
    for (i=0; i<n; i++) {
        cin >> p[i];
        if (i) diff[i-1] = p[i] - p[i-1];
    }
    sort(diff, diff+n-1, cmp);
    ll dis = p[i-1] - p[0] + 1;
    for (int i=0; i<m-1; i++) {
        dis = dis - diff[i] + 1;
    }
    cout << dis << endl;
    return 0;
}