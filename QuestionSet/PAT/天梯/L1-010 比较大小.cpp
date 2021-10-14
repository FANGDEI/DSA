/*
 * @Author: FANG
 * @Date: 2021-10-14 18:44:13
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[3];
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a + 3);
    for (int i = 0; i < 3; i++) {
        cout << a[i];
        if (i != 2) cout << "->";
        else cout << endl;
    }
}