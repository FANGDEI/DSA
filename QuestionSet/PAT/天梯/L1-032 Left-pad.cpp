/*
 * @Author: FANG
 * @Date: 2021-10-18 18:36:41
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int n;
    char ch;
    cin >> n >> ch;
    getchar();
    getline(cin, s);
    if (n >= s.length()) {
        for (int i=0; i<n - s.length(); i++) cout << ch;
        cout << s;
    } else {
        for (int i=s.length() - n; i<s.length(); i++) cout << s[i];
    }
    
    return 0;
}