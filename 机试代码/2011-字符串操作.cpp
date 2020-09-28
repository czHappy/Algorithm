/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/2 16:48:41
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
	string s,tmp;
	int t,i,len;
	int op;
	cin>>s;
	cin>>t;
	while(t--){
		cin>>op>>i>>len;
		if(op == 0){
			tmp = s;
			for(int j=i,k=i+len-1; j<i+len; j++,k--){
				s[j] = tmp[k];
			}
		}
		else{
			cin>>tmp;
			for(int j=i,k=0; j<i+len; j++){
				s[j] = tmp[k++];
			}
		}
		cout<<s<<endl;
	}


	return 0;
}

