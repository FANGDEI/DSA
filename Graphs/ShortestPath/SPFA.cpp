#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
struct Edge {
    int to;
    double w;
    int next;
} edge[1005 * 2];
struct Point {
    int x, y;
} point[1005 * 2];
int head[105 * 2], cnt;
queue<int> q;
int n, m;
void add(int u, int v, double w) {
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
double dis[105];
bool vis[105];
int main() {
    memset(head, -1, sizeof(head));
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        point[i].x = x, point[i].y = y;
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        double w = sqrt((point[u].x - point[v].x) * (point[u].x - point[v].x) + 
        (point[u].y - point[v].y) * (point[u].y - point[v].y));
        add(u, v, w);
        add(v, u, w);
    }
    int s, t;
    cin >> s >> t;
    for (int i=1; i<=n; i++) dis[i] = 0x3f3f3f3f + 0.1;
    dis[s] = 0;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = false;
        for (int i=head[x]; ~i; i=edge[i].next) {
            if (dis[edge[i].to] > dis[x] + edge[i].w) {
                dis[edge[i].to] = dis[x] + edge[i].w;
                if (!vis[edge[i].to]) {
                    q.push(edge[i].to);
                    vis[edge[i].to] = true;
                }
            }
        }
    }
    printf("%.2lf", dis[t]);
    return 0;
}