/*
 * @Author: FANG
 * @Date: 2021-09-27 20:09:28
 * 22
 */
#include <iostream>
using namespace std;
int n, a[10005];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int this_sum = 0, max_sum = 0;
    int l = 0, r = 0, t = 0;
    for (int i = 0; i < n; i++) {
        this_sum += a[i];
        if (this_sum > max_sum) {
            max_sum = this_sum;
            r = i;
            l = t;
        }
        if (this_sum < 0) {
            this_sum = 0;
            t = i + 1;
        }
    }
    if (max_sum == 0) cout << max_sum << " " << a[0] << " " << a[n - 1] << endl;
    else cout << max_sum << " " << a[l] << " " << a[r] << endl;
    return 0;
}