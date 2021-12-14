/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/12 9:03:13
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
int n;
int a[1000];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		if(n % 2) cout<<a[n/2 + 1]<<endl;
		else cout<<1.0*(a[n/2] + a[n/2+1]) / 2.0<<endl; 
	}


	return 0;
}

