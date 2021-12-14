/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/18 11:54:41
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
	while(t--){
		ll ans = 0;
		int n,m;
		cin>>n>>m;
		n = sqrt(n);//只需要试到n的平方根 
		for(int i=1; i<=n; i++){
			if(m%i == 0){
				if(m / i == i){ // m = i^2 则i是在对角线上 
					ans += 1;
				}
				else{ //i * (m/i) == m  那么 (m/i) * i == m  ，故而必有两个答案 
					ans += 2;
				}
			}
		}
		cout<<ans<<endl;
		
	} 


	return 0;
}

