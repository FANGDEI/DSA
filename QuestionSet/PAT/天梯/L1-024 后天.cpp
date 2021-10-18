/*
 * @Author: FANG
 * @Date: 2021-10-18 18:09:29
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int a;
    cin >> a;
    a += 2;
//     cout <<a << endl;
    if (a > 7) a %= 7;
    cout << a << endl;
    return 0;
}