/*
 * @Author: FANG
 * @Date: 2021-12-29 23:37:06
 */
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int l, r;
    int t;
    bool operator < (const node &x) const {
        return this->r < x.r;
    }
} p[5005];
bool is[30005];
int main() {
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < h; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        p[i] = {l, r, t};
    }
    sort(p, p + h);
    int res = 0;
    for (int i = 0; i < h; i++) {
        int cnt = 0;
        for (int j = p[i].l; j <= p[i].r; j++) {
            if (is[j] == true) cnt++;
        }
        for (int j = p[i].r; j >= p[i].l; j--) {
            if (cnt >= p[i].t) break;
            if (is[j] == false) {
                is[j] = true;
                cnt++, res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}