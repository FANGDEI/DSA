/*
 * @Author: FANG
 * @Date: 2021-10-10 19:51:32
 */
/* 计算出总天数后对7取余数的结果是0 ~ 6 */

#include <iostream>
using namespace std;
int main() {
	int y, m, d;
	cin >> y >> m >> d;
	int tmp = (y - 1) / 400;
	int beforeYearDay = tmp * 400 * 365 + tmp * 97;
	for (int i = tmp * 400 + 1; i < y; i++) {
		if (i % 400 == 0 || (i % 100 != 0 && i % 4 == 0)) beforeYearDay += 366;
		else beforeYearDay += 365;
	}
	cout << beforeYearDay << endl;
	// 1 3 5 7 8 10 12
	int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) month[2] += 1;
	for (int i = 0; i < m; i++) beforeYearDay += month[i];
	cout << beforeYearDay << endl;
	int days = beforeYearDay + d;
	cout << days << endl;
	tmp = days % 7;
// 	cout << tmp << endl;
	if (tmp == 1) cout << "Monday" << endl;
	else if (tmp == 2) cout << "Tuesday" << endl;
	else if (tmp == 3) cout << "Wednesday" << endl;
	else if (tmp == 4) cout << "Thursday" << endl;
	else if (tmp == 5) cout << "Friday" << endl;
	else if (tmp == 6) cout << "Saturday" << endl;
	else if (tmp == 0) cout << "Sunday" << endl; 
	return 0;
}