/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/18 11:41:45
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
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		for(int i=0; i<s.length(); i++){
			if(i+5 >= s.length()) break;
			if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '1' && s[i+3] == '1' && s[i+4] == '1' && s[i+5] == '0'){
				s.erase(i+5,1);//��ʱָ��i+5ָ�򱻵���Ԫ�ص���һ��
				i = i+4; //ָ��β�����ٴ�ѭ��ʱ��Ҫ��1�����䵽��һ��Ԫ�� 
			}
		}
		cout<<s<<endl; 
	} 


	return 0;
}

