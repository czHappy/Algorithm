/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/2 11:11:32
  Description:
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
const int maxn = 1e3;

vector<int> G[maxn];
int n,m;//顶点数 询问数
int cnt;
struct node{
	int u,v;
	int nxt;
	int id;
}query[maxn<<1];

int head[maxn];

void addQ(int u, int v, int id){
	query[cnt].v = v;
	query[cnt].u = u;
	query[cnt].id = id;
	query[cnt].nxt = head[u];
	head[u] = cnt++;
}

bool vis[maxn];//结点访问标志
int dist[maxn];//结点到根节点的距离 
int lca[maxn];//lca[i]是第i个询问的lca 

//并查集基本操作 
int fa[maxn] ;
void init(){
	for(int i=1; i<maxn; i++){
		fa[i] = i;
		vis[i] = 0;
		head[i] = 0; 
		G[i].clear();
	}
	dist[1] = 0;
	cnt = 1;
} 

int find(int x){
	if(x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

void merge(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		fa[fy] = fx;
	}
}

void tarjan(int u){
	vis[u] = 1;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(!vis[v]){
			dist[v] = dist[u] + 1;
			tarjan(v);
			merge(u , v);//这里一定要注意是把v merge到 u 
		}
	}
	for(int i=head[u]; i; i = query[i].nxt){
		int v = query[i].v;
		if(vis[v]){
			lca[query[i].id] = find(v);
		}
	}
}



int main(){
	int t;
	cin>>t;
	while(t--){
		init();
		cin>>n>>m;
		int x,y;
		for(int i=1; i<=n; i++){
			cin>>x>>y;
			if(x!=-1){
				G[i].push_back(x);
				G[x].push_back(i);
			} 
			if(y!=-1){
				G[i].push_back(y);
				G[y].push_back(i);
			} 
		}
		for(int i=1; i<=m; i++){
			cin>>x>>y;
			addQ(x, y, i);
			addQ(y, x, i);
		}	
		tarjan(1);
		for(int i=1; i<cnt; i+=2){
			cout<<dist[query[i].u] + dist[query[i].v] - 2*dist[lca[query[i].id]]<<endl;
		}
	}


	return 0;
}

