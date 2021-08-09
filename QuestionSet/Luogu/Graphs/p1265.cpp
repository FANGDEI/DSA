//P1265 公路修建
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, x[5005], y[5005];
double dis[5005];
bool vis[5005];
double getDistance(int i, int j) {
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> x[i] >> y[i];
    double res = 0;
    for (int i=1; i<=n; i++) dis[i] = INF;
    dis[1] = 0;
    for (int i=1; i<=n; i++) {
        double m = INF;
        int x = 0;
        for (int j=1; j<=n; j++) {
            if (!vis[j] && dis[j] < m) {
                m = dis[j];
                x = j;
            }
        }
        vis[x] = true;
        res += m;
        for (int j=1; j<=n; j++) {
            if (j != x && dis[j] > getDistance(j, x)) dis[j] = getDistance(j, x);
        }
    }
    printf("%.2lf", res);
    return 0;
}