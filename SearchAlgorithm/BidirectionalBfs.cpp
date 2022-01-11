/*
 * @Author: FANG
 * @Date: 2022-01-09 15:22:05
 */
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 250;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
typedef pair<int, int> PII;
queue<PII> q;
int dis[N][N], vis[N][N], n, m;
char g[N][N];
int main() {
    while (cin >> n >> m && n && m) {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                if (g[i][j] == 'Y') q.push({i, j}), vis[i][j] = 2;
                if (g[i][j] == 'M') q.push({i, j}), vis[i][j] = 1;
            }
        }
        while (!q.empty()) {
            auto k = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = k.first + dx[i], y = k.second + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == vis[k.first][k.second] || g[x][y] == '#') continue;
                if (vis[x][y] == 0) {
                    vis[x][y] = vis[k.first][k.second];
                    dis[x][y] = dis[k.first][k.second] + 1;
                    q.push({x, y});
                } else if (vis[x][y] != vis[k.first][k.second] && g[x][y] == '@') {
                    cout << (dis[x][y] + 1 + dis[k.first][k.second]) * 11 << endl;
                    while (!q.empty()) q.pop();
                    break;
                }
            }
        }
    }
    return 0;
}