/*
  Name:最小生成树 
  CopyRight:
  Author: Cz
  Date: 2019/8/27 20:27:50
  Description:
*/
/*
//prim算法
//算法概要
1. 特点：从顶点扩展最小生成树，选边加点
2. 适合稠密图 时间复杂度(V^2) 
3. 伪码 
void prim(G,T){
	T = null;
	U = {w} ;
	while(V != U){
		for(u : U)
			for(v : V)
				if(u,v) is the shortest edge in all edges which vertex coming from the two set respectively.
				then
					T = T union {{u,v}} //边加到树上去
					U = U union u; //顶点加入U集合 
	}
}
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
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 0x7fffffff;
const int maxn = 2e2+10;
int dx[4] = {0, 0, 1, -1};
int dy[4]  = {1, -1, 0 , 0};

int dis[maxn];//记录每个顶点到S集合的所有边的长度
int vis[maxn];//点是否在S集合
int G[maxn][maxn];//存图 邻接矩阵存储，因为prim算法适合顶点少，边多的图 
int x,y,w;
int sum;
int n,m;
void Prim(int s){
    memset(vis , 0 , sizeof vis);
    vis[s] = 1;
    //s进入S集合，初始化一下dis
    rep(i,1,n){
        dis[i] = G[i][s];
    }
    //还需要选n-1个点
    rep(i , 1 ,  n-1){
        int minx=inf;
        int index;
        //从dis中找出一个最小的
        rep(j,1,n){  //实际上可以堆优化 
            if(!vis[j] && dis[j] < minx){
                minx = dis[j];
                index = j;
            }
        }
        //这个顶点被加入S集合 因为这个顶点到S集合的边最小
        vis[index] = 1;
        sum += minx;//最小生成树总长加上该边的值
        //由于这个顶点的加入，使得余下V-S顶点到S集合的距离发生了变化
        rep(j , 1, n){
            if(!vis[j] && G[index][j] < dis[j]){
                dis[j] = G[index][j];
            }
        }
    }
}
int main(){
    while(cin>>n){
        if(n == 0) break;
        rep(i,1,n)
        rep(j,1,n)
        if(i==j) G[i][j] =  0;
        else G[i][j] = inf;
        sum = 0;
        rep(i,1,n*(n-1)/2){
            cin>>x>>y>>w;
            G[x][y] = w;
            G[y][x] = w;
        }

        Prim(1);
        cout<<sum<<endl;

    }
    return 0;
}



//克鲁斯卡尔算法 Kruskal
/*
1. 特点：选边加点法，每次选最小的边，不形成环就加入
2. 适合边比较少的稀疏图
3. 可用并查集来判断环 
4. 把边排序时间复杂度ElogE,或者用堆存放E也是ElogE,之后只需要扫描一遍E，
总体复杂度是O(ElogE)
 
void Kruskal(V,T){
	T = V;
	nums = n;
	while(nums > 1){
		find the shortest edge(u,v) from E
		if v and u are subordinate to different conecttion components
		then  
			T = T union {(u , v)};
			nums--; 
	}
} 


int n;//边数
int m;//顶点数
int fa[maxn];//根节点
//把边按照从小到大排序
struct node{
    int u,v,w; 
}edge[M];

bool cmp(node a, node b){
    return a.w < b.w;
}

//并查集基本操作
void init(){
    rep(i,1,n){
        fa[i] = i;
    }
}
int find(int x){
    if(x != fa[x]){
        return fa[x] = find(fa[x]);
    }
    return fa[x];
}
void merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        fa[fx] = fa[fy];
    }
}

int main(){
    int x,y,w;
    ios::sync_with_stdio(false);
    while(cin>>n){
        if(n  == 0) break;
        m = (n-1)*n/2;
        int sum = 0;
        init();
        rep(i , 1, m){
            cin>>x>>y>>w;
            edge[i].u = x;
            edge[i].v = y;
            edge[i].w = w;
        }
        sort(edge+1,  edge+1+m,cmp);//把边从小到大
        //从小到大筛边 遇到 环则跳过
        rep(i,1,m){
            node cur = edge[i];
            int u = cur.u;
            int v = cur.v;
            int w = cur.w;
        //如果u,v处于同一个集合，在加入uv边则必形成环
            if(find(u) != find(v)){
                sum += w;
                merge(u,v);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
*/ 



