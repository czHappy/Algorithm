/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/16 10:00:52
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
vector<int> num;
int main(){
	int t;
	cin>>t;
	while(t--){
		num.clear();
		int m,x;
		cin>>m;
		string op;
		while(m--){
			cin>>op;
			if(op[0] =='a'){
				cin>>x;
				num.push_back(x);
			}
			if(op[0] == 'p'){
				num.pop_back();
				
			}
			if(op[0] == 'f'){
				cin>>x;
				if(x > 0) cout<<num[x-1]<<endl;
				else cout<<num[num.size() + x]<<endl;
			}
		}
	} 


	return 0;
}

