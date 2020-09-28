/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/16 10:07:35
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

int n,ans;
int num1[105][105]; 
int num2[105][105];
int dpr[105][105]; //row 	从左到右的延伸 
int dpc[105][105]; // column  从上到下的延伸 
int dp[105][105]; //dp[i][j]表示以(i,j)为左下角的最大方阵 
int main(){
	cin>>n;
	ans = 0;
	memset(dpr , 0 , sizeof dpr);
	memset(dpc , 0 , sizeof dpc);
	memset(dp , 0 , sizeof dp);
	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	cin>>num1[i][j]; 
	
	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	cin>>num2[i][j]; 
	
	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	num1[i][j] = !(num1[i][j] ^ num2[i][j]); //异或后取非，为1则是相同像素
	
	//
	for(int j=1; j<=n; j++){
		for(int i=1; i<=n; i++){
			if(num1[i][j] == 1){
				dpr[i][j] = dpr[i][j-1] + 1;
			}
			else{
				dpr[i][j] = 0;
			}
		}
	} 
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(num1[i][j] == 1){
				dpc[i][j] = dpc[i-1][j] + 1;
			}
			else{
				dpc[i][j] = 0;
			}
		}
	} 
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int t = dp[i-1][j-1];//取该点左上角的值
			t = min(t , dpr[i][j-1]) ;
			t = min(t , dpc[i-1][j]) ;
			if(num1[i][j] == 1){
				dp[i][j] = t + 1;
			}
			else{
				dp[i][j] = 0;
			}
			
			ans = max(ans , dp[i][j]);
		}
	} 
	
	cout<<ans<<endl;
	
	
	return 0;
}
/*
4
1 1 1 1
1 1 1 0
1 1 1 0
1 1 1 1
0 1 1 1
0 1 1 1
0 1 1 1
0 1 1 0




*/
