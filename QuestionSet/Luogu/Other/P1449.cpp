/*
 * @Author: FANG
 * @Date: 2021-10-09 11:23:52
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    char ch;
    stack<int> sta;
    while ((ch = getchar()) != '@') {
        if (ch == '+') {
            int a = sta.top();
            sta.pop();
            int b = sta.top();
            sta.pop();
            sta.push(a + b);
        } else if (ch == '-') {
            int a = sta.top();
            sta.pop();
            int b = sta.top();
            sta.pop();
            sta.push(b - a);
        } else if (ch == '*') {
            int a = sta.top();
            sta.pop();
            int b = sta.top();
            sta.pop();
            sta.push(a * b);
        } else if (ch == '/') {
            int a = sta.top();
            sta.pop();
            int b = sta.top();
            sta.pop();
            if (a == 0) return 0;
            sta.push(b / a);
        } else {
            string d = "";
            while (ch != '.') {
                if (ch <= '9' && ch >= '0') {
                    d += ch;
                }
                ch = getchar();
            }
            sta.push(atoi(d.c_str()));
            d = "";
        }
    }
    cout << sta.top() << endl;
    return 0;
}