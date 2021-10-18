/*
 * @Author: FANG
 * @Date: 2021-10-18 18:32:36
 */
#include <iostream>
#include<string>
#include<cmath>

using namespace std;

void Prime(int n) {
    if (n < 2) {
        cout << "No" << endl;
        return ;
    }
    if (n == 2) {
        cout << "Yes" << endl;
        return ;
    }
    for (int i=2; i<sqrt(n); i++) {
        if (n % i == 0) {
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
}

int main() {
	int n, m;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> m;
        Prime(m);
    }
	return 0;
}

