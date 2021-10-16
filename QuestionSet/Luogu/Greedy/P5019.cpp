/*
 * @Author: FANG
 * @Date: 2021-10-16 17:25:57
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
int a[N], n, min_val, min_index, res;
void sub(int head, int tail) {
    min_val = 0x3f3f3f3f;
    for (int i = head; i <= tail; i++) {
        if (min_val > a[i]) min_val = a[i], min_index = i;
    }
    for (int i = head; i <= tail; i++) {
        a[i] -= min_val;
    }
    res += min_val;
}
void dfs(int head, int tail) {
    if (head > tail) return ;
    sub(head, tail);
    dfs(head, min_index - 1);
    dfs(min_index + 1, tail);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, n);
    cout << res << endl;
    return 0;
}