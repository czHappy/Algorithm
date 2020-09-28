/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/30 11:38:14
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
int a[100];
int t,n; 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++) cin>>a[i];
		if(n < 3){
			cout<<0<<endl; 	
			continue;
		} 
		int cnt = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				for(int k=j+1; k<n; k++){
					if(a[j] < a[i] && a[j] < a[k]){
						cnt++;
					}
				}
			}
			
		}
		cout<<cnt<<endl;
	}

	return 0;
}

