/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/2 21:01:42
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
const int maxn = 505;
const int inf = 0x3f3f3f3f; 
int dist[maxn];
int head[maxn];
int cnt;
struct node{
	int v,w,nxt;
}edge[maxn<<1];

void addEdge(int u, int v, int w){
	edge[cnt].v = v;
	edge[cnt].nxt = head[u];
	edge[cnt].w = w; 
	head[u] = cnt++;
}

int n,m,k;
bool vis[maxn];
void dijkstra(int s){
	memset(vis , 0 ,sizeof vis);
	vis[s] = 1;
	for(int i=1; i<=n; i++) dist[i] = inf; //dist[i]表示1到i的最短距离 
	dist[s] = 0;
	//源点 第一次松弛 
	for(int i=head[s]; i!=-1; i=edge[i].nxt){
		int v = edge[i].v;
		dist[v] = edge[i].w;
	}
	
	for(int i=1; i<n; i++){ //经过n-0轮次选举 
		int pos,minx = inf;
		for(int j=1; j<=n; j++){
			if(!vis[j] && dist[j] < minx){
				minx = dist[j];
				pos = j;
			}
		}
		
		vis[pos] = 1; //当前最小距离点加入集合S 
		//松弛操作
		for(int j=head[pos]; j!=-1; j=edge[j].nxt){
			int v = edge[j].v;
			int w = edge[j].w;
			if(!vis[v] && dist[v] > dist[pos] + w)
				dist[v] = dist[pos] + w;
		}
	}
}


int main(){
	int u,v,t;
	cin>>t;
	while(t--){
		cnt = 0; //从第0条边开始计数 对应head初始化为-1
		memset(head, -1, sizeof head); 
		cin>>n>>m>>k;
		for(int i=1; i<=m; i++){
			cin>>u>>v;
			addEdge(u,v,1);
			addEdge(v,u,1);
		}
		
		dijkstra(1);
		cout<<dist[n]<<endl; 
		//for(int i=1; i<=n; i++) cout<<dist[i]<<endl;
		for(int i=1; i<=k ;i++){
			cin>>u;
			u <<= 1;
			u -= 1;
			edge[u].w = inf; //关闭双向路 
			edge[u^1].w = inf;
		}
	//	for(int i=0; i<cnt; i++) cout<<"edge "<<i<<" "<<" v= "<<edge[i].v<<" w = "<<edge[i].w<<endl;
		
		dijkstra(1);
		cout<<dist[n]<<endl;
	}


	return 0;
}

