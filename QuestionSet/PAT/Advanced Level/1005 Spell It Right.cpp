/*
 * @Author: FANG
 * @Date: 2021-09-27 14:17:58
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int sum = 0;
    char ch;
    while ((ch = getchar()) != '\n') {
        sum += (ch - '0');
    }
    string s = to_string(sum);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') cout << "zero";
        if (s[i] == '1') cout << "one";
        if (s[i] == '2') cout << "two";
        if (s[i] == '3') cout << "three";
        if (s[i] == '4') cout << "four";
        if (s[i] == '5') cout << "five";
        if (s[i] == '6') cout << "six";
        if (s[i] == '7') cout << "seven";
        if (s[i] == '8') cout << "eight";
        if (s[i] == '9') cout << "nine";
        if (i + 1 != s.length()) cout << " ";
        else cout << endl;
    }
    return 0;
}