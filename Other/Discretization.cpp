/*
 * @Author: FANG
 * @Date: 2021-11-09 19:59:04
 */
/*
    离散化: 当数组的值域很大, 但数组元素的个数很少时可以进行离散化
    如a[] = {1, 10, 5, 2000, 500000}
    离散化后: 0, 2, 1, 3, 4
*/
#include <vector>
#include <algorithm>

std::vector<int> alls; // 储存所有离散化的值
alls.erase(std::unique(alls.begin(), alls.end()), alls.end()); // 去重

// 可以用 lower_bound() 代替
int binarySearch(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (q[mid] >= goal) r = mid;
        else l = mid + 1;
    }
    return r; // return r + 1; 根据题意
}