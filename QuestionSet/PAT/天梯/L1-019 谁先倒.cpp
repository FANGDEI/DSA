/*
 * @Author: FANG
 * @Date: 2021-10-18 17:10:01
 */
/*
 * @Author: FANG
 * @Date: 2021-08-01 08:54:11
 */
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int ta = a, tb = b;
    int n;
    cin >> n;
    while (n--) {
        int e, f, g, h;
        cin >> e >> f >> g >> h;
        int m = e + g;
        if (f == m && f != h) a--;
        if (h == m && h != f) b--;
        if (a < 0) {
            cout << "A" << endl;
            cout << tb - b << endl;
            return 0;
        } else if (b < 0) {
            cout << "B" << endl;
            cout << ta - a << endl;
            return 0;
        }
    }
    return 0;
}