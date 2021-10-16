/*
 * @Author: FANG
 * @Date: 2021-10-16 12:10:07
 */
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int x, y;
    bool operator < (const node &a) {
        return this->y < a.y;
    }
} a[100005];
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n);
    int res = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].x >= end) {
            res++;
            end = a[i].y;
        }
    }
    cout << res << endl;
    return 0;
}