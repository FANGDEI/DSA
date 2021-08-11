//P1706 全排列问题
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 10;
bool vis[N];
int n;
vector<int> ans;
void DFS(int n) {
    if (ans.size() == n) {
        for (int i=0; i<n; i++) {
            printf("%5d", ans[i]);
        }
        cout << endl;
        return ;
    }
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            ans.push_back(i);
            vis[i] = true;
            DFS(n);
            ans.pop_back();
            vis[i] = false;
        }
    }
}
int main() {
    cin >> n;
    DFS(n);
    return 0;
}