/*
 * @Author: FANG
 * @Date: 2021-10-18 17:51:41
 */
#include <iostream>
using namespace std;
int n;
int main() {
    cin >> n;
    int odd, even;
    odd = even = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t & 1) odd++;
        else even++;
    }
    cout << odd << " " << even << endl;
    return 0;
}