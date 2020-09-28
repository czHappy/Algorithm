/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/30 13:36:53
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
const double eps = 1e-8;

double a,b,c,d;

double calc(double a, double b, int op){
	if(op == 0) return a+b;
	if(op == 1) return a-b;
	if(op == 2) return a*b;
	return a / b;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		double ans;
		cin>>a>>b>>c>>d;
		bool flag = 0;
		for(int i=0; i<4; i++){
			if(flag) break;
			for(int j=0; j<4; j++){
				if(flag) break;
				ans = 0;
				for(int k=0; k<4; k++){
					ans = calc(a, b, i);
					ans = calc(ans, c, j);
					ans = calc(ans , d , k);
					if(fabs(ans - 24) < eps){
						flag = 1;
						break;
					}	
				}
				
				
			}	
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}


	return 0;
}

