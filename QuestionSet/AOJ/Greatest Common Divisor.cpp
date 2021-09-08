/*
 * @Author: FANG
 * @Date: 2021-09-08 21:00:25
 * @LastEditTime: 2021-09-08 21:15:14
 * @Description: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B
 * @FilePath: \DSA\QuestionSet\AOJ\Greatest Common Divisor.cpp
 */
#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}