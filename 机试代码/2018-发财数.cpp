/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/28 17:40:19
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

const int maxn = 4e5; 
int money[20000];
int prime[maxn+10];
bool isPrime[maxn+10];
int cnt = 0;
void getPrime(){
	memset(isPrime, 1 , sizeof isPrime); //先认为都是质数
	isPrime[0] = isPrime[1] = 0;
	for(int i=2; i<=maxn; i++){
		if(isPrime[i]) {
			prime[cnt++] = i;
		}
		for(int j=0; j<cnt; j++){
			if(i*prime[j] > maxn) break;
			isPrime[ i*prime[j] ]  = 0;
			if(i % prime[j] == 0) break;
		}
	}	
}
 


void init(){
	getPrime();
	int cnt = 1;//指针 cnt到10000即可停止 
	for(int i=256; ; i++){ //[256 , +∞) 
		if(cnt > 10000) break;
		if(isPrime[i]) continue;//优化一  当前是素数直接跳过  
		int idx = 0;//当前质因子 prime[idx]
		int k = 0; //记录i的质因子个数 
		int store = i;//暂存i的值 
		while(store){
			while(store % prime[idx] == 0){
				store = store/prime[idx];
				k++;
				int other =  store;
				if(isPrime[other]){ //如果另外一个数也是质数 那么直接除掉， k+=1 ，优化二 
					store = 1;
					k++;
					break;
				}
			}

			idx++;//试试下一个质数 
			if(k >= 8){
				money[cnt++] = i;
				break;
			}
			if(prime[idx] > sqrt(store)){ //优化三 继续分解store时，若当前质因子已经大于根号store，则不必再试下去 大幅度提升速度 
				break; 
			} 
		}
	}
}




int main(){
	
	int t,n;
	init();
//	cout<<"over"<<endl;
	//for(int i=1; i<10000; i++){
	//	if(i % 100 == 0) cout<<endl;
	//	cout<<money[i]<<" ";
	//}
	cin>>t;
	while(t--){
		cin>>n;
		cout<<money[n]<<endl;
	}

	return 0;
}

