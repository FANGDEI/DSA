/*
 * @Author: FANG
 * @Date: 2021-10-14 19:15:48
 */
#include <stdio.h>
int main()
{
    int h, m;
    scanf("%d:%d", &h, &m);
    if (h < 12 || (h == 12 && m == 00))
        printf("Only %02d:%02d.  Too early to Dang.", h, m);
    else
    {
        if (m > 00)
            h++;
        for (int i = 0; i < h - 12; i++)
            printf("Dang");
    }
}
