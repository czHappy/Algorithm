/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/1 11:00:24
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
	int t;
	cin>>t;
	int a,b,c,d;
	while(t--){
		cin>>a>>b>>c>>d;
		int m = min(a,b);
		int n = min(c,d);
		cout<<min(m,n)<<endl;
	} 


	return 0;
}

