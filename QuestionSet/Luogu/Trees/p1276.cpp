//P1276 校门外的树（增强版）
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[10005];
int l, n, ans, res;
int main() {
    cin >> l >> n;
    memset(a, 1, sizeof(a));
    while (n--) {
        int o, x, y;
        cin >> o >> x >> y;
        if (o == 0) {
            for (int j=x; j<=y; j++) {
                if (a[j] == 2) ans++;
                a[j] = 0;
            }
        } else {
            for (int j=x; j<=y; j++) if (a[j] == 0) a[j] = 2;
        }
    }
    for (int i=0; i<=l; i++) if (a[i] == 2) res++;
    cout << res << endl << ans << endl;
    return 0;
}