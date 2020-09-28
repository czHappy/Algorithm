/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/11 8:48:31
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

const int maxn = 1e3;
vector<int> G[maxn];
bool exist[maxn]; 


void kill(int x){
	for(int i=0; i<G[x].size(); i++){
		exist[G[x][i]] = 0;
		kill(G[x][i]);
	}
	G[x].clear();
	exist[x] = 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0; i<maxn; i++){
			G[i].clear();
			exist[i] = 0;
		} 
		exist[0] = 1;
		int n;
		cin>>n;
		string s;
		int a , b;
		while(n--){
			cin>>s;
			if(s[0] == 'Q'){
				cin>>a;
				if(exist[a]) cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
 			}
			if(s[0] == 'F'){
				cin>>a>>b;
				exist[b] = 1;
				G[a].push_back(b);	
			}
			if(s[0] == 'K'){
				cin>>a;
				kill(a);
			}
		}
	}


	return 0;
}
/*
11
199
FORK 0 1
FORK 1 2
FORK 2 3
FORK 2 6
FORK 6 7
FORK 1 4
FORK 0 5
QUERY 5
KILL 2
QUERY 3
QUERY 1



*/
