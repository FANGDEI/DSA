/*
 * @Author: FANG
 * @Date: 2021-10-14 18:42:16
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int maxCount = 0, start;
    for (int i = 2; i <= sqrt(n); i++) {
        int tmp = n;
        int j = i, count = 0;
        while (tmp % j == 0) {
            tmp = tmp / j;
            j++;
            count++;
        }
        if (count > maxCount) start = i, maxCount = count;
    }
    if (maxCount) {
        cout << maxCount << endl;
        for (int i = 0; i < maxCount; i++) {
            if (!i) cout << start + i;
            else cout << "*" << start + i;
        }
        cout << endl;
    } else {
        cout << "1" << endl << n << endl;
    }
    return 0;
}