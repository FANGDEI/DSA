//过河卒
#include <iostream>
#include <algorithm>
using namespace std;
int map[25][25];
long long f[25][25];
int x1, y1, x2, y2;
int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    x1+=2, y1+=2, x2+=2, y2+=2;
    f[1][2] = 1;
    map[x2][y2] = 1;
    map[x2-1][y2-2] = 1;
    map[x2+1][y2-2] = 1;
    map[x2-2][y2-1] = 1;
    map[x2+2][y2-1] = 1;
    map[x2-2][y2+1] = 1;
    map[x2+2][y2+1] = 1;
    map[x2-1][y2+2] = 1;
    map[x2+1][y2+2] = 1;
    for (int i=2; i<=x1; i++) {
        for (int j=2; j<=y1; j++) {
            if (!map[i][j]) f[i][j] = f[i][j-1] + f[i-1][j];
            else f[i][j] = 0;
        }
    }
    cout << f[x1][y1] << endl;
    return 0;
}