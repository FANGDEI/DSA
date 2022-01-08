/*
 * @Author: FANG
 * @Date: 2021-12-27 00:48:22
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int n, m, vis[1005][1005];
char g[1005][1005];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct node {
    int x, y;
};
void bfs(int sx, int sy) {
    queue<node> q;
    int res = 1;
    vis[sx][sy] = 1;
    q.push({sx, sy});
    while (!q.empty()) {
        node f = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = f.x + dx[i], y = f.y + dy[i];
            if (x > 0 && x <= n && y > 0 && y <= n && vis[x][y] == 0 && g[x][y] != g[f.x][f.y]) {
                vis[x][y] = 1;
                q.push({x, y});
                res++;
            }
        }
    }
    cout << res << endl;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%s", g[i]);
    while (m--) {
        for (int i = 0; i < 1005; i++)
            for (int j = 0; j < 1005; j++) 
                vis[i][j] = 0;
        int sx, sy;
        scanf("%d %d", &sx, &sy);
        bfs(sx, sy);
    }
    return 0;
}