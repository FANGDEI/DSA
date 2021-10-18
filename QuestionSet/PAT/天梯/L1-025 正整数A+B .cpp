/*
 * @Author: FANG
 * @Date: 2021-10-18 18:16:57
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
	char a[100], b[100];
	cin >> a;
	getchar();
	scanf("%[^\n]", b);
	int la = strlen(a), lb = strlen(b);
	for (int i=0; i<la; i++) if (a[i] < '0' || a[i] > '9') a[0] = '@';
	for (int i=0; i<lb; i++) if (b[i] < '0' || b[i] > '9') b[0] = '@';
	int A, B;
	A = atoi(a);
	B = atoi(b);
	if (A == 0 && B == 0) cout << "? + ? = ?" << endl;
	else if (A==0 && B!=0) if (B>=1 && B<=1000) printf("? + %d = ?\n", B); else cout << "? + ? = ?" << endl;
	else if (A!=0 && B==0) if (A>=1 && A<=1000) printf("%d + ? = ?\n", A); else cout << "? + ? = ?" << endl;
	else if (A!=0 && B!=0) {
		if (A>=1 && A<=1000 && B>=1 && B<=1000) printf("%d + %d = %d", A, B, A+B);
		else if ((A<1 || A>1000) && (B<1 || B>1000)) cout << "? + ? = ?" << endl;
		else if ((A>=1 && A<=1000) && (B<1 || B>1000)) printf("%d + ? = ?\n", A);
		else if ((B>=1 && B<=1000) && (A<1 || A>1000)) printf("? + %d = ?\n", B);
	}
	return 0;
}