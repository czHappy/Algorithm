/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/8 9:01:28
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
const int inf = 0x3f3f3f3f;

//���о�a-z���н������һ�鿴˭�Ļ���С 

int calc(char a, char b){ //a -> b ����Ҫ�Ļ��� 
	return min( (b - a + 26) % 26 , (a - b + 26) % 26 ); 
}

int main(){
	int t;
	string s;
	cin>>t;
	
	while(t--){
		int ans = inf;
		cin>>s;
		for(int i=0; i<26; i++){
			char x = 'a' + i;
			//cout<<"x = "<<x<<endl;
			int sum = 0;
			for(int j=0; j<s.size(); j++){
				sum += calc(s[j] , x);
			}
			//cout<<"sum = "<<sum<<endl;
			ans = min(ans , sum);
		}
		cout<<ans<<endl;
	}


	return 0;
}

