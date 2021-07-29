#include <iostream>
#include <algorithm>
using namespace std;
// O(nlog2n)
int main() {
    int a[] = {10,1,35,61,89,36,55,99,76};
    int i, j, gap;
    for (gap = 9 / 2; gap > 0; gap /= 2) {
        for (i = 0; i < gap; i++) {
            for (j = i + gap; j < 9; j += gap) {
                if (a[j] < a[j-gap]) {
                    int tmp = a[j];
                    int k = j - gap;
                    while (k >= 0 && a[k] > tmp) {
                        a[k + gap] = a[k];
                        k -= gap;
                    }
                    a[k + gap] = tmp;
                }
            }
        }
    }
    for (int i=0; i<9; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}