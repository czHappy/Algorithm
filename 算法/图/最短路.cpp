/*
  Name: �Ͻ�˹���� 
  CopyRight:
  Author: Cz
  Date: 2019/8/27 21:07:00
  Description:
*/

/*
�㷨
void dijkstra(G,v0,dist){
	init S = {v0} dist[i] = G[v0][i]
	while(S != V)
		for(vj in V-S) 
			if dist[j] is the minimum value of distance between v0 and V-S
			then 
				S = S union {j}
		for v in next[j] //v����V-S����һ����
			 update dist[v] with dist[v] and G[j][v] 
			
} 

������ķ�㷨����ϵ������
1. ����ķ�еľ�����S�������嵽v�ľ��룬���Ͻ�˹�����ľ�����v0��v�ľ���
2. ǰ�߸��¾��������¼���Ķ���Ϊ���ĸ����������㵽���ľ��룬�Դ˸��¼���S��������룬
����Ҳ�����¼���Ķ���Ϊ���ĸ����������㵽Դ��ľ��� 
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
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+10;
int dis[maxn];
int G[maxn][maxn];
int n,m;//n����� m����
bool vis[maxn];
void dijkstra(int s){
    memset(vis , 0 , sizeof vis);
    rep(i,1,n){
        dis[i] = G[s][i];
    }
    vis[s] = 1;//s����S����

    //ֻ��Ҫ�ٽ�n-1�������S����
    rep(i, 1 , n-1){
        int minx = inf;//����ÿһ���ҵ㣬��Ҫ�ҵ�ǰ���·�ĵ�
        int pos;//��¼һ�����ĸ���
        rep(j , 1 , n){ //����ʵ���Ͽ����ö��Ż� 
            if(!vis[j] && dis[j] < minx){
                minx = dis[j];
                pos = j;
            }
        }
        //pos�������S����
        vis[pos] = 1;
        //����pos����Ľ��� ��S��������Ľ�� �������Ϊpos�ļ�����Ҫ���и���
        rep(k, 1 , n){ //��S��������ĵ��ɳڲ��� 
            if(!vis[k] && dis[k] > dis[pos] + G[pos][k]){
                dis[k] = dis[pos] + G[pos][k];
            }
        }
    }
}


int main(){
    int x,y,w;
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        //��ʼ��
        rep(i,1,n)
        rep(j,1,n){
            if(i == j) G[i][j] = 0;
            else G[i][j] = inf;
        }
        rep(i,1,m){
            cin>>x>>y>>w;
            G[x][y] = w;
            G[y][x] = w;
        }
        dijkstra(1);
        //rep(i,1,n) cout<<dis[i]<<" ";
        int e;
        while(cin>>e)
            cout<<dis[e]<<endl;
    }
    return 0;
}

