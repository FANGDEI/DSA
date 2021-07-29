/*
    两个数除以一个数的余数相同，那么两数之差除以这个数的余数为零。
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[50000+5], f[10];
int main() {
    // std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        int t;
        scanf("%d", &t);
        a[i] = a[i-1] + t;
        a[i] %= 7;
    }
    int maxlength = 0;
    for (int i=1; i<=n; i++) {
        if (!f[a[i]]) f[a[i]] = i;
        else maxlength = max(maxlength, i-f[a[i]]);
    }
    printf("%d\n", maxlength);
    return 0;
}