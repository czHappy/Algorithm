/*
  Name: 迪杰斯特拉 
  CopyRight:
  Author: Cz
  Date: 2019/8/27 21:07:00
  Description:
*/

/*
算法
void dijkstra(G,v0,dist){
	init S = {v0} dist[i] = G[v0][i]
	while(S != V)
		for(vj in V-S) 
			if dist[j] is the minimum value of distance between v0 and V-S
			then 
				S = S union {j}
		for v in next[j] //v的在V-S中下一条边
			 update dist[v] with dist[v] and G[j][v] 
			
} 

与普利姆算法的联系与区别
1. 普利姆中的距离是S集合整体到v的距离，而迪杰斯特拉的距离是v0到v的距离
2. 前者更新距离是以新加入的顶点为核心更新其它顶点到它的距离，以此更新集合S到各点距离，
后者也是以新加入的顶点为核心更新其它顶点到源点的距离 
*/ 

#include<iostream>
#include<queue>
#include<list>
#include<vector>
#include<cstring>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;
typedef long long ll;
#define rep(i,s,e) for(int i=s; i<=e; i++)
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+10;
int dis[maxn];
int G[maxn][maxn];
int n,m;//n个结点 m条边
bool vis[maxn];
void dijkstra(int s){
    memset(vis , 0 , sizeof vis);
    rep(i,1,n){
        dis[i] = G[s][i];
    }
    vis[s] = 1;//s加入S集合

    //只需要再将n-1个点加入S集合
    rep(i, 1 , n-1){
        int minx = inf;//对于每一次找点，都要找当前最短路的点
        int pos;//记录一下是哪个点
        rep(j , 1 , n){ //这里实际上可以用堆优化 
            if(!vis[j] && dis[j] < minx){
                minx = dis[j];
                pos = j;
            }
        }
        //pos顶点加入S集合
        vis[pos] = 1;
        //由于pos顶点的进入 对S集合以外的结点 其距离因为pos的加入需要进行更新
        rep(k, 1 , n){ //对S集合以外的点松弛操作 
            if(!vis[k] && dis[k] > dis[pos] + G[pos][k]){
                dis[k] = dis[pos] + G[pos][k];
            }
        }
    }
}


int main(){
    int x,y,w;
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        //初始化
        rep(i,1,n)
        rep(j,1,n){
            if(i == j) G[i][j] = 0;
            else G[i][j] = inf;
        }
        rep(i,1,m){
            cin>>x>>y>>w;
            G[x][y] = w;
            G[y][x] = w;
        }
        dijkstra(1);
        //rep(i,1,n) cout<<dis[i]<<" ";
        int e;
        while(cin>>e)
            cout<<dis[e]<<endl;
    }
    return 0;
}

