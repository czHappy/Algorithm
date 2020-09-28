/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/1 21:53:33
  Description:
*/
/*
��С������
1. prim�㷨
�е������·�Ͻ�˹������������kruscal�㼯��S�����µ�ʱ��ѡȡδ�ڼ���S�е���S����ĵ� 
�Ͻ�˹������ѡȡ��Դ����̵���뼯��S���������е���Դ����� 
 
2. ��³˹�����㷨
�ű߼ӱ߲��ɻ����õ����鼯 
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
int dist[maxn]; //dist[i]��ʾ����i������S�ľ��� 
bool vis[100];//����S 
int n,m;
int sum; //��С���������� 
int prim(int s){ //����������ʼ��s 
	sum = 0;
	for(int i=1; i<=n; i++) dist[i] = G[i][s];
	memset(vis, 0, sizeof vis);
	vis[s] = 1;
	for(int i=1; i<n; i++){ //ѡȡn-1�ִ� 
		int v;
		int minx = inf; 
		for(int j=0; j<n; j++){ //����һ�����뼯��S��С 
			if(!vis[j] && minx > dist[j]){
				minx = dist[j];
				v = j;
			}
		}
		vis[v] = 1;//ѡ���Ķ���v���뼯��S 
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

