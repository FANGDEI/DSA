/*
 * @Author: FANG
 * @Date: 2021-10-24 02:21:38
 */
#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
int a[100005];
int quickSort(int *a, int l, int r, int m) {
    if (l == r) return a[l];
    int k = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] < k);
        do j--; while (a[j] > k);
        if (i < j) swap(a[i], a[j]);
    }
    int s = j - l + 1;
    if (m <= s) quickSort(a, l, j, m);
    else quickSort(a, j + 1, r, m - s);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int res = quickSort(a, 0, n - 1, m);
    printf("%d", res);
    return 0;
}