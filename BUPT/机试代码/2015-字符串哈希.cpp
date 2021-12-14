/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/17 10:49:38
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
int N,X;
string s;
vector<string> str;
int _hash[100005]; 

int calc(string s){
	int ans = 0;
	for(int i=0; i<s.length(); i++){
		ans += s[i] - 'A';
	}
	return ans;
}
int main(){
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>s;
		str.push_back(s);
		_hash[i] = calc(s);
	}	
	cin>>X;
	for(int i=0; i<N; i++){
		if(_hash[i] == X) cout<<str[i]<<endl;
	}

	return 0;
}
/*
5
AAAA
ABC
ZZ
A
AAA
0

*/
