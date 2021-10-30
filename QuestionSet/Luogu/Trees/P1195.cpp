/*
 * @Author: FANG
 * @Date: 2021-10-30 14:36:50
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
int n, m, k, s, cnt, tot;
struct node {
	int x, y, v;
}ka[200001];
int fat[5001];

int read() {
	int s = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

int father(int x) {
	if (fat[x] != x) fat[x] = father(fat[x]);//并查集用
	return fat[x];
}

void unionn(int x, int y) {//并查集用
	int fa = father(x);
	int fb = father(y);
	if (fa != fb) fat[fa] = fb;
}

bool cmp(node a, node b) {//sort用
	return a.v < b.v;
}

int main() {
	n = read(), m = read(), k = read();
	int x, y, d;
	for (int i = 1; i <= m; i++) {
		x = read(), y = read(), d = read();
		ka[++cnt].v = d;
		ka[cnt].x = x;
		ka[cnt].y = y;
	}
	for (int i = 1; i <= n; i++) fat[i] = i;//并查集用
	sort(ka + 1, ka + m + 1, cmp);
	for (int i = 1; i <= m; ++i) {//kruskal
		if (father(ka[i].x) != father(ka[i].y)){
			unionn(ka[i].x, ka[i].y);
			tot += ka[i].v;
			s++;
		}
		if (s == n - k) break;
	}
	printf("%d\n", tot);
}