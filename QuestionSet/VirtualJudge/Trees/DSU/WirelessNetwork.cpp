/*
 * @Author: FANG
 * @Date: 2021-08-17 16:44:19
 */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Point {
   int x, y;
   int index;
} p[1005];
int repaired[1005], cnt; // The index of the repaired computer and the nums of the repaired computer
int fa[1005];
double getDistance(Point a, Point b) {
   return sqrt(((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) * 1.0);
}
int find(int x) {
   return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
   for (int i = 1; i <= 1005; i++) fa[i] = i;
   int n, d;
   cin >> n >> d;
   for (int i = 1; i <= n; i++) {
      cin >> p[i].x >> p[i].y;
      p[i].index = i;
   }
   char ch;
   while (scanf(" %c", &ch) != EOF) {
      if (ch == 'S') {
         int a, b;
         cin >> a >> b;
         if (find(a) == find(b)) {
            cout << "SUCCESS" << endl;
         } else cout << "FAIL" << endl;
      } else {
         int t;
         cin >> t;
         for (int i = 0; i < cnt; i++) {
            if (getDistance(p[t], p[repaired[i]]) <= d) {
               // fa[t] = fa[repaired[i]];
               fa[find(t)] = find(repaired[i]);
            }
         }
         repaired[cnt++] = p[t].index;
      }
   }
   return 0;
}