#include <iostream>
#include <algorithm>
using namespace std;
int tmp[100];
// O(nlogn)
void Merge(int a[], int s, int m, int e, int tmp[]) {
    /*
        将数组a[s, m], a[m+1, e]合并到tmp中 并保证tmp有序
        最后将tmp拷贝到a[s, e]
        归并时间复杂度：O(e-m+1), O(n)
    */
    int pb = 0;
    int p1 = s, p2 = m + 1;
    while (p1 <= m && p2 <= e) {
        if (a[p1] < a[p2]) tmp[pb++] = a[p1++];
        else tmp[pb++] = a[p2++];
    }
    while (p1 <= m) tmp[pb++] = a[p1++];
    while (p2 <= e) tmp[pb++] = a[p2++];
    for (int i=0; i<e-s+1; i++) a[s+i] = tmp[i];
}

void MergeSort(int a[], int s, int e, int tmp[]) {
    if (s < e) {
        int m = s + (e - s) / 2;
        MergeSort(a, s, m, tmp); // 左半边排序
        MergeSort(a, m+1, e, tmp); // 右半边排序
        Merge(a, s, m, e, tmp); // 归并
    }
}

int main() {
    int a[] = {10,1,35,61,89,36,55,99,76};
    MergeSort(a, 0, 8, tmp);
    for (int i=0; i<9; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}