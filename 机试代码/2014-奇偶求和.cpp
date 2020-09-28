/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/11 14:19:15
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
	cin>>t;
	while(t--){
		int sum1,sum2,x;
		sum1 = sum2 = 0;
		cin>>n;
		while(n--){
			cin>>x;
			if(x % 2) sum1 += x;
			else sum2 += x;
		}
		cout<<sum1<<" "<<sum2<<endl; 
	} 


	return 0;
}

