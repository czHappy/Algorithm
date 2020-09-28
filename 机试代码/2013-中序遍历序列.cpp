  /*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/6 11:16:00
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
int n;
int a[500];
int main(){
	int t;
	cin>>t;
	while(t--){
		bool flag = true;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
			if(i == 0) continue;
			else{
				if(a[i-1] >= a[i]) flag = false;
			}
		}
		cout<< (flag ? "Yes":"No" )<< endl;
		
	}


	return 0;
}

