//P1162 填涂颜色
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 35;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int a[N][N], b[N][N], n;
void dfs(int x, int y) {
    if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || a[x][y] != 0) return ;
    a[x][y] = 1;
    for (int i=0; i<4; i++) dfs(x + dx[i], y + dy[i]);
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> b[i][j];
            if (b[i][j] == 0) a[i][j] = 0;
            else a[i][j] = 2;
        }
    }
    dfs(0, 0);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j] == 0) cout << "2" << " ";
            else cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}