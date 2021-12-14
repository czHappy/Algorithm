/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/2 18:50:33
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
const int maxn = 105;
const int inf = 0x7fffffff;
int n,m;
int dist[maxn][maxn];

void init(){
	for(int i=0; i<maxn; i++){
		for(int j=0; j<maxn; j++){
			dist[i][j] = inf>>1; //这里最好是inf/2 因为floyd中有两数相加，可能超过inf造成溢出成负数，结果错误 
		}
		dist[i][i] = 0;
	}
}


void floyd(){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
				//cout<<"dist (i,j) = "<<dist[i][j]<<" ";
			}
			//cout<<endl;
		}
	}
}


int main(){
	int t,x,y;
	cin>>t;
	while(t--){
		init();
		cin>>n>>m;
		for(int i=1; i<=n; i++){
			cin>>x>>y;
			if(x!=-1) dist[i][x] = dist[x][i] = 1;
			if(y!=-1) dist[i][y] = dist[y][i] = 1;
		}
		floyd();
		while(m--){
			cin>>x>>y;;
			cout<<dist[x][y]<<endl;
		}
	}


	return 0;
}

