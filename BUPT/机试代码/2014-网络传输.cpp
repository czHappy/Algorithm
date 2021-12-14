/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/11 10:24:42
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
const int maxn = 1e3+10;
const int inf = 0x3f3f3f3f;
int dist[maxn];//距离向量 
int G[maxn][maxn]; //w[i][j]为i->j边权 
bool vis[maxn];//顶点访问标志 实质上是S集合 
int s,e;// 源点 终点
int n,m,k;//total vertex , edge and targets

int tar[20];//目标数字 
vector<int> tmp;//存放临时排列 
int cnt=0;//排列计数 
bool used[20];// 排列访问标志 
vector<int> order[4000000];//全排列结果 

ll ans,minn;
void init(){
	dist[s] = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			if(i == j) G[i][j] = 0;
			else G[i][j] = inf;
	}
	for(int i=0; i<=cnt; i++) order[i].clear();
	cnt = 0;
	tmp.clear();
	memset(used,0,sizeof used); 
	ans = 0;
	minn = inf;
} 

void dijkstra(int s){
	memset(vis , 0, sizeof vis);//清空S集合 
	for(int i=1; i<=n; i++){ //初始化dist 
		dist[i] = G[s][i];
	}
	vis[s] = 1;//源点加入S集合 
	for(int i=1; i<n; i++){ //n-1轮松弛 
		int minx = inf;
		int pos;//找下一个离源点最近的点 准备加入S集合 
		for(int j=1; j<=n; j++){
			if(!vis[j] && dist[j] < minx){
				minx = dist[j];
				pos = j;
			}
		} 
		vis[pos] = 1; //该顶点加入S集合 
		
		for(int k=1; k<=n; k++){ //对S集合外的点进行松弛操作 利用pos更新离源点距离 
			if(!vis[k] && dist[k] > dist[pos] + G[pos][k]){
				dist[k] = dist[pos] + G[pos][k];
			}
		}
	}
}


void permu(int c){ //permu 第c个数字 
	if(c > k){ //如果所有的位置都已枚举完毕 则得到一个新的排列 
	cout<<"size = "<<tmp.size()<<endl;
		for(int i=0; i<k; i++){
			order[cnt].push_back(tmp[i]);
			cout<<tmp[i]<<" "; 
		}
		cout<<endl;
		cnt++;
		return ;
	}
	for(int i=0; i<k; i++){
		if(!used[i]){ //如果第i个数字没有用那么就可继续往下排列 
			used[i] = 1;//第i个数字已经用了   打上已访问标志 
			tmp.push_back(tar[i]);
			permu(c+1);//枚举下一个位置 
			used[i] = 0;//深搜返回后标志清零
			tmp.pop_back();
		}
	} 
}

int k_dist[20][maxn]; //k_dist[i][j]表示i到j的最短距离 
int main(){
	int t,u,v,w;
	cin>>t;
	while(t--){
		
		cin>>n>>m>>k;
		init();
		for(int i=0; i<m; i++){
			cin>>u>>v>>w;
			G[u][v] = w;
			G[v][u] = w;
		}
		for(int i=0; i<k; i++) cin>>tar[i];
		permu(1);//计算出k个目标的全排列 共cnt个 
		//计算k个目标之间的距离
		for(int i=0; i<k; i++){
			dijkstra(tar[i]);
			for(int j=1; j<=n; j++) k_dist[tar[i]][j] = dist[j];
		} 
		dijkstra(1); //计算源点到各点的最短距离 
		for(int i=0; i<cnt; i++){
			ans = 0;
			ans += dist[ order[i][0] ];
			for(int j=0; j<order[i].size(); j++){
				if(j+1 < order[i].size()){
					ans += k_dist[ order[i][j] ][ order[i][j+1] ];
				}
			}
			minn = min(minn , ans);
		} 
		cout<<minn<<endl;
	} 

	return 0;
}

