/*
 * @Author: FANG
 * @Date: 2021-12-29 23:37:24
 */
#include <iostream>
#include <algorithm>
using namespace std;
struct A {
    int s, f;
    bool operator < (const A &a) {
        return this->f < a.f;
    }
} t[1005];
int main() {
    int n;
    cin >> n; 
    for (int i = 0; i < n; i++) cin >> t[i].s >> t[i].f;
    sort(t, t + n);
    int res = 1, pre = 0;
    for (int i = 1; i < n; i++) {
        if (t[i].s >= t[pre].f) {
            res++;
            pre = i;
        }
    }
    cout << res << endl;
    return 0;
}