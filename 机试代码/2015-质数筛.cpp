/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/17 9:08:10
  Description:
*/

// ����һ��С��31��������С��������� 

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

//������ͨɸ
const int maxn =  10000;
bool isPrime[maxn+5];
int prime[maxn+5];
int cnt = 0;
void getPrime(){
	memset(isPrime, 1, sizeof isPrime); //�ٶ��������� 
	isPrime[0] = isPrime[1] = 0;// 0 1����������
	//ɸ��BOOL���� 
	for(int i=2; i*i<=maxn; i++){ //ö��i��sqrt(maxn) 
		for(int j=2; j<=maxn/i; j++){ //ö��i�ı�������Ȼ��2��ʼ 
			if(isPrime[i]) isPrime[i*j] = 0;
		}
	} 
	//�������
	for(int i=2; i<maxn; i++){
		if(isPrime[i]) prime[cnt++] = i;//prime[i]��ʾ��i��������ʲô 
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

