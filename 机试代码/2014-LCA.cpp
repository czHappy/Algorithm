/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/11 17:20:35
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
const int maxn = 1e2+10;
const int M = 1e3+10;
int n,m;

//��ʽǰ���ǽ�ͼ
int head[maxn];
int cnt;
struct node{
	int v;
	int nxt;
	int w;
}edge[maxn*2];//������˫������Կ�������С 

void addEdge(int u, int v){
	edge[cnt].v = v;
	edge[cnt].nxt = head[u];
	head[u] = cnt++;
}

bool vis[maxn];

//��ѯ�ʽ�ͼ
int headq[maxn];
int cntq;
struct nodeq{
	int u,v;
	int nxt;
	int id;//�����ǵڼ���ѯ�� 
}query[M*2];

void addQ(int u, int v, int idx){
	query[cntq].u = u;
	query[cntq].v = v;
	query[cntq].id = idx;
	query[cntq].nxt = headq[u];
	headq[u] = cntq++;
}

int lca[M];

// ���鼯��������
int fa[maxn];
void init(){
	for(int i=1; i<=n; i++){
		fa[i] = i;
		vis[i] = 0;
		head[i] = 0;
		headq[i] = 0;
	}
	cnt = 1;
	cntq = 1;
} 

int find(int x){
	if(x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}
 
void merge(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) fa[fy] = fx;
}

void tarjan(int u){
	vis[u] = 1;
	//�ݹ��������u 
	for(int i=head[u]; i; i=edge[i].nxt){
		int v = edge[i].v;
		if(!vis[v]){
			tarjan(v);
			merge(u, v);//u�϶���v�ĸ��ף���v������u�� 
		}
	}
	
	//���u������� ��������ѯ�ʹ�ϵ�Ľ�� 
	for(int i=headq[u]; i; i=query[i].nxt){
		int v = query[i].v;
		//�����һ�˵��Ѿ����ʹ�����ôlca����ȷ�����䵱ǰ��father 
		if(vis[v]) lca[query[i].id] = find(v);
	}
}


int main(){
	int t,u,v;
	cin>>t;
	while(t--){
		cin>>n;
		init();
		for(int i=1; i<n; i++){
			cin>>u>>v;
			addEdge(u,v);
			addEdge(v,u);
		}
		cin>>m;
		for(int i=1; i<=m; i++){
			cin>>u>>v;
			addQ(u,v,i);//ͬ����i����ѯ 
			addQ(v,u,i);
		}
		tarjan(1);//ָ�����ڵ�Ϊ1 
		for(int i=1; i<=m; i++) cout<<lca[i]<<endl;
	} 


	return 0;
}

