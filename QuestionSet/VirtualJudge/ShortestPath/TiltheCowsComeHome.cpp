/*
 * @Author: FANG
 * @Date: 2021-08-22 23:25:42
 * @LastEditTime: 2021-08-22 23:44:47
 * @Description: https://vjudge.ppsucxtt.cn/problem/POJ-2387
 * @FilePath: \DSA\QuestionSet\VirtualJudge\ShortPath\TiltheCowsComeHome.cpp
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2005;
struct Edge {
    int to;
    int w;
    int next;
} edge[N];
int head[N], cnt, dis[N], t, n;
bool vis[N];
void add(int u, int v, int w) {
    ++cnt;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int main() {
    memset(head, -1, sizeof(head));
    memset(dis, INF, sizeof(dis));
    cin >> t >> n;
    for (int i=1; i<=t; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    // vis[n] = true;
    dis[n] = 0;
    for (int i=1; i<=n; i++) {
        int min_val = INF, x = 0;
        for (int j=1; j<=n; j++) if (!vis[j] and dis[j] < min_val) min_val = dis[j], x = j;
        vis[x] = true;
        for (int k=head[x]; ~k; k=edge[k].next) dis[edge[k].to] = min(dis[edge[k].to], dis[x] + edge[k].w);
    }
    cout << dis[1] << endl;
    return 0;
}