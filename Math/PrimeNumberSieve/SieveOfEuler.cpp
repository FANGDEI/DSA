#include<stdio.h>
#include<stdlib.h>
#define MAX 100000005

int a[MAX], prime[MAX], s;

int main(){
    int n;
    scanf("%d", &n);

    for (int i=2; i<=n; i++){
        if (a[i] == 0)prime[++s] = i;
        for (int j = 1; j<=s && i * prime[j] <= n; j++){
            a[i*prime[j]] = 1;
            if (i%prime[j]==0)break;
        }
    }

    for (int i = 1; i<=s; i++)printf("%d\n", prime[i]);

    system("pause");
    return 0;
}