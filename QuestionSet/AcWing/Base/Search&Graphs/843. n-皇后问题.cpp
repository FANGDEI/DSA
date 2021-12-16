/*
 * @Author: FANG
 * @Date: 2021-11-12 22:08:45
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 20;
char g[N][N];
int col[N], dg[N], udg[N];
int n;
void dfs(int x = 0) {
    if (x == n) {
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[x + i] && !udg[n - x + i]) {
            g[x][i] = 'Q';
            col[i] = dg[x + i] = udg[n - x + i] = true;
            dfs(x + 1);
            col[i] = dg[x + i] = udg[n - x + i] = false;
            g[x][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs();
    return 0;
}