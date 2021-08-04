# FenwickTree

[FenwickTree](https://oi-wiki.org/ds/fenwick/)

*树状数组和线段树具有相似的功能，但他俩毕竟还有一些区别：树状数组能有的操作，线段树一定有；线段树有的操作，树状数组不一定有。但是树状数组的代码要比线段树短，思维更清晰，速度也更快，在解决一些单点修改的问题时，树状数组是不二之选。*
***

![FenwickTreeTest](https://oi-wiki.org/ds/images/fenwick1.png)

```java
import java.util.Scanner;

class FenwickTree {
	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        for (int i=1; i<=n; i++) {}
        in.close();
    }
    final static int N = 500000;
    static int[] a = new int[N], sum = new int[N], sum1 = new int[N], sum2 = new int[N];
    static int n;
    public static int lowbit(int x) {
        return x & -x;
    }
    // public static void update(int i, int k) { // 单点修改 区间查询(PrefixSum) 区间修改 单点查询(Difference)
    //     while (i <= n) {
    //         sum[i] += k;
    //         i += lowbit(i);
    //     }
    // }
    // public static int ask(int i) {
    //     int res = 0;
    //     while (i > 0) {
    //         res += sum[i];
    //         i -= lowbit(i);
    //     }
    //     return res;
    // }
    public static void update(int i, int k) { // 区间修改 区间查询(Difference)
        int x = i;
        while (i <= n) {
            sum1[i] += k;
            sum2[i] += k * (x - 1);
            i += lowbit(i);
        }
    }
    public static int ask(int i, int k) {
        int x = i;
        int res = 0;
        while (i > 0) {
            res += x * sum1[i] - sum2[i];
            i -= lowbit(i);
        }
        return res;
    }
}
```



## 二维树状数组
......