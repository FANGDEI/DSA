/*
 * @Author: FANG
 * @Date: 2021-10-24 02:21:13
 */
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[100005];
void quickSort(int a[], int l, int r) {
    if (l == r) return ;
    int k = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] < k);
        do j--; while (a[j] > k);
        if (i < j) swap(a[i], a[j]);
    }
    quickSort(a, l, j);
    quickSort(a, j + 1, r);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}