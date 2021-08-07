# Graphs

## 图的存储
***

### 邻接矩阵

![邻接矩阵](https://img-blog.csdnimg.cn/20190128175511539.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzcyMTQyMw==,size_16,color_FFFFFF,t_70)

* 邻接矩阵的局限性：时间复杂度O(n^2)，空间复杂度O(n^2)

* 稀疏图用邻接矩阵存储浪费空间

* 要确定图中有多少条边，则必须按行、按列对每个元素进行检测，所花费的时间代价很大


### 邻接表

![邻接表](https://img-blog.csdn.net/20180312142243881?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQva29uZ194eg==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

### 链式前向星
......数组模拟邻接表
