//新二叉树
#include <iostream>
#include <string>
using namespace std;
int n;
string s;
int main() {
    cin >> n;
    cin >> s;
    for (int i=2; i<=n; i++) {
        string str;
        cin >> str;
        int x = s.find(str[0]);
        s.erase(x, 1);
        s.insert(x, str);
    }
    for (int i=0; i<s.length(); i++) if (s[i] != '*') cout << s[i];
    cout << endl;
    return 0;
}