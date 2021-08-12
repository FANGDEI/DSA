//P1605 迷宫
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 6;
int Map[M][M];
bool vis[M][M];
int n, m, t, ans;
int sx, sy, fx, fy;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};
void DFS(int x, int y) {
    if (x < 1 || x > n) return ;
    if (y < 1 || y > m) return ;
    if (x == fx and y == fy) {
        ans++;
        return ;
    }
    for (int i=0; i<4; i++) {
        if (Map[x + dx[i]][y + dy[i]] and !vis[x + dx[i]][y + dy[i]]) {
            vis[x][y] = true;
            DFS(x + dx[i], y + dy[i]);
            vis[x][y] = false;
        }
    }
}
int main() {
    cin >> n >> m >> t;
    // memset(Map, 1, sizeof(Map));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            Map[i][j] = 1;
        }
    }
    cin >> sx >> sy >> fx >> fy;
    while (t--) {
        int x, y;
        cin >> x >> y;
        Map[x][y] = 0;
    }
    DFS(sx, sy);
    cout << ans << endl;
    return 0;
}