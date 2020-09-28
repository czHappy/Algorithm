/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/1 22:25:43
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
/*
struct node{
	int v;
	int nxt;
	int w;
}edge[maxn<<1];

int cnt = 1; //记录当前是第几条边  从1开始 
void addEdge(int u, int v, int w){
	edge[cnt].v = v;
	edge[cnt].w = w
	edge[cnt].nxt = head[u];
	head[u] = cnt++;
}

*/
const int maxn = 50*50;
int n,m;
struct node{
	int u,v,w;
}edge[maxn]; 

bool cmp(node a, node b){
	return a.w < b.w;
}


int fa[100];
//并查集基本操作
void init(){
	for(int i=0; i<100; i++) fa[i] = i;
}
int find(int x){
	if(x != fa[x]) return fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		fa[fx] = fy;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		init();
		cin>>n;
		m = 0;
		int w;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>w;
				if(i<=j) continue;
				edge[m].u = i;
				edge[m].v = j;
				edge[m].w = w;
				m++;
			}
		}
		sort(edge, edge+m, cmp);
		int ans = 0;
		for(int i=0; i<m; i++){
			int u = edge[i].u;
			int v = edge[i].v;
			int w = edge[i].w;
			if(find(u) != find(v)){
				ans += w;
				merge(u , v);
			}
		}
		cout<<ans<<endl;
	}
	

	return 0;
}

