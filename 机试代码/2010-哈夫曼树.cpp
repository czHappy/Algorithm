/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/2 10:37:33
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

priority_queue<int, vector<int>, greater<int> > q; 

int main(){
	int n,x, sum = 0;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x;
		q.push(x);
	}
	while(q.size() > 1){
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		int c = a + b;
		q.push(c);
		//cout<<"a b c = "<<a<<" "<<b<<" "<<c<<endl;
		sum += c;
	}
	cout<<sum<<endl;

	return 0;
}

