/*
 * @Author: FANG
 * @Date: 2021-10-24 12:37:26
 */
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll res;
int n;
int a[100005], tmp[100005];
void merge(int *a, int s, int m, int e) {
    int pb = 0;
    int p1 = s, p2 = m + 1;
    while (p1 <= m && p2 <= e) {
        if (a[p1] <= a[p2]) tmp[pb++] = a[p1++];
        else {
            res += m - p1 + 1;
            tmp[pb++] = a[p2++];
        }
    }
    while (p1 <= m) tmp[pb++] = a[p1++];
    while (p2 <= e) tmp[pb++] = a[p2++];
    for (int i = 0; i < e - s + 1; i++) {
        a[s + i] = tmp[i];
    }
}
void mergeSort(int *a, int s, int e) {
    if (s < e) {
        int m = s + e >> 1;
        mergeSort(a, s, m);
        mergeSort(a, m + 1, e);
        merge(a, s, m, e);
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, 0, n - 1);
    cout << res << endl;
    return 0;
}