/*
 * @Author: FANG
 * @Date: 2021-11-04 12:43:19
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 100005;
int a[N], b[N], x;
int main() {
    int n, m;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];
    for (int i = 0, j = m - 1; i < n; i++) {
        while (j >= 0 && a[i] + b[j] > x) j--;
        if (j >= 0 && a[i] + b[j] == x) cout << i << " " << j << endl;
    }
    return 0;
}