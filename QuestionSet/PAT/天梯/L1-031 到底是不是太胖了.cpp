/*
 * @Author: FANG
 * @Date: 2021-10-18 18:35:35
 */
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int high, weight;
        double s;
        cin >> high >> weight;
        s = (high - 100) * 0.9 * 2;
        if (abs((weight - s)) < 0.1 * s) cout << "You are wan mei!" << endl;
        else if (weight - s > 0) cout << "You are tai pang le!" << endl;
        else cout << "You are tai shou le!" << endl;
    }
    
    return 0;
}