/*
 * @Author: FANG
 * @Date: 2021-10-28 23:42:53
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    int a[100005];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (m--) {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if (a[l] != x) cout << "-1 -1" << endl;
        else {
            cout << l << " ";
            l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r + 1>> 1;
                if (a[mid] <= x) l = mid;
                else r = mid - 1;
            }
            cout << r << endl;
        }
    }
    return 0;
}