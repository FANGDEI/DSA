//P2212 [USACO14MAR]Watering the Fields S
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2005;
int n, c;
struct Edge {
    int u, v, w;
    bool operator < (const Edge x) {
        return this->w < x.w;
    }
} edge[N * (N - 1)];
struct Point {
    int x, y;
} p[N];
int fa[N];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
    cin >> n >> c;
    for (int i=1; i<=n; i++) cin >> p[i].x >> p[i].y;
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int cost = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
            if (i != j && cost >= c) {
                ++cnt;
                edge[cnt].u = i;
                edge[cnt].v = j;
                edge[cnt].w = cost;
            }
        }
    }
    sort(edge + 1, edge + cnt + 1);
    int r = 0, ans = 0;
    for (int i=1; i<=n; i++) fa[i] = i;
    for (int i=1; i<=cnt; i++) {
        if (find(edge[i].u) != find(edge[i].v)) {
            r++;
            fa[find(edge[i].u)] = find(edge[i].v);
            ans += edge[i].w;
        }
        if (r == n - 1) break;
    }
    if (r == n - 1) cout << ans << endl;
    else puts("-1");
    return 0;
}