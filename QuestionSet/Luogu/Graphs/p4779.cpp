//P4779 【模板】单源最短路径（标准版）
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define INF 0x3f
const int N = 1e5 + 5;
const int M = 2 * 1e5 + 5;
int n, m, s;
struct Edge {
    /* data */
    int to;
    int w;
    int next;
} edge[M];
int head[N], dis[N], cnt;
bool vis[N];
priority_queue<pair<int, int> > q;
void add(int u, int v, int w) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    memset(dis, INF, sizeof(dis));
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (int i=head[x]; ~i; i=edge[i].next) {
            if (dis[edge[i].to] > dis[x] + edge[i].w) dis[edge[i].to] = dis[x] + edge[i].w,
            q.push(make_pair(-dis[edge[i].to], edge[i].to));
        }
    }
    for (int i=1; i<=n; i++) cout << dis[i] << " ";
    cout << endl;
    return 0;
}