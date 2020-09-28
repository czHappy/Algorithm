/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/30 13:56:19
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

//0 1 2 3
//+ - * /
const double eps = 1e-8;

bool prior[4][4] = {1, 1, 0, 0,
					1, 1, 0, 0,
					1, 1, 1, 1,
					1, 1, 1, 1};
int t;
double a[4]; //输入数字 4个 

stack<double> num;//数字栈 
stack<char> sg;//符号栈 

map<int , char> mp; //index转符号 
map<char , int> trans; //符号转index 



void operate(){
		char op = sg.top();
		sg.pop();
		double y = num.top();
		num.pop();
		double x = num.top();
		num.pop();
		double ans;
		if(op == '+') ans = (x + y);
		if(op == '-') ans = (x - y);
		if(op == '*') ans = (x * y);
		if(op == '/') ans = (x / y);
		
		num.push(ans);
	//	cout<<"op = " <<op<<"  value = "<<ans<<endl;
}

double calc(string sre){
	//cout<<"sre = "<<sre<<endl;
	bool fn = 1;//交替取数和符号 
	int idx = 0;//数字 指针 
	int sx = 0; // 符号指针 
	while(idx < 4){
		if(fn){
			num.push(a[idx++]);
			fn = 0;
		}
		else{
			while( !sg.empty() && prior[ trans [sg.top() ] - 1 ][trans[ sre[sx] ] - 1 ] ){
				operate();
			}
			sg.push(sre[sx++]);
			fn = 1;
		}
	}
	
	while( !sg.empty() ){
		operate(); 
	}
	return num.top();
}

int main(){
	mp[1] = '+';
	mp[2] = '-';
	mp[3] = '*';
	mp[4] = '/';
	trans['+'] = 1;
	trans['-'] = 2;
	trans['*'] = 3;
	trans['/'] = 4;
	string sre[64];//符号结果
	int cnt = 0; //符号序列的种类 
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++){
			for(int k=1; k<=4; k++){
				sre[cnt] = "";
				sre[cnt] += mp[i];
				sre[cnt] += mp[j];
				sre[cnt] += mp[k];
				cnt++;
			}	
		}
	}
//	for(int i=0; i<cnt; i++) cout<<sre[i]<<endl;//debug 
	cin>>t;
	while(t--){	
		bool f = 0;
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		
		for(int i=0; i<64; i++){
			if( fabs(calc(sre[i]) - 24) < eps ){
				cout<<"solution:"<< a[0] << sre[i][0] << a[1]<<sre[i][1]<<a[2]<<sre[i][2]<<a[3]<<endl;
				f = 1;
				break;
			}
		}
		if(f) cout<<"YES"<<endl;
		else cout<<"NO"<<endl; 
	} 
	
	
	return 0;
}

