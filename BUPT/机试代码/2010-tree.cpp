/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/2 10:26:14
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
const int maxn = 1000+5;
typedef long long ll;
/*有一棵树，输出某一深度的所有节点，
有则输出这些节点，无则输出EMPTY。
该树是完全二叉树。*/

//第k层有2^{k-1}  起始位置为2^{k-1} 
int n,d;
int a[maxn];
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	cin>>d;
	int lo = pow(2 , d-1);
	int hi = min((lo<<1) - 1 , n);
	if(lo > n){
		cout<<"EMPTY"<<endl;
		return 0;
	}
	else{
		for(int i=lo; i<=hi; i++) cout<<a[i]<<" ";
	}

	return 0;
}

