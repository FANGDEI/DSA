/*
 * @Author: FANG
 * @Date: 2021-10-16 20:31:42
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
struct node {
    int s, e, v;
    bool operator < (const node &a) {
        return this->e < a.e;
    }
} a[30005];
bool vis[30005];
int n, h, res;
int main() {
    cin >> n >> h;
    for (int i = 1; i <= h; i++) {
        cin >> a[i].s >> a[i].e >> a[i].v;
    }
    sort(a + 1, a + h + 1);
    for (int i = 1; i <= h; i++) {
        int k = 0;
        for (int j = a[i].s; j <= a[i].e; j++) {
            if (vis[j]) k++;
        }
        if (k >= a[i].v) continue;
        for (int j = a[i].e; j >= a[i].s; j--) {
            if (vis[j] == false) {
                vis[j] = true;
                res++;
                k++;
                if (k == a[i].v) break;
            }
        }
    }
    cout << res << endl;
    return 0;
}