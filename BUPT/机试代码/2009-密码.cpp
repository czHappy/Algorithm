/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/2 11:49:23
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
//b a c e u  f g h i j  k l m n o  p q r s t  v w x y z  d
int main(){
	char t[100];
	string s;
	for(int i=1; i<=26; i++) cin>>t[i];
	cin>>s;
	for(int i=0; i<s.length(); i++){
		s[i] = t[s[i] - 'A' + 1];
	}
	cout<<s<<endl;
	return 0;
}

