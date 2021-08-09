//P2504 [HAOI2006]聪明的猴子
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e6 + 5;
// const int M = 505;
int n, m;
int a[N];
struct Point {
    int x, y;
} point[N];
struct Edge {
    int u, v;
    double w;
    bool operator < (const Edge &x) {
        return this->w < x.w;
    }
} edge[N << 2];
int fa[N];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
    cin >> m;
    for (int i=1; i<=m; i++) cin >> a[i];
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> point[i].x >> point[i].y;
    }
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i != j) {
                edge[++cnt].u = i;
                edge[cnt].v = j;
                edge[cnt].w = sqrt(pow(point[i].x - point[j].x, 2) + pow(point[i].y - point[j].y, 2));
            }
        }
    }
    long long r = 0;
    double ans = 0;
    for (int i=1; i<=cnt; i++) fa[i] = i;
    sort(edge + 1, edge + cnt + 1);
    for (int i=1; i<=cnt; i++) {
        if (find(edge[i].u) != find(edge[i].v)) {
            fa[find(edge[i].u)] = find(edge[i].v);
            r++;
            ans = edge[i].w;
        }
        if (n == r - 1) break;
    }
    int res = 0;
    for (int i=1; i<=m; i++) {
        if (a[i] >= ans) res++;
    }
    cout << res << endl;
    return 0;
}