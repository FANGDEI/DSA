//P3374 【模板】树状数组 1
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 500005;
int n, m;
int sum[N];
int lowbit(int x) {
    return x & -x;
}
void update(int i, int k) {
    while (i <= n) {
        sum[i] += k;
        i += lowbit(i);
    }
}
int ask(int i) {
    int ans = 0;
    while (i > 0) {
        ans += sum[i];
        i -= lowbit(i);
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        update(i, k);
    }
    while (m--) {
        int o, x, y;
        cin >> o >> x >> y;
        if (o == 1) update(x, y);
        else if (o == 2) cout << ask(y) - ask(x - 1) << endl;
    }
    return 0;
}