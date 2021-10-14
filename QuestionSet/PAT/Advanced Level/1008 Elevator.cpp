/*
 * @Author: FANG
 * @Date: 2021-10-14 20:50:58
 */
#include <iostream>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    int res = 0, tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > tmp) res += 6 * (t - tmp);
        else res += 4 * (tmp - t);
        tmp = t;
    }
    cout << res + n * 5 << endl;
    return 0;
}