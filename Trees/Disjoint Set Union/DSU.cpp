#include <iostream>
#include <algorithm>
using namespace std;
#define MAXSIZE 100
int fa[MAXSIZE];
void initSet(int size) {
    for (int i=0; i<size; i++) fa[i] = i;
}
int find(int x) {
    if (fa[x] == x) return x;
    else return find(fa[x]);
}
int Find(int x) { // 路径压缩
    // return fa[x] == x ? x : (fa[x] = Find(fa[x]));
    if (fa[x] == x) return x;
    else {
        fa[x] = Find(fa[x]);
        return fa[x];
    }
}
void unionSet(int x, int y) {
    x = Find(x);
    y = Find(y);
    fa[x] = y;
}
int main() {

    return 0;
}