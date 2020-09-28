/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/4 9:28:20
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
int a[10000];
int main(){
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		int cnt = 0;
		while(x){
			int r = x % 2;
			x = x >> 1;
			a[cnt++] = r;
		}
		for(int i = cnt-1; i>=0; i--) cout<<a[i];
		cout<<endl;
	} 


	return 0;
}

