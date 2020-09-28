/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/15 8:59:10
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
int t,n;
map<string, int> mp;
int R[5] = {0}; //A B C D四个寄存器 

ll trans(string s){
	ll ans = 0;
	int cnt = 0;
	if(s[s.length() - 1] != 'H' && s[s.length() - 1] != 'B'){
		for(ll i=s.length()-1; i>=0; i--){
			ans += pow(10 , cnt) * (s[i] - '0');
			cnt++; 
		}
		return ans;
	}
	
	bool flag = 0; //是否是16进制 
	if(s[s.length() - 1] == 'H') flag = 1;
	s.pop_back();//标志符号弹出 
	
	for(ll i=s.length()-1; i>=0; i--){
		if(!flag) 
			ans += pow(2 , cnt) * (s[i] - '0');
		else{
			if(s[i] >= '0' && s[i] <='9') ans += pow(16, cnt) * (s[i] - '0');
			else ans += pow(16, cnt) * (s[i] - 'A' + 10);
		}
		cnt++;
	}
	return ans;
}


void operation(string op){
	string d,s,tmp;
	ll a,b;
	bool f = 0;
	d = s = "";		
	if(op == "MOV") f = 1;
	cin>>tmp;
	/*
	int i=0;
	for(i=0; i<tmp.length(); i++){
		bool p = (tmp[i]>='0' && tmp[i] <='9') ||  (tmp[i]>='A' && tmp[i]<='Z');//判断中文逗号 
		if(!p) break; 
		d += tmp[i];
	}
	i+=1; //略去逗号 
	for(; i<tmp.length(); i++){
		s += tmp[i];
	}*/
	
	d += tmp[0];
	d += tmp[1];
	for(int i=4; i<tmp.length(); i++) s += tmp[i];
	cout<<"d = "<<d<<" s = "<<s<<endl;
	if(mp[s]){ //如果是寄存器 
		b = R[mp[s]];
		if(s[1] == 'H') b = b & (0xFF00);
		if(s[1] == 'L') b = b & (0x00FF);
	} 
	else{ //如果是立即数 
		b = trans(s);
	}
	
	if(f) R[mp[d]] = b;
	else  R[mp[d]] += b;	
}


int main(){
	mp["AX"] = mp["AL"] = mp["AH"] = 1;
	mp["BX"] = mp["BL"] = mp["BH"] = 2;
	mp["CX"] = mp["CL"] = mp["CH"] = 3;
	mp["DX"] = mp["DL"] = mp["DH"] = 4;
	string op,val;
	string s,d,tmp;
	cin>>t;
	while(t--){
		cin>>n;
		memset(R , 0 , sizeof R);
		while(n--){	
			cin>>op;
			operation(op);
		}
		for(int i=1; i<=4; i++) cout<<R[i]<<" ";
		cout<<endl;
	}
	

	return 0;
}


/*

2
3
MOV
AX,
2
MOV
BX,
3
ADD
AX,
BX
5
MOV
AX,
2
MOV
BX,
030H
MOV
CX,
11B
ADD
AX,
CX
ADD
DL,
CL



*/




