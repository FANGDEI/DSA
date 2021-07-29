#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

struct bigNum
{ // 大数存储
    int d[100005];
    int len;
    bigNum()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bigNum change(string str)
{
    bigNum a;
    a.len = str.length();
    for (int i = 0; i < a.len; i++)
    { // 整数的高位会变成数组的低位 而整数的低位会变成数组的高位 逆序存储
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

int compare(bigNum a, bigNum b) //比较a，b的大小，返回1，0，-1
{
    if (a.len > b.len)
        return 1;
    else if (a.len < b.len)
        return -1;
    else
    {
        for (int i = a.len - 1; i >= 0; i--) //从高往低比较
        {
            if (a.d[i] > b.d[i])
                return 1;
            else if (a.d[i] < b.d[i])
                return -1;
        }
        return 0; //两位数相等
    }
}

bigNum add(bigNum a, bigNum b)
{
    bigNum c;
    int carry = 0; //carry是进位
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10; //个位数为该位的结果
        carry = temp / 10;        //十位数为新的进位
    }
    if (carry != 0) //如果最后进位不为0，则直接赋给最高位
    {
        c.d[c.len++] = carry;
    }
    return c;
}

bigNum sub(bigNum a, bigNum b)
{
    bigNum c;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        if (a.d[i] < b.d[i])
        {
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0)
        c.len--;
    return c;
}

bigNum multi(bigNum a, int b)
{
    bigNum c;
    int carry = 0; //进位
    for (int i = 0; i < a.len; i++)
    {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10; //个位作为该位的结果
        carry = temp / 10;        //高位部分作为新的进位
    }
    while (carry != 0)
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

bigNum divide(bigNum a, int b, int &r) //r为余数，初始时r = 0
{
    bigNum c;
    c.len = a.len; //被除数的每一位和商的每一位是一一对应的，因此先令其长度相等
    for (int i = a.len - 1; i >= 0; i--)
    {
        r = r * 10 + a.d[i];
        if (r < b) //如果不够除
            c.d[i] = 0;
        else //够除
        {
            c.d[i] = r / b; //商
            r = r % b;
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0)
    {
        c.len--;
    }
    return c;
}

bigNum multi(bigNum a, bigNum b)
{
    bigNum c;
    for (int i = 0; i < a.len; i++)
    {
        for (int j = 0; j < b.len; j++)
        {
            c.d[i + j] += (a.d[i] * b.d[j]); //先乘起来，后面统一进行进位
        }
    }
    int i = 0;
    while (c.d[i] != 0)
    {
        if (c.d[i] >= 10) //若>=10
        {
            c.d[i + 1] = c.d[i + 1] + c.d[i] / 10; //将十位上数字进位
            c.d[i] = c.d[i] % 10;                  //将个位上的数字留下
        }
        i++;
    }
    c.len = i;
    return c;
}

bigNum divide(bigNum a, bigNum b) //a是被除数，b是除数
{
    int sum = 0;
    while (compare(a, b) >= 0) //当a>=b就一直继续
    {
        a = sub(a, b);
        sum++;
    }
    return a;
}

int main()
{

    return 0;
}