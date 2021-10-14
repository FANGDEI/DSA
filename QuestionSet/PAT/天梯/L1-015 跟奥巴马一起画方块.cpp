/*
 * @Author: FANG
 * @Date: 2021-10-14 18:45:47
 */
#include<stdio.h>
int main(){
    int n,row;
    char c;
    scanf("%d %c",&n,&c);
    if(n%2==0)
        row=n/2;
    else row=n/2+1;
    for(int i=0;i<row;i++){
        for(int j=0;j<n;j++)
            putchar(c);
        printf("\n");
    }
    return 0;
}