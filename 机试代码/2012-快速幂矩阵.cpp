/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/4 10:10:34
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

int n;//矩阵维数 
int k;//幂次 
//快速幂
long long qpow(long long a, long long n){
	long long ans = 1;
	while(n > 0){
		if(n&1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
} 

//快速幂矩阵 

struct Matrix{
	long long ma[15][15];
};

Matrix multi(Matrix a, Matrix b){
	Matrix ans;//存放结果矩阵
	memset(ans.ma , 0 , sizeof ans.ma);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				ans.ma[i][j] += a.ma[i][k] * b.ma[k][j]; 
			}
		}
	} 
	return ans;
}

Matrix pow(Matrix a, int x){
	Matrix ans;
	memset(ans.ma , 0 , sizeof ans.ma);
	for(int i=0; i<n; i++) ans.ma[i][i] = 1;//单位阵初始化
	while(x){
		if(x & 1) ans = multi(ans, a);
		a = multi(a , a);
		x >>= 1;
	} 
	return ans;	
}


int main(){
	int t; 
	cin>>t;
	while(t--){
		cin>>n>>k;
		Matrix x,ans;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>x.ma[i][j];
			}
		}
		ans = pow(x , k);
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<ans.ma[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}

//3 2 2 9 8 9 3 

