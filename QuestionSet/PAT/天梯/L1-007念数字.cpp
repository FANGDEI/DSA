/*
 * @Author: FANG
 * @Date: 2021-09-23 20:25:51
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int main() {
    char ch;
    ch = getchar();
    while (1) {
        if (ch == '-') cout << "fu";
        if (ch == '0') cout << "ling";
        if (ch == '1') cout << "yi";
        if (ch == '2') cout << "er";
        if (ch == '3') cout << "san";
        if (ch == '4') cout << "si";
        if (ch == '5') cout << "wu";
        if (ch == '6') cout << "liu";
        if (ch == '7') cout << "qi";
        if (ch == '8') cout << "ba";
        if (ch == '9') cout << "jiu";
        ch = getchar();
        if (ch == '\n') {
            cout << endl;
            break;
        } else cout << " ";
    }
    return 0;
}