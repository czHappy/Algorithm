/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/13 21:33:09
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

struct node{
	int id;
	int size;
} mem[500];
bool cmp(node a, node b){
	if(a.size == b.size) return a.id < b.id;

	return a.size < b.size;
}
bool vis[500];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(vis , 0 , sizeof vis);
		for(int i=1; i<=n; i++){
			mem[i].id = i;
			cin>>mem[i].size;
		}
		sort(mem+1, mem+n+1, cmp);
		int m,x;
		cin>>m;
		for(int i=1; i<=m; i++){
			cin>>x;
			bool flag = 0;
			for(int j=1; j<=n; j++){
				if(mem[j].size >= x && !vis[j]){
					cout<<mem[j].size<<" ";
					vis[j] = 1;
					flag = 1;
					break;
				}
			}
			if(!flag) cout<<"NULL"<<" ";
		}
		cout<<endl;
	}


	return 0;
}

