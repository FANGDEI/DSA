# Prime Number Sieve

# SieveOfEratosthenes

***一个质数的倍数一定是合数***

对于 2 3 4 5 6 7 8 9 10 11 12 13

2是质数筛去二的倍数: 2 3 ~~4~~ 5 ~~6~~ 7 ~~8~~ 9 ~~10~~ 11 ~~12~~ 13

3是质数筛去三的倍数: 2 3 ~~4~~ 5 ~~6~~ 7 ~~8~~ ~~9~~  ~~10~~ 11 ~~12~~ 13

***

就可以得到13以内的质数是2 3 5 7 11 13

```java
class SieveOfEratosthenes {
    public static void main(String[] args) {
        SieveOfEratosthenes.sieve(100);
        for (int i=1; i<=k; i++) System.out.println(prime[i] + " ");
    }
    static final int N = 10000000 + 5;
    static int[] vis = new int[N], prime = new int[N];
    static int k = 0;
    public static void sieve(int n) {
        for (int i=2; i<=n; i++) {
            if (vis[i] == 0) {
                for (int j=2; i*j<=n; j++) {
                    vis[i * j] = 1; // 筛去
                }
                prime[++k] = i;
            }
        }
    }
}
```

## SieveOfEuler

通过一个合数的最小质因数来筛选

减少了很多SieveOfEratosthenes中重复筛选的数

```java
class SieveOfEuler {
    public static void main(String[] args) {
        SieveOfEuler.sieve(100);
        for (int i=1; i<=k; i++) {
            System.out.println(prime[i] + " ");
        }
    }
    static final int N = 10000000 + 5;
    static int[] vis = new int[N], prime = new int[N];
    static int k = 0;
    public static void sieve(int n) {
        for (int i=2; i<=n; i++) {
            if (vis[i] == 0) prime[++k] = i;
            for (int j=1; j<=k&&i*prime[j]<=n; j++) {
                vis[i * prime[j]] = 1;
                if (i % prime[j] == 0) break;
            }
        }
    }
}
```



