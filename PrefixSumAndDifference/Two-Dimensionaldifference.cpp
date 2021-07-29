/*[地毯]https://www.luogu.com.cn/problem/P3397 */
#include <bits/stdc++.h>
using namespace std;
int a[1010][1010], diff[1010][1010];
void insert(int x1, int y1, int x2, int y2, int c) {
    diff[x1][y1] += c;
    diff[x2+1][y1] -= c;
    diff[x1][y2+1] -= c;
    diff[x2+1][y2+1] += c;   
}
int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        insert(x1, y1, x2, y2, 1);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            diff[i][j] = diff[i][j] + diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}