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
int dist[maxn];//�������� 
int G[maxn][maxn]; //w[i][j]Ϊi->j��Ȩ 
bool vis[maxn];//������ʱ�־ ʵ������S���� 
int s,e;// Դ�� �յ�
int n,m,k;//total vertex , edge and targets

int tar[20];//Ŀ������ 
vector<int> tmp;//�����ʱ���� 
int cnt=0;//���м��� 
bool used[20];// ���з��ʱ�־ 
vector<int> order[4000000];//ȫ���н�� 

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
	memset(vis , 0, sizeof vis);//���S���� 
	for(int i=1; i<=n; i++){ //��ʼ��dist 
		dist[i] = G[s][i];
	}
	vis[s] = 1;//Դ�����S���� 
	for(int i=1; i<n; i++){ //n-1���ɳ� 
		int minx = inf;
		int pos;//����һ����Դ������ĵ� ׼������S���� 
		for(int j=1; j<=n; j++){
			if(!vis[j] && dist[j] < minx){
				minx = dist[j];
				pos = j;
			}
		} 
		vis[pos] = 1; //�ö������S���� 
		
		for(int k=1; k<=n; k++){ //��S������ĵ�����ɳڲ��� ����pos������Դ����� 
			if(!vis[k] && dist[k] > dist[pos] + G[pos][k]){
				dist[k] = dist[pos] + G[pos][k];
			}
		}
	}
}


void permu(int c){ //permu ��c������ 
	if(c > k){ //������е�λ�ö���ö����� ��õ�һ���µ����� 
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
		if(!used[i]){ //�����i������û������ô�Ϳɼ����������� 
			used[i] = 1;//��i�������Ѿ�����   �����ѷ��ʱ�־ 
			tmp.push_back(tar[i]);
			permu(c+1);//ö����һ��λ�� 
			used[i] = 0;//���ѷ��غ��־����
			tmp.pop_back();
		}
	} 
}

int k_dist[20][maxn]; //k_dist[i][j]��ʾi��j����̾��� 
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
		permu(1);//�����k��Ŀ���ȫ���� ��cnt�� 
		//����k��Ŀ��֮��ľ���
		for(int i=0; i<k; i++){
			dijkstra(tar[i]);
			for(int j=1; j<=n; j++) k_dist[tar[i]][j] = dist[j];
		} 
		dijkstra(1); //����Դ�㵽�������̾��� 
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

