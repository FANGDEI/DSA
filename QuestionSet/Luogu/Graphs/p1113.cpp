//P1113 杂务
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e4 + 5;
const int M = N * N;
struct Edge {
    int to;
    int next;
} edge[M];
int n, times[N], head[N], cnt, inDeg[N], dp[N];
queue<int> q;
int main() {
    memset(head, -1, sizeof(head));
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x;
        cin >> times[i];
        while (cin >> y && y != 0) {
            edge[++cnt].to = x;
            edge[cnt].next = head[y];
            head[y] = cnt;
            inDeg[x]++;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!inDeg[i]) {
            q.push(i);
            dp[i] = times[i];
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i=head[now]; ~i; i=edge[i].next) {
            if (--inDeg[edge[i].to] == 0) q.push(edge[i].to);
            dp[edge[i].to] = max(dp[edge[i].to], dp[now] + times[edge[i].to]);
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}