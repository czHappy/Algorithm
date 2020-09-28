/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/6 10:51:45
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

bool isLeap(int year){
	if(year % 100 && !(year % 4)) return true;
	if(!(year % 100) && !(year % 400)) return true;
	return false;
} 

int days[13];
int main(){
	days[1] = 31;
	days[2] = 28;
	days[3] = 31;
	days[4] = 30;
	days[5] = 31;
	days[6] = 30;
	days[7] = 31;
	days[8] = 31;
	days[9] = 30;
	days[10] = 31;
	days[11] = 30;
	days[12] = 31;
	int T;
	int a,b,c;
	scanf("%d",&T);
	while(T--){
		int sum = 0;
		scanf("%d:%d:%d", &a,&b,&c);
		if(isLeap(a)) days[2] = 29;
		else days[2] = 28;
		for(int i=1; i<b; i++) sum += days[i];
		cout<<"sum1="<<sum<<" ; a b c :"<<a<<b<<c<<endl;
		sum += c;
		cout<<sum<<endl;
	}


	return 0;
}

