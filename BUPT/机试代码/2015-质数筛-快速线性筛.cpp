


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
	 		isPrime[ i*prime[j] ] = 0; //�����Ѿ�ɸ�������������ǵ�i����Ȼ����������
			/*
			ŷ��ɸ���ѵ�����ڶ�if (i % prime[j] == 0)�ⲽ����⣬��i��prime[j]��������ʱ���� m = i / prime[j]��
			��ô i * prime[j+1] �Ϳ��Ա�Ϊ (m * prime[j+1]) * prime[j]����˵�� i * prime[j+1] �� prime[j] ����������
			����Ҫ�ٽ��б��(��֮��ᱻ prime[j] * ĳ���� ���)��
			���� prime[j+2] ��֮�������ͬ��ֱ������ѭ���������ͱ������ظ���ǡ�
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

