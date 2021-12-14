/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/8 8:54:03
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
	int m1,s1,m2,s2;
	int k1,k2;
	scanf("%d",&t);
	while(t--){
		scanf("%d:%d",&m1,&s1);
		scanf("%d:%d",&m2,&s2);
		k1 = m1*60 + s1;
		k2 = m2*60 + s2;
		cout<<(k2 - k1 + 1440) % 1440<<endl;; 
	} 
	return 0;
}

