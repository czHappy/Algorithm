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
>函数lower_bound()在first和last中的前闭后开区间进行二分查找，返回大于或等于val的第一个元素位置。如果所有元素都小于val，则返回last的位置.

>函数upper_bound()返回的在前闭后开区间查找的关键字的上界，返回大于val的第一个元素位置

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

