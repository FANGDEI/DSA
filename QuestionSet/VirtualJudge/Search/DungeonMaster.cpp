/*
 * @Author: FANG
 * @Date: 2021-08-23 12:45:49
 * @LastEditTime: 2021-08-23 16:24:21
 * @Description: https://vjudge.ppsucxtt.cn/problem/POJ-2251
 * @FilePath: \DSA\QuestionSet\VirtualJudge\Search\DungeonMaster.cpp
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 35;
char g[N][N][N];
int l, r, c, dis[N][N][N];
queue<int> q;
int dx[] = {0, 0, 0, 0, 1, -1},
    dy[] = {-1, 1, 0, 0, 0, 0},
    dz[] = {0, 0, -1, 1, 0, 0};
int bfs() {
    while (q.size()) {
        int x, y, z;
        x = q.front();q.pop();
        y = q.front();q.pop();
        z = q.front();q.pop();
        g[x][y][z] = '#';
        for (int i=0; i<6; i++) {
            int px = x + dx[i], py = y + dy[i], pz = z + dz[i];
            if (px < 0 || py < 0 || pz < 0 || px >= l || py >= r || pz >= c) continue;
            if (g[px][py][pz] == '#') continue;
            dis[px][py][pz] = dis[x][y][z] + 1;
            if (g[px][py][pz] == 'E') return dis[px][py][pz];
            g[px][py][pz] = '#';
            q.push(px), q.push(py), q.push(pz);
        }
    }
    return -1;
}
int main() {
    while (cin >> l >> r >> c and l and r and c) {
        while (q.size()) q.pop();
        for (int i=0; i<l; i++) {
            for (int j=0; j<r; j++) {
                scanf("%s", g[i][j]);
            }
        }
        for (int i=0; i<l; i++) {
            for (int j=0; j<r; j++) {
                for (int k=0; k<c; k++) {
                    if (g[i][j][k] == 'S') {
                        q.push(i), q.push(j), q.push(k);
                        dis[i][j][k] = 0;
                        // g[i][j][k] = '#';
                        break;
                    }
                }
            }
        }
        int res = bfs();
        if (res != -1) cout << "Escaped in "<< res << " minute(s)." << endl;
        else cout << "Trapped!" << endl;
    }
    return 0;
}