//P4047 [JSOI2010]部落划分
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cmath>
using namespace std;
const int N = 1e3 + 5;
struct Edge {
    int u, v;
    double w;
    bool operator < (const Edge x) {
        return this->w < x.w;
    }
} edge[N * (N - 1)];
struct Point {
    int x, y;
} point[N];
int n, k, fa[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> point[i].x >> point[i].y;
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (j != i) {
                edge[++cnt].u = i;
                edge[cnt].v = j;
                edge[cnt].w = sqrt(pow(point[i].x - point[j].x, 2) + pow(point[i].y - point[j].y, 2));
            }
        }
    }
    sort(edge + 1, edge + cnt + 1);
    for (int i=1; i<=n; i++) fa[i] = i;
    bool flag = false;
    // double ans;
    int r = 0;
    for (int i=1; i<=cnt; i++) {
        if (r == n - k) flag = true;
        if (find(edge[i].u) != find(edge[i].v)) {
            fa[find(edge[i].u)] = find(edge[i].v);
            r++;
            // ans += edge[i].w;
            if (flag == true) {
                printf("%.2lf", edge[i].w);
                return 0;
            }
        }
    }
    return 0;
}