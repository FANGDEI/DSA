/*
 * @Author: FANG
 * @Date: 2021-11-03 22:08:58
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int n, a[125][125], s[125][125];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    int res = -0x3f3f3f3f;
    for (int x1 = 1; x1 <= n; x1++)
        for (int y1 = 1; y1 <= n; y1++)
            for (int x2 = 1; x2 <= n; x2++)
                for (int y2 = 1; y2 <= n; y2++) 
                    if (x1 > x2 || y1 > y2) continue;
                    else res = max(res, s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
    cout << res << endl; 
    return 0;
}