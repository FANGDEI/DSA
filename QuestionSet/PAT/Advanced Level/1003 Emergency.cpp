/*
 * @Author: FANG
 * @Date: 2021-09-27 09:20:42
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int INF = 0x3f3f3f3f;
struct Edge {
    int to;
    int w;
    int next;
} edge[N * N];
bool vis[N];
int head[N], cnt, group[N], dis[N], nums[N], w[N];
int n, m, s, e;
void add(int u, int v, int w) {
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int main() {
    memset(head, -1, sizeof(head));
    memset(dis, INF, sizeof(dis));
    memset(vis, false, sizeof(vis));
    cin >> n >> m >> s >> e;
    for (int i = 0; i < n; i++) cin >> group[i];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dis[s] = 0;
    nums[s] = 1;
    w[s] = group[s];
    for (int i = 0; i < n; i++) {
        int min_val = INF, x;
        for (int j = 0; j < n; j++) if (dis[j] < min_val && !vis[j]) min_val = dis[j], x = j;
        if (min_val == INF) break;
        vis[x] = true;
        for (int k = head[x]; ~k; k = edge[k].next) {
            int v = edge[k].to;
            if (dis[edge[k].to] > dis[x] + edge[k].w) {
                dis[edge[k].to] = dis[x] + edge[k].w;
                nums[edge[k].to] = nums[x];
                w[edge[k].to] = w[x] + group[edge[k].to];
            } else if (dis[edge[k].to] == dis[x] + edge[k].w) {
                nums[edge[k].to] += nums[x];
                if (w[x] + group[edge[k].to] > w[edge[k].to]) {
                    w[edge[k].to] = w[x] + group[edge[k].to];
                } 
            }
        }
    }
    cout << nums[e] << " " << w[e] << endl;
    return 0;
}