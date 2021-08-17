/*
 * @Author: FANG
 * @Date: 2021-08-17 16:44:19
 * @LastEditTime: 2021-08-17 17:09:23
 * @Description: https://vjudge.ppsucxtt.cn/problem/POJ-2236
 * @FilePath: \DSA\QuestionSet\VirtualJudge\Trees\DSU\WirelessNetwork.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct{
  int x,y;
  int index;
}pos;

int pre[1005];
pos p[1005];
pos repaired[1005];

void init(){
   for(int i=1;i<=1000;i++)
      pre[i]=i;
}

int root_find(int x){
   return pre[x]==x?x:pre[x]=root_find(pre[x]);
}

void join(int x,int y){
  int rx=root_find(x);
  int ry=root_find(y);
  if(rx!=ry)
    pre[rx]=ry;
}

double dis(pos a,pos b){
   return sqrt((double)(a.x-b.x)*(double)(a.x-b.x)+(double)(a.y-b.y)*(double)(a.y-b.y));
}

int main()
{
    init();
    int N,D;
    scanf("%d%d",&N,&D);
    for(int i=1;i<=N;i++)
        scanf(" %d %d",&p[i].x,&p[i].y);
    int cnt=0;
    char type;
    while(~scanf(" %c",&type)){
       if(type=='O') {
          int temp;
          scanf("%d",&temp);
          repaired[cnt].x=p[temp].x;
          repaired[cnt].y=p[temp].y;
          repaired[cnt].index=temp;
          for(int i=0;i<cnt;i++){
              if(dis(repaired[i],p[temp])<=D){

                  join(repaired[i].index,temp);
              }
          }
          cnt++;
       }
       else{
         int a,b;
         scanf(" %d %d",&a,&b);
         if(root_find(a)==root_find(b))
              printf("SUCCESS\n");
         else
              printf("FAIL\n");
       }

    }
    return 0;
}