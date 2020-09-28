/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/18 11:37:49
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

int a[55]; 

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans = 0;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					if(a[i] + a[j] == a[k]) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}

