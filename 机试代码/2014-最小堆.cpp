/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/10 21:43:20
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

vector<int> G[1000];
int w[1000];
int main(){

	int t;
	cin>>t;
	while(t--){
		int n,u,v;
		cin>>n;
		for(int i=1; i<=n; i++){			
			cin>>w[i];
			G[i].clear();
		}
		for(int i=1; i<n; i++){
			cin>>u>>v;
			G[u].push_back(v); 
		}
		bool f = 1;
		for(int i=1; i<=n; i++){
			for(int j=0; j<G[i].size(); j++){
				if(w[i] > w[G[i][j]]){
					f = 0;
					break;
				}
			}
		}
		if(f) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	} 

	return 0;
}

