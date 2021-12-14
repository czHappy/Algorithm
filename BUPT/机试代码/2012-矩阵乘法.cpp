/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/4 9:32:22
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
int mat[15][15];
int base[15][15];
int re[15][15];
int n,k;

void powM(int k){
	if(k==0){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				re[i][j] = mat[i][j];	
			}
		}
	} 
	while(k--){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				re[i][j] = 0;
				for(int s=0 ; s<n; s++)
					re[i][j] += mat[i][s] *  base[s][j];
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				mat[i][j] = re[i][j];	
			}
		}
	}
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(re , 0, sizeof re);
		cin>>n>>k;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>mat[i][j];
				base[i][j] = mat[i][j];
			}
		}
		powM(k-1);
			
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<re[i][j]<<" ";
			}
			cout<<endl;
		}
		
		
	}


	return 0;
}



