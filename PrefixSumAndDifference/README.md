# Prefix sum and Difference

---

[ 参考资料1](https://blog.csdn.net/weixin_45629285/article/details/111146240)

[参考资料2](https://zhuanlan.zhihu.com/p/268883850)

---



## Prefix Sum

![Prefix Sum](https://img-blog.csdnimg.cn/20201213215001825.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTYyOTI4NQ==,size_16,color_FFFFFF,t_70)

### One-dimensional prefix sum

对于一个长度为n的区间，输入m个询问，每次输入l， r。对于每次询问输出区间中l到r数的和。

1. 暴力求区间和：时间复杂度为O(n * m) (TLE)

2. 前缀和：时间复杂度O(n + m)

   ```java
   import java.util.Scanner;
   
   public class OneDimensionalPrefixSum {
       public static void main(String[] args) {
           Scanner in = new Scanner(System.in);
           int n = in.nextInt();
           int[] sum = new int[N];
           for (int i=1; i<=n; i++) {
               int t;
               t = in.nextInt();
               sum[i] = sum[i-1] + t;
           }
           int m = in.nextInt();
           while (m != 0) {
               int l, r;
               l = in.nextInt();
               r = in.nextInt();
               System.out.println(sum[r] - sum[l-1]);
               m--;
           }
           in.close();
       }
       final static int N = (int)1e5 + 10;
   }
   ```

   ### Two-dimensional prefix sum

   ~~**容斥原理**~~ **容斥原理**

   输入一个n行m列的整数矩阵，再输入q个询问，每个询问包含四个整数x1, y1, x2, y2，表示一个子矩阵的左上角坐标和右下角坐标。对于每个询问输出子矩阵中所有数的和。
   
   ![prefix suma](https://pic1.zhimg.com/80/v2-73b5efba0c9bf6558444f2c09d57d918_720w.jpg)

```markdown
s[i] [j] = s[i-1][j] + s[i][j-1 ] + a[i] [j] - s[i-1][ j-1]
```

```java
import java.util.Scanner;

public class TwoDimensionalPrefixSum {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m, n, q;
        n = in.nextInt();
        m = in.nextInt();
        q = in.nextInt();
        int[][] a = new int[N][N], s = new int[N][N];
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                a[i][j] = in.nextInt();
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1];
            }
        }
        while (q!=0) {
            q--;
            int x1, x2, y1, y2;
            x1 = in.nextInt();
            y1 = in.nextInt();
            x2 = in.nextInt();
            y2 = in.nextInt();
            System.out.println(s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1]);
        }
        in.close();
    }
    final static int N = 1010;
}
```

## Difference

![difference](https://img-blog.csdnimg.cn/20201214210831512.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTYyOTI4NQ==,size_16,color_FFFFFF,t_70)

### One-dimensional difference

![one-dimensional difference](https://img-blog.csdnimg.cn/20201215214337143.png)

给定区间`[l ,r ]`，让我们把`a`数组中的`[ l, r]`区间中的每一个数都加上`c`

```java
import java.util.Scanner;

public class TwoDimensionalPrefixSum {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m, n;
        n = in.nextInt();
        m = in.nextInt();
        int[] a = new int[N], b = new int[N];
        for (int i=1; i<=n; i++) {
            a[i] = in.nextInt();
            b[i] = a[i] - a[i-1];
        }
        while (m != 0) {
            m--;
            int l, r, c;
            l = in.nextInt();
            r = in.nextInt();
            c = in.nextInt();
            b[l] += c;
            b[r+1] -= c;
        }
        for (int i=1; i<=n; i++) {
            b[i] += b[i-1];
            System.out.print(b[i] + " ");
        }
        in.close();
    }
    final static int N = (int)1e5 + 10;
}
```

### Two=dimensional difference

对于二维数组的子矩阵加上c。

![difference](https://img-blog.csdnimg.cn/20201217170336254.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTYyOTI4NQ==,size_16,color_FFFFFF,t_70)

```mark
b[i][j]=a[i][j]−a[i−1][j]−a[i][j−1]+a[i−1][j−1]; //预处理公式
a[i][j]=p[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1]; //差分矩阵还原得到原矩阵

我们可以先假想a数组为空，那么b数组一开始也为空，但是实际上a数组并不为空，因此我们每次让以(i,j)为左上角到以(i,j)为右上角面积内元素(其实就是一个小方格的面积)去插入 c=a[i][j]，等价于原数组a中(i,j) 到(i,j)范围内 加上了 a[i][j] ,因此执行n*m次插入操作，就成功构建了差分b数组.
```

```java
import java.util.Scanner;

public class TwoDimensionalDifference {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, m, q;
        n = in.nextInt();
        m = in.nextInt();
        q = in.nextInt();
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) a[i][j] = in.nextInt();
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) insert(i, j, i, j, a[i][j]);
        while (q != 0) {
            q--;
            int x1, x2, y1, y2, c;
            x1 = in.nextInt();
            y1 = in.nextInt();
            x2 = in.nextInt();
            y2 = in.nextInt();
            c = in.nextInt();
            insert(x1, y1, x2, y2, c);
        }
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];//还原
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                System.out.print(b[i][j] + " ");
            }
            System.out.println();
        }
        in.close();
    }
    static final int N = (int)1e3 + 5;
    static final int[][] a = new int[N][N], b = new int[N][N];
    public static void insert(int x1, int y1, int x2, int y2, int c) {
        b[x1][y1] += c;
        b[x2+1][y1] -= c;
        b[x1][y2+1] -= c;
        b[x2+1][y2+1] += c;
    }
}
```


