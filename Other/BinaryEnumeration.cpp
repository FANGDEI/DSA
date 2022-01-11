/*
 * @Author: FANG
 * @Date: 2022-01-11 14:10:24
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}