/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/19 9:23:22
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


int a[1000];
int n,m;
void op1(int l, int r){
	int t;
	while(l < r){
		t = a[l];
		a[l] = a[r];
		a[r] = t;
		l++,r--;
	}
}

void op2(int l , int r){
	int len;
	cin>>len;
	int cnt = 0,t;
	while(cnt < len){
		t = a[l+cnt];
		a[l+cnt] = a[r+cnt];
		a[r+cnt] = t;
		cnt++;
	}
	
}

void op3(int l, int r){
	int x;
	cin>>x;
	for(int i=l; i<=r; i++) a[i] = x;
}
void op4(int l, int r){
	sort(a+l, a+r+1);
}

void op5(int l, int r){
	int ans = 0;
	for(int i=l; i<=r; i++){
		 
		ans += a[i];
	}
	cout<<ans<<endl;
}

int main(){
	cin>>n>>m;
	int op,l,r,x,len;
	for(int i=1; i<=n; i++) cin>>a[i];
	while(m--){
		cin>>op>>l>>r;
		if(op == 1) op1(l,r);
		if(op == 2) op2(l,r);
		if(op == 3) op3(l,r);
		if(op == 4) op4(l,r);
		if(op == 5) op5(l,r);
		for(int i=1; i<=n; i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	

	return 0;
}
/*
9 8
1 2 3 4 5 6 7 8 9
1 4 8
5 7 9
2 2 5 3
5 5 9
3 5 8 3
4 3 8
5 7 9
5 1 9


*/
