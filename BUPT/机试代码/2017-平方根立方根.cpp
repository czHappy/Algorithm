/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/19 9:04:38
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
const double eps = 1e-6;
int main(){
	int t;
//	for(int i=1; i<10; i++) cout<<i*i*i<<endl; 
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans = 0;
		for(int i=1; i*i*i<=n; i++){ //Ҫ��i^3��ƽ������i��Ȼ��ƽ���� 
			if( (sqrt(1.0*i) - (int)sqrt(i)) < eps ) ans++;
		}
		cout<<ans<<endl;
	} 
	

	return 0;
}





//����  ��� �ȴ�1~1000��������  �ٴ�1~4e4��ƽ���� �󽻼� 

