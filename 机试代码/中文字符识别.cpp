/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/15 10:29:37
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

int main(){
	string s = "abc£¬d9987";
	for(int i=0; i<s.length(); i++) 
		if(s[i] == '£¬') cout<<"YES"<<endl; 
	
	for(int i=0; i<s.length(); i++) 
		cout<<s[i]<<endl;
		
	for(int i=4; i<s.length(); i++) 
		cout<<s[i]<<endl;
	return 0;
}

