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
/*��һ���������ĳһ��ȵ����нڵ㣬
���������Щ�ڵ㣬�������EMPTY��
��������ȫ��������*/

//��k����2^{k-1}  ��ʼλ��Ϊ2^{k-1} 
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

