/*
  Name:ͼ�ı��� 
  CopyRight:
  Author: Cz
  Date: 2019/10/3 19:34:26
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

const int maxn = 100;
vector<int> G[maxn];
bool visit[maxn];
int n;//������ 
int m;//���� 
queue<int> Q;//bfs���� 

void dfs(int u){
	cout<<"dfs���� "<<u<<endl;
	visit[u] = 1; 
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(!visit[v]){
			dfs(v);
		}
	} 
}

void DFStravel(){
	memset(visit , 0 , sizeof visit);
	for(int i=1; i<=n; i++){
		if(!visit[i]) dfs(i);
	}
}

void bfs(int u){
	visit[u] = 1;
	Q.push(u);
	while(!Q.empty()){
		int v = Q.front();
		cout<<"bfs����"<<v<<endl;
		Q.pop();
		for(int i=0; i<G[v].size(); i++){
			int w = G[v][i];
			if(!visit[w]) {
				Q.push(w);
				visit[w] = 1;//�����м����Ϸ��ʱ�� 
			} 
		}	
	} 
}

void BFStravel(){
	memset(visit , 0 , sizeof visit);
	while(!Q.empty()) Q.pop();
	for(int i=1; i<=n; i++){
		if(!visit[i]) bfs(i);
	}
	
}
int main(){
	while(cin>>n>>m){
		for(int i=0; i<m; i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);//����ͼ 
		}
	//	DFStravel();
		BFStravel();
		for(int i=0; i<maxn; i++) G[i].clear();
	}
	
	
	return 0;
}

/*
5  6
1 2
1 4
2 3
3 4
2 5
3 5

*/

