//P1135 奇怪的电梯
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 205;
int n, a, b, ans = 0x3f3f3f3f;
int k[N];
bool vis[N];
void DFS(int now, int tot) {
    if (now == b) ans = min(ans, tot);
    if (tot > ans) return ;
    vis[now] = true;
    if (now + k[now] <= n and !vis[now + k[now]]) DFS(now + k[now], tot + 1);
    if (now - k[now] >= 1 and !vis[now - k[now]]) DFS(now - k[now], tot + 1);
    vis[now] = false;
}
int main() {
    cin >> n >> a >> b;
    for (int i=1; i<=n; i++) cin >> k[i];
    vis[a] = true;
    DFS(a, 0);
    // cout << ans << endl; 
    if (ans != 0x3f3f3f3f) cout << ans << endl;
    else puts("-1");
    return 0;
}