/*
 * @Author: FANG
 * @Date: 2021-10-14 18:30:39
 */
#include <iostream>

using namespace std;

int main() {
    string a;
    cin >> a;
    int b[10] = {0};
    for (int i = 0; i < a.length(); i++) {
        b[a[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (b[i]) cout << i << ":" << b[i] << endl;
    }
    return 0;
}