#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int N = 1e4 + 5;
const int M = 500005;
int n, m, s, cnt;
bool vis[N];
int head[N], dis[N];
struct Edge {
    int to;
    int w;
    int next;
} edge[M];
void add(int u, int v, int w) {
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
priority_queue<pair<int, int> > q;
//priority_queue<pair<dis[x], x> >
int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    for (int i=1; i<=n; i++) dis[i] = INF;
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue; //懒惰删除
        vis[x] = true;
        for (int i=head[x]; ~i; i=edge[i].next) {
            if (dis[edge[i].to] > dis[x] + edge[i].w) {
                dis[edge[i].to] = dis[x] + edge[i].w;
                q.push(make_pair(-dis[edge[i].to], edge[i].to)); //priority_queue默认大根堆
            }
        }
    }
    for (int i=1; i<=n; i++) if (dis[i] != INF) cout << dis[i] << " "; else cout << 0x7fffffff << " ";
    cout << endl;
    return 0;
}