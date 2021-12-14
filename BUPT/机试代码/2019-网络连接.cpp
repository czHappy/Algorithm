/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/1 21:53:33
  Description:
*/
/*
最小生成树
1. prim算法
有点像最短路迪杰斯特拉，区别是kruscal点集合S加入新点时，选取未在集合S中的离S最近的点 
迪杰斯特拉是选取到源点最短点加入集合S并更新所有点离源点距离 
 
2. 克鲁斯卡尔算法
排边加边不成环，用到并查集 
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
const int inf = 0x7fffffff;
int G[maxn][maxn];
int dist[maxn]; //dist[i]表示顶点i到集合S的距离 
bool vis[100];//集合S 
int n,m;
int sum; //最小生成树代价 
int prim(int s){ //传入任意起始点s 
	sum = 0;
	for(int i=1; i<=n; i++) dist[i] = G[i][s];
	memset(vis, 0, sizeof vis);
	vis[s] = 1;
	for(int i=1; i<n; i++){ //选取n-1轮次 
		int v;
		int minx = inf; 
		for(int j=0; j<n; j++){ //看哪一个点离集合S最小 
			if(!vis[j] && minx > dist[j]){
				minx = dist[j];
				v = j;
			}
		}
		vis[v] = 1;//选出的顶点v加入集合S 
		sum += minx;
		
		for(int j=0; j<n; j++){
			if(!vis[j] && dist[j] > G[v][j]){
				dist[j] = G[v][j];
			}
		} 
	}

} 



int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>G[i][j];	
			}	
		} 
		prim(0);
		cout<<sum<<endl;
	} 


	return 0;
}

