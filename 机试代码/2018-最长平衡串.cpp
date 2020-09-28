/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/28 19:44:14
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
const int maxn = 1e6+10;
int dp[maxn];
string s;
int solve(string s){
	int ans = 0;
	if(s[0] == '0') dp[0] = -1;
	else dp[0] = 1;
	for(int i=1; i<s.size(); i++){
		if(s[i] == '0'){
			dp[i] = dp[i-1] - 1;
		}
		else{
			dp[i] = dp[i-1] + 1;
		}
	}
	for(int i=0; i<s.length(); i++) cout<<dp[i]<<" ";
	cout<<endl;
	map<int, int> mp; //map[value] = first_pos ����λ����dp������+1 
	
	for(int i=0; i<s.length(); i++){
		if(mp[dp[i]] != 0){
			ans = max(ans , i + 1 - mp[dp[i]]); 
		}
		else{
			mp[ dp[i] ] = i + 1; 
		}
		//���� ��dp[i]����0����˵��[0,i]����ƽ��ģ���Ҫ����Ϊ0���ֵ��map�ϲ��ø�ֵ�� 
		if(i != 0 && dp[i] == 0) ans = max(ans , i+1);
	} 
	
	return ans;
	
}


int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		cout<<solve(s)<<endl;
	} 


	return 0;
}

