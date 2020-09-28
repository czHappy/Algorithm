/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/11 14:23:19
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

int a[105];
int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		int d;
		if(n == 1){
			cout<<1<<endl;
			continue;
		}
		d = a[1] - a[0];
		int tmp = 2;
		int ans = 2;
		for(int i=2; i<n; i++){
			if(a[i] - a[i-1] == d) tmp++;
			else{
				ans = max(ans , tmp);
				tmp = 2;
				d = a[i] - a[i-1];
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}

