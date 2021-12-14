/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/2 10:31:01
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
//数组模拟进位法
 
string plusx(string s, bool f1, bool f2){
	int c = 0;//进位标志
	int pos = 31;
	if(f1) s[31] += 1;
	if(f2) s[30] += 1;
	while(pos >= 0){
		s[pos] += c;
		c = (s[pos] - '0') / 2;
		s[pos] = (s[pos] - '0') % 2 + '0';
		pos--;
	}
	
	return s;	
}

int main(){
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		cout<<plusx(s,1,0)<<endl;
		cout<<plusx(s,1,1)<<endl;
	}


	return 0;
}

