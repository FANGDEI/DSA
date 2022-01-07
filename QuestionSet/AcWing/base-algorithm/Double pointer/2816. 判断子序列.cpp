/*
 * @Author: FANG
 * @Date: 2021-11-04 12:28:38
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    int a[100005], b[100005];
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    int slow = 1, fast = 1;
    while (slow <= n && fast <= m) {
        if (b[fast] == a[slow]) slow++, fast++;
        else fast++;
    }
    if (slow > n) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}