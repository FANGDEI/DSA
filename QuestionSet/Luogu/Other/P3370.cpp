/*
 * @Author: FANG
 * @Date: 2021-11-03 22:54:44
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m[s]++;
    }
    cout << m.size() << endl;
    return 0;
}