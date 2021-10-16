/*
 * @Author: FANG
 * @Date: 2021-10-15 23:06:50
 */
#include <iostream>
#include <algorithm>
using namespace std;
int a, b, n, s;
struct node {
    int x, y;
    bool operator < (const node &a) {
        return this->y < a.y;
    }
} c[5005];
int main() {
    cin >> n >> s;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (x <= a + b) {
            c[++cnt].x = x;
            c[cnt].y = y;
        }
    }
    sort(c + 1, c + cnt + 1);
    int res = 0;
    for (int i = 1; i <= cnt; i++) {
        if (s < c[i].y || a + b < c[i].x) break;
        res++;
        s -= c[i].y;
    }
    cout << res << endl;
    return 0;
}