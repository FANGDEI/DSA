/*
 * @Author: FANG
 * @Date: 2021-09-27 14:34:54
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int m;
    cin >> m;
    string first, last;
    int firstTime = 0x3f3f3f3f, lastTime = -0x3f3f3f3f;
    for (int i = 0; i < m; i++) {
        string id;
        int Hour, Min, Sec;
        cin >> id;
        scanf("%d:%d:%d", &Hour, &Min, &Sec);
        if (firstTime > Hour * 3600 + Min * 60 + Sec) firstTime = Hour * 3600 + Min * 60 + Sec, first = id;
        scanf("%d:%d:%d", &Hour, &Min, &Sec);
        if (lastTime < Hour * 3600 + Min * 60 + Sec) lastTime = Hour * 3600 + Min * 60 + Sec, last = id;
    }
    cout << first << " " << last << endl;
    return 0;
}