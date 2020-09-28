/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/3 10:21:23
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
	int T;
	cin>>T;
	while(T--){
		map<char , int > mp;
		char x;
		cin>>x;
		string s;
		cin>>s;
		for(int i=0; i<s.length(); i++){
			mp[s[i]]++;
		}
		cout<<mp[x]<<endl;
	} 


	return 0;
}

