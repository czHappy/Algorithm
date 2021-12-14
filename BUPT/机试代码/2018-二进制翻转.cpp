/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/28 17:09:20
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

int main(){
	ll x;
	int t;
	cin>>t;
	int a[40];
	while(t--){
		memset(a , 0 , sizeof a);
		cin>>x;
		int i=0;
		while(x){
			a[i++] = x % 2;
			x >>= 1;
		}
		ll re = 0;
		for(i=0; i<32; i++){
			re = (re << 1) + a[i];
		}
		cout<<re<<endl;
	} 

	return 0;
}

