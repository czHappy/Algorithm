/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/2 11:56:44
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


/*
>����lower_bound()��first��last�е�ǰ�պ�������ж��ֲ��ң����ش��ڻ����val�ĵ�һ��Ԫ��λ�á��������Ԫ�ض�С��val���򷵻�last��λ��.

>����upper_bound()���ص���ǰ�պ�������ҵĹؼ��ֵ��Ͻ磬���ش���val�ĵ�һ��Ԫ��λ��

*/
int n1,n2;
int a1[1000],a2[1000];

int main(){
	cin>>n1;
	for(int i=0; i<n1; i++) cin>>a1[i];
	cin>>n2;
	for(int i=0; i<n2; i++) cin>>a2[i];
	for(int i=0; i<n2; i++){
		int pos = lower_bound(a1 ,a1 + n1 ,a2[i]) - a1;
		cout<<pos<<endl;
	}

	return 0;
}

