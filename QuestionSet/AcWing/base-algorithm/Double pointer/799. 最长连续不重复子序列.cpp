/*
 * @Author: FANG
 * @Date: 2021-11-04 12:28:14
 */
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int n, a[100005], s[100005];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        s[a[i]]++;
        while (j <= i && s[a[i]] > 1) {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}