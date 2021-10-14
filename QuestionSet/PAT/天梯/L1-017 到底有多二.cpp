/*
 * @Author: FANG
 * @Date: 2021-10-14 19:12:17
 */
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    bool isEven = false, isNegative = false;
    if (s[0] == '-') isNegative = true;
    if ((s[s.length() - 1] - '0') % 2 == 0) isEven = true;
    int count = 0;
    for (int i = 0; i < s.length(); i++) if (s[i] == '2') count++;
//     cout << count * 1.0 / (isNegative == true ? s.length() - 1 : s.length()) * (isEven == true ? 2 : 1) * (isNegative == true ? 1.5 : 1) << endl;
    printf("%.2lf%%", count * 1.0 / (isNegative == true ? s.length() - 1 : s.length()) * (isEven == true ? 2 : 1) * (isNegative == true ? 1.5 : 1) * 100);
    return 0;
}