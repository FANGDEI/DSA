/*
 * @Author: FANG
 * @Date: 2021-10-13 22:37:30
 */
#include <iostream>
using namespace std;
const int N = 20;
long long f[N][N]; // [x][y] x : The nums of the queue  y: The nums of the stack
int n;
long long dfs(int x, int y) {
    if (f[x][y]) return f[x][y];
    if (x == 0) return 1;
    if (y > 0) f[x][y] += dfs(x, y - 1);
    f[x][y] +=dfs(x - 1, y + 1);
    return f[x][y];
}
int main() {
    cin >> n;
    cout << dfs(n, 0) << endl;
    return 0;
}