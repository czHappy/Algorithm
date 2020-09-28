/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/6 11:04:21
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

const int maxn = 200;
int T;
int n;
vector<int> fa[maxn];
vector<int> son[maxn];
int in[maxn];
int out[maxn];
int de[maxn];
bool isP(int x){
	//先检查父亲 
	for(int j = 0; j<fa[x].size(); j++){
		if(de[x] < de[ fa[x][j] ]) return 0;
	}
	//再检查儿子 
	for(int j = 0; j<son[x].size(); j++){
		if(de[x] < de[ son[x][j] ]) return 0;
	}
	return 1; 
	
}

int main(){
	cin>>T;
	int u,v;
	while(T--){
		cin>>n;
		for(int i=0; i<maxn; i++){
			in[i] = 0;
			out[i] = 0;
			de[i] = 0;
			son[i].clear();
			fa[i].clear();
		}
		for(int i=1; i<n; i++){
			cin>>u>>v;
			fa[v].push_back(u);
			son[u].push_back(v);
			in[v]++;
			out[u]++;
		}
		for(int i=0; i<n; i++) de[i] = in[i] + out[i];
		int ans = 0;
		for(int i=0; i<n; i++){
			if(isP(i)) ans++;
		}
		cout<<ans<<endl;
	}


	return 0;
}

