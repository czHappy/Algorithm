/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/1 11:02:28
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

bool isPrime(int x){
	if(!(x % 4) && x % 100) return true;
	if( !(x % 400) ) return true;
	return false;
}

int main(){
	int t;;
	cin>>t;
	while(t--){
		int x,y,cnt = 0;
		//cout<<x<<" "<<y<<" "<<cnt<<endl;
		cin>>x>>y;
		for(int i=x; i<=y; i++){
			if(isPrime(i)){
				cnt++;
				i+=3;
			} 
		}
		cout<<cnt<<endl;
	} 


	return 0;
}

