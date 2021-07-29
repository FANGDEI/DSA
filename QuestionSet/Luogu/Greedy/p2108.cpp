//混合牛奶 Mixing Milk
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
struct Milk{
    int price, max;
    bool operator<(const Milk x) {
        return this->price < x.price;
    }
} a[2000005];
int main() {
    cin >> m >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].price >> a[i].max;
    }
    sort(a, a+n);
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (m >= a[i].max) {
            ans += a[i].price * a[i].max;
            m -= a[i].max;
        } else if (m < a[i].max) {
            ans += m * a[i].price;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}