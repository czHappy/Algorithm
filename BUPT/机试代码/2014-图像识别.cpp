/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/15 8:22:25
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
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};; 

int t,n,m;
int G[maxn][maxn]; 
int D;
bool vis[maxn][maxn];

bool inG(int x, int y){
	if(x >= 1 && x <= n && y >= 1 && y <= m) return true;
	return false;
}

void dfs(int ux, int uy){
	for(int i=0; i<4; i++){
		int vx = ux + dx[i];
		int vy = uy + dy[i];
		if(!inG(vx, vy)) continue;
		if(!vis[vx][vy] && abs(G[vx][vy] - G[ux][uy]) <= D)  {
			vis[vx][vy] = 1;
			dfs(vx, vy);
		}
		
	}
}


int getConnNum(){
	int ans = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(!vis[i][j]){
				vis[i][j] = 1;
				dfs(i , j);
				ans++;
			}
		}
	}
	return ans;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>D;;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				cin>>G[i][j];
			}
		}
		
		memset(vis ,0 , sizeof vis);
		
		cout<<getConnNum()<<endl;
	}
	return 0;
}
/*
	i   j 
ио  -1  0
об  1   0
вС  0   -1
ср  0   1 */
