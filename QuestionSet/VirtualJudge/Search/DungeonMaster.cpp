/*
 * @Author: FANG
 * @Date: 2021-08-23 12:45:49
 * @LastEditTime: 2021-08-23 13:40:37
 * @Description: https://vjudge.ppsucxtt.cn/problem/POJ-2251
 * @FilePath: \DSA\QuestionSet\VirtualJudge\Search\DungeonMaster.cpp
 */
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
const int N = 50;
typedef struct node
{
    int first;
    int second;
    int third;
} PO;
queue<PO> q; //定义一个结构体队列存点
int n, m, k, x1, y1, z1, x2, y2, z2;
char g[N][N][N];
;
int d[N][N][N];

int bfs(int x1, int y1, int z1)
{
    memset(d, -1, sizeof d); //初始所有距离原点的点全部设置为无穷大
    PO e;
    e.first = x1, e.second = y1, e.third = z1;
    q.push(e);                                                                              //出发点入队进行拓展
    d[x1][y1][z1] = 0;                                                                      //出发点距离设置为0
    int dx[] = {0, 1, 0, -1, 0, 0}, dy[] = {1, 0, -1, 0, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1}; //拓展操作可以直接定义数组来进行拓展
    while (!q.empty())
    {
        PO t = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i], z = t.third + dz[i];
            if (x >= 0 && y >= 0 && z >= 0 && x < k && y < m && z < n && (g[x][y][z] == '.' || g[x][y][z] == 'E') && d[x][y][z] == -1) //这里要特别注意已经出队的点不能再入队了，入队的都是从未入队过的点，所以加了句距离都为-1才进行入队操作
            {
                PO p;
                p.first = x, p.second = y, p.third = z;
                q.push(p);
                d[x][y][z] = d[t.first][t.second][t.third] + 1;
            }
        }
    } //只要队列不为空就进行拓展
    return d[x2][y2][z2];
}
int main()
{
    while (1)
    {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0)
            break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int b = 0; b < k; b++)
                {
                    cin >> g[b][j][i];
                    if (g[b][j][i] == 'S')
                        x1 = b, y1 = j, z1 = i;
                    if (g[b][j][i] == 'E')
                        x2 = b, y2 = j, z2 = i;
                }
        int a = bfs(x1, y1, z1);
        if (a == -1)
            printf("Trapped!");
        else
            printf("Escaped in %d minute(s).", a);
        puts("");
    }
    return 0;
}