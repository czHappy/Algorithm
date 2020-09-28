/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/3 10:24:26
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
vector<int> G[maxn]; 

int main(){
	int T,n,m,a,b;
	cin>>T;
	int cas = 1;
	while(cas <= T){
		for(int i=0; i<maxn; i++) G[i].clear();
		cin>>n>>m;
		for(int i=0; i<n; i++){
			cin>>a>>b;
			G[b].push_back(a);
		}
		queue<int> q;
		q.push(1);
		int cur = 1;
		int nxt = 0;
		cout<<"Q"<<cas<<":"<<endl;
		while(!q.empty()){
			int fr = q.front();
			q.pop();
			cur--;
			cout<<fr<<" ";
			for(int i=0; i<G[fr].size(); i++){
				q.push(G[fr][i]);
				nxt++;
			} 
			if(cur == 0){
				cout<<endl;
				cur = nxt;
				nxt = 0;
			}
		}
		cas++;
	}


	return 0;
}

