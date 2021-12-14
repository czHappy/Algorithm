/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/10 21:34:57
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

ll gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b , a%b);
} 

int main(){
	ll a,b;
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		ll a1 = pow(2 , a);
		ll b1 = pow(2 ,b);
		ll fm = max(a1, b1);
		ll fz = fm / min(a1 , b1) + 1;
		ll com = gcd(fm , fz);
		fm /= com;
		fz /= com;
		cout<<fz<<"/"<<fm<<endl;
	}


	return 0;
}

