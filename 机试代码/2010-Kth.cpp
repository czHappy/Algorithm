/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/2 10:04:19
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
const int maxn = 1000;
typedef long long ll;
int n,x,k;
int a[maxn];
int main(){
	while(cin>>n){
		for(int i=0; i<n; i++) cin>>a[i];
		cin>>k;
		sort(a,a+n);
		int b = unique(a,a+n) - a;
		cout<<a[k-1]<<endl;
		
	}


	return 0;
}

