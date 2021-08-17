/*
 * @Author: FANG
 * @Date: 2021-08-17 12:34:18
 * @LastEditTime: 2021-08-17 12:39:28
 * @Description: https://vjudge.net/problem/HDU-1213
 * @FilePath: \DSA\QuestionSet\VirtualJudge\Trees\HowManyTable.cpp
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int n, m;
int T, fa[1005];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) fa[i] = i;
        for (int i=1; i<=m; i++) {
            int x, y;
            cin >> x >> y;
            fa[find(x)] = find(y);
        }
        set<int> s;
        for (int i=1; i<=n; i++) s.insert(find(i));
        cout << s.size() << endl;
        s.clear();
    }
    return 0;
}