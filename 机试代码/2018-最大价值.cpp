/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/30 21:09:37
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
const int maxn = 2e4+10;
int n,x,y,z;
struct node{
	int pos;
	bool L;
	int val;	
}T[maxn<<1];

bool cmp(node a, node b){
	if(a.val == b.val){
		return a.pos < b.pos;
	}
	return a.val < b.val;
}

int main(){
	cin>>n>>x>>y>>z;
	for(int i=0; i<2*n; i++){		
		T[i].pos = i;
		cin>>T[i].val; //偶数是左端点 奇数是右端点
		if(i % 2) T[i].L = 0;
		else T[i].L = 1;
	}
	sort(T, T+2*n, cmp);
	
	ll sum = n*x;
	ll ans = n*x;
	for(int i=0; i<2*n; i++){
		if( T[i].L ) sum += y - x;
		else sum -= y - z;
		ans = max(ans , sum);
	}
	cout<<ans<<endl;
	return 0;
}

