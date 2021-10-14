/*
 * @Author: FANG
 * @Date: 2021-10-14 18:46:01
 */
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int n, flag = true;
    cin >> n;
    int m[] = {0,7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    for (int i = 0; i < n; i++) {
        cin >> s;
        int sum = 0;
        for (int j = 0; j < s.length() - 1; j++) {
            sum += (s[j] - '0') * m[j + 1];
        }
        sum %= 11;
        char n[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
        if (n[sum] != s[s.length() - 1]) cout << s << endl, flag = false;
    }
    if (flag) cout << "All passed" << endl;
    return 0;;
}