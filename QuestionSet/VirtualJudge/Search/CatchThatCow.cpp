/*
 * @Author: FANG
 * @Date: 2021-08-22 21:55:46
 * @LastEditTime: 2021-08-22 22:24:30
 * @Description: https://vjudge.ppsucxtt.cn/problem/POJ-3278
 * @FilePath: \DSA\QuestionSet\VirtualJudge\Search\CatchThatCow.cpp
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
int dis[N], s, e;
queue<int> q;
int main() {
    cin >> s >> e;
    q.push(s);
    vis[s] = true;
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x == e) {
            cout << dis[x] << endl;
            return 0;
        }
        if (x - 1 >= 0 and x - 1 <= 100000 and !vis[x - 1]) q.push(x - 1), vis[x - 1] = true, dis[x - 1] = dis[x] + 1;
        if (x + 1 >= 0 and x + 1 <= 100000 and !vis[x + 1]) q.push(x + 1), vis[x + 1] = true, dis[x + 1] = dis[x] + 1;
        if (x << 1 >= 0 and x << 1 <= 100000 and !vis[x << 1]) q.push(x << 1), vis[x << 1] = true, dis[x << 1] = dis[x] + 1;
    }
    return 0;
}