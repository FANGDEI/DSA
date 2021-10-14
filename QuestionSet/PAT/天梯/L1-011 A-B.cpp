/*
 * @Author: FANG
 * @Date: 2021-10-14 18:44:28
 */
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            if (a[i] == b[j]) a[i] = '~';
        }
    }
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != '~') cout << a[i];
    }
    cout << endl;
    return 0;
}