/*
 * @Author: FANG
 * @Date: 2021-08-17 12:43:02
 * @LastEditTime: 2021-08-17 12:58:02
 * @Description: https://vjudge.net/problem/POJ-2524
 * @FilePath: \DSA\QuestionSet\VirtualJudge\Trees\DSU\UbiquitousReligions.cpp
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int fa[50005], cnt;
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
    while (scanf("%d %d", &n, &m) && n && m) {
        memset(fa, 0, sizeof(fa));
        for (int i=1; i<=n; i++) fa[i] = i;
        for (int i=1; i<=m; i++) {
            int x, y;
            cin >> x >> y;
            fa[find(x)] = find(y);
        }
        int ans = 0;
        for (int i=1; i<=n; i++) if (fa[i] == i) ans++;
        printf("Case %d: ", ++cnt);
        cout << ans << endl;
    }
    return 0;
}