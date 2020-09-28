


/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/17 9:31:55
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
const int maxn = 10000;
bool isPrime[maxn+10];
int prime[maxn+10]; 
int cnt = 0;
void getPrime(){
	memset(isPrime , 1 , sizeof isPrime);
	isPrime[0] = isPrime[1] = 0;
	for(int i=2; i<=maxn; i++){
		if(isPrime[i]) prime[cnt++] = i;

	 	for(int j=0; j<cnt; j++){
	 		if(i * prime[j] > maxn) break;
	 		isPrime[ i*prime[j] ] = 0; //遍历已经筛出的质数，他们的i倍必然都不是质数
			/*
			欧拉筛的难点就在于对if (i % prime[j] == 0)这步的理解，当i是prime[j]的整数倍时，记 m = i / prime[j]，
			那么 i * prime[j+1] 就可以变为 (m * prime[j+1]) * prime[j]，这说明 i * prime[j+1] 是 prime[j] 的整数倍，
			不需要再进行标记(在之后会被 prime[j] * 某个数 标记)，
			对于 prime[j+2] 及之后的素数同理，直接跳出循环，这样就避免了重复标记。
			*/
			if(i % prime[j] == 0)	break;
			 
		}
	}
}
int main(){/*
	getPrime();
	for(int i=0; i<cnt; i++) cout<<prime[i]<<endl;


	return 0;
}

