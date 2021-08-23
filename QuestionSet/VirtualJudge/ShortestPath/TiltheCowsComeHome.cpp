/*
 * @Author: FANG
 * @Date: 2021-08-22 23:25:42
 * @LastEditTime: 2021-08-23 12:43:59
 * @Description: https://vjudge.ppsucxtt.cn/problem/POJ-2387
 * @FilePath: \DSA\QuestionSet\VirtualJudge\ShortestPath\TiltheCowsComeHome.cpp
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 5;
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
priority_queue<pair<int, int> > q;
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
    q.push(make_pair(0, n));
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (int i=head[x]; ~i; i=edge[i].next) {
            if (dis[edge[i].to] > dis[x] + edge[i].w) {
                dis[edge[i].to] = dis[x] + edge[i].w;
                q.push(make_pair(-dis[edge[i].to], edge[i].to));
            }
        }
    }
    cout << dis[1] << endl;
    return 0;
}