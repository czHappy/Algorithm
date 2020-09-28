/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/8 8:49:55
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
const int inf = 0x3f3f3f3f;
int m1,m2,n,t;
int a[10000]; 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		m1 = -inf;
		m2 = -inf;
		for(int i=0; i<n; i++){
			cin>>a[i];
			m1 = max(m1 , a[i]);
		}
		for(int i=0; i<n; i++){
			if(a[i] == m1) continue;
			m2 = max(m2 , a[i]);
		}
		cout<<m1<<" "<<m2<<endl;
	}
	return 0;
}

