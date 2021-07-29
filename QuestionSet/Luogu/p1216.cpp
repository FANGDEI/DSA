//数字三角形
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
int a[1005][1005];
int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			cin >> a[i][j];
		}
	}
	// int ans = 0;
	for (int i=n; i>=0; i--) {
		for (int j=1; j<=n; j++) {
			// ans = 
			a[i][j] = max(a[i+1][j], a[i+1][j+1]) + a[i][j];
		}
	}
	cout << a[1][1] << endl;
	return 0;
}
/*
0
0 7
0 3 8
0 8 1 0
0 2 7 4 4
0 4 5 2 6 5 
0 0 0 0 0 0 0
*/