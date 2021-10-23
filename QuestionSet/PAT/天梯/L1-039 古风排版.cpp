/*
 * @Author: FANG
 * @Date: 2021-10-23 17:59:33
 */
#include <stdio.h>
#include <string.h>
int n;
char s[1005];
char str[1005][1005];
int main() {
	scanf("%d", &n);
	getchar();
	gets(s);
	int len = strlen(s), cow;
	if (len % n != 0) cow = len / n + 1;
	else cow = len / n;
//	printf("%d", cow);
	int k = 0;
	for (int i = cow - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (k < len) str[j][i] = s[k++];
			else str[j][i] = ' ';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < cow; j++) {
			printf("%c", str[i][j]);
		}
		puts("");
	}
	return 0;
}