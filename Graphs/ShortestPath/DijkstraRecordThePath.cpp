/*
 * @Author: FANG
 * @Date: 2021-10-29 22:36:44
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> path(505, -1); // path用来记录此点的前一个节点
const int N = 505;
struct Edge {
    int to;
    int w;
    int next;
} edge[N * N];
bool vis[N];
int head[N], cnt, nums[N], group[N], dis[N], w[N];
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
    path.push_back(s);
    for (int i = 0; i < n; i++) {
        int min_val = INF, x = 0;
        for (int j = 0; j < n; j++) if (dis[j] < min_val && vis[j] == false) min_val = dis[j], x = j;
        vis[x] = true;
        for (int k = head[x]; ~k; k = edge[k].next) {
            if (dis[edge[k].to] > dis[x] + edge[k].w) {
                dis[edge[k].to] = dis[x] + edge[k].w;
                nums[edge[k].to] = nums[x];
                w[edge[k].to] = w[x] + group[edge[k].to];
                path[edge[k].to] = x;
            } else if (dis[edge[k].to] == dis[x] + edge[k].w) {
                nums[edge[k].to] += nums[x];
                if (w[edge[k].to] < w[x] + group[edge[k].to]) {
                    w[edge[k].to] = w[x] + group[edge[k].to];
                    path[edge[k].to] = x;
                }
            }
        }
    }
    cout << nums[e] << " " << w[e] << endl;
	stack<int> res;
    int p = e;
	res.push(e);
	while (path[p] != -1) {
		res.push(path[p]);
		p = path[p];
	}
    while (!res.empty()) { // path记录的路径是逆序，用栈反向输出
		cout << res.top() << " ";
		res.pop();
		if (res.size() == 1) break;
	}
	cout << res.top() << endl;
    return 0;
}