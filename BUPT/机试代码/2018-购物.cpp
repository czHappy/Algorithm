/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/30 11:24:23
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
	int t,n;
	scanf("%d",&t); 
	while(t--){
		scanf("%d",&n);
		double p,ans = 0;
		int c;
		for(int i=0; i<n; i++){
			scanf("%lf %d",&p,&c);
			ans	+= p * c;
		}

		printf("%.2f\n",ans);
	}

	return 0;
}

