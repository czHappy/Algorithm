/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/2 11:41:20
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
#include<cmath>
using namespace std;
typedef long long ll;

int main() {
	int n;
	int a[1000];
	int maxx = -1;
	int minx = 0x3f3f3f3f;
	int sum = 0;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		minx = min(a[i] , minx);
		maxx = max(a[i] , maxx);
		sum += a[i];
	} 
	
	sum -= (minx + maxx);
	cout<<sum*1.0/(n-2)<<endl;
	printf("%.2f\n",sum*1.0/(n-2));
	return 0;
}

