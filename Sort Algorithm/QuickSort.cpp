#include <iostream>
#include <algorithm>
using namespace std;

void QuickSort(int a[], int s, int e) {
    if (s >= e) return ;
    int k = a[s];
    int i = s, j = e;
    while (i != j) {
        while (j > i && a[j] >= k) j--;
        swap(a[i], a[j]);
        while (i < j && a[i] <= k) i++;
        swap(a[i], a[j]);
    }// 结束后a[i] = k;
    QuickSort(a, s, i - 1);
    QuickSort(a, i + 1, e);
}

int main() {
    int a[] = {10,1,35,61,89,36,55,99,76};
    QuickSort(a, 0, 8);
    for (int i=0; i<9; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}