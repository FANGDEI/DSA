#include<bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
struct Matrix {
	long long c[101][101];
} A, I;
long long n, k;
Matrix operator*(const Matrix &x,const Matrix &y) { // 运算符重载
	Matrix a;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			a.c[i][j]=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++) {
				a.c[i][j]+=x.c[i][k]*y.c[k][j]%Mod; // 步步取模
				a.c[i][j]%=Mod;
			}
	return a;
}

int main() {
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>A.c[i][j];
	for(int i=1; i<=n; i++) // 单位矩阵
		I.c[i][i]=1;
	while(k) {
		if(k&1) I=I*A;
		A=A*A;
		k=k>>1;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			cout<<I.c[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}