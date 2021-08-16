/*
 * @Author: FANG
 * @Date: 2021-08-16 15:31:43
 * @LastEditTime: 2021-08-16 15:51:19
 * @Description: https://vjudge.ppsucxtt.cn/problem/POJ-1321
 * @FilePath: \DSA\QuestionSet\VirtualJudge\Search\棋盘问题.cpp
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n, k, ans;
char map[10][10];
bool vis[10];
void dfs(int x, int num) {
    if (num == k) {
        ans++;
        return ;
    }
    if (x > n) return ;
    for (int i=1; i<=n; i++) {
        if (map[x][i] == '#' && vis[i] == 0) {
            vis[i] = true;
            dfs(x+1, num+1);
            vis[i] = false;
        }
    }
    dfs(x+1, num);
}
int main() {
    while (~scanf("%d %d", &n, &k) && ~n && ~k) {
        memset(vis, 0, sizeof(vis));
        memset(map, 0, sizeof(map));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cin >> map[i][j];
            }
        }
        ans = 0;
        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}