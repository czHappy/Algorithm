/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/17 9:08:10
  Description:
*/

// 给定一个小于31的整数求小于其的质数 

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

bool is_prime(int x){
	if(x == 1) return 0;
	if(x == 2) return 1;
	for(int i=2; i<sqrt(x)+0.5; i++){
		if(x % i == 0) return 0;
	}
	return 1;
} 

//质数普通筛
const int maxn =  10000;
bool isPrime[maxn+5];
int prime[maxn+5];
int cnt = 0;
void getPrime(){
	memset(isPrime, 1, sizeof isPrime); //假定都是质数 
	isPrime[0] = isPrime[1] = 0;// 0 1都不是质数
	//筛出BOOL数组 
	for(int i=2; i*i<=maxn; i++){ //枚举i到sqrt(maxn) 
		for(int j=2; j<=maxn/i; j++){ //枚举i的倍数，当然从2开始 
			if(isPrime[i]) isPrime[i*j] = 0;
		}
	} 
	//素数入表
	for(int i=2; i<maxn; i++){
		if(isPrime[i]) prime[cnt++] = i;//prime[i]表示第i个素数是什么 
	} 
	
} 




int main(){
	int t,n;
	getPrime();
	/*
	for(int i=0; i<cnt; i++){
		cout<<prime[i]<<endl;
	}*/
	cin>>t;
	
	while(t--){
		cin>>n;
		int ans = 0;
		for(int i=2; i<n; i++){
			if(is_prime(i)) ans++;
		}
		cout<<"ans1 = "<<ans<<endl;
		
		ans = 0;
		for(int i=0; i<n; i++){
			if(isPrime[i]) ans ++;
		}
		cout<<"ans2 = "<<ans<<endl;
	}


	return 0;
}

