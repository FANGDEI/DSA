/*
 * @Author: FANG
 * @Date: 2021-08-01 09:07:27
 */
#include <iostream>

using namespace std;
int n, k, res;
void dfs(int a, int b, int c) {
    if (b == 1) {
        res++;
        return ;
    }
    for (int i = c; i <= a / b; i++) {
        dfs(a - i, b - 1, i);
    }
}
int main() {
    cin >> n >> k;
    dfs(n, k, 1);
    cout << res << endl;
    return 0;
}