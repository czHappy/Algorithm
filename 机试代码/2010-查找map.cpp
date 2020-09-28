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
int n,m,x;
map<int,int> mp;
int main(){

	while(cin>>n){
		for(int i=0; i<n; i++){
			cin>>x;
			mp[x] = 1;
		}
		cin>>m;
		for(int i=0; i<m; i++){
			cin>>x;
			if(mp[x]) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}

	return 0;
}

