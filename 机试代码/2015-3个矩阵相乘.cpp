/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/17 10:14:42
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

int n = 5; 
struct Matrix{
	int n,m; //行数n 列数m 
	long long ma[15][15];
};

Matrix multi(Matrix a, Matrix b){
	Matrix ans;//存放结果矩阵
	if(a.m != b.n){ //必须保证a的列数等于b的行数 
		cout<<"ERROR"<<endl;
		return ans;
	}
	//结果矩阵的维数 
	ans.n = a.n;
	ans.m = b.m; 
	memset(ans.ma , 0 , sizeof ans.ma);
	for(int i=0; i<a.n; i++){
		for(int j=0; j<b.m; j++){
			for(int k=0; k<a.m; k++){
				ans.ma[i][j] += a.ma[i][k] * b.ma[k][j]; 
			}
		}
	} 
	return ans;
}

/*
1
1 2 3 4 5
6 5 8 9 7
6 5 7 8 4
5 6 3 2 1
2 3 1 4 5

1 2 3 4 5
3 2 1 4 5
6 5 4 1 2
6 2 1 4 5
3 2 1 3 4

7 8 9 6 3
1 2 4 5 6
3 2 1 4 5
3 2 1 8 6
3 0 0 1 0

*/
int main(){
	int t; 
	cin>>t;
	while(t--){
		/* test
		Matrix p,q;
		p.n = 3;
		p.m = 2;
		q.n = 2;
		q.m = 4;
		for(int i=0; i<p.n; i++){
			for(int j=0; j<p.m; j++){
				cin>>p.ma[i][j];
			}
		}
		for(int i=0; i<q.n; i++){
			for(int j=0; j<q.m; j++){
				cin>>q.ma[i][j];
			}
		}
		
		p = multi(p , q);
		for(int i=0; i<p.n; i++){
			for(int j=0; j<q.m; j++){
				cout<<p.ma[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
		Matrix a,b,c,ans;
		a.n = b.n = c.n = n;
		a.m = b.m = c.m = n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>a.ma[i][j];
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>b.ma[i][j];
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>c.ma[i][j];
			}
		}
		ans = multi(a , b);
		ans = multi(ans , c);
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<ans.ma[i][j]<<" ";
			}
			cout<<endl;
		}
	}


	return 0;
}

