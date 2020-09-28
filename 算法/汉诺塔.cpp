/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/5/1 16:40:27
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
int cnt = 0;
void solve(int size, int source, int buffer, int dest){
	if(size == 1) {
		cnt++;
		//printf("把一个盘子从[%d]移动到[%d]\n",source,dest);
		return ;
	}
	solve(size - 1, source, dest , buffer);
	solve(1, source, buffer, dest); 
	solve(size - 1, buffer, source, dest);

}

int main(){
	int n;
	while(cin>>n){
		cnt = 0;
		solve(n , 1, 2, 3);
		cout<<cnt<<endl;
	} 


	return 0;
}

