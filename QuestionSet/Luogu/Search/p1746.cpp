//P1746 离开中山路
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1005;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
struct node {
    int x, y, step;
    node(){}
    node(int a, int b, int c) {
        x = a, y = b, step = c;
    }
};
char m[N][N]; // 输入有小坑...
int n, sx, sy, fx, fy;
bool vis[N][N];
queue<node> q;
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> m[i][j];
    cin >> sx >> sy >> fx >> fy;
    q.push(node(sx, sy, 0));
    vis[sx][sy] = true;
    while (!q.empty()) {
        node f = q.front();
        q.pop();
        if (f.x == fx and f.y == fy) {
            cout << f.step << endl;
            return 0;
        }
        for (int i=0; i<4; i++) {
            int x = f.x + dx[i], y = f.y + dy[i];
            if (x>0&&x<=n&&y>0&&y<=n&&!vis[x][y]&&m[x][y]!='1') {
                vis[x][y] = true;
                q.push(node(x, y, f.step + 1));
            }
        }
    }
    return 0;
}
