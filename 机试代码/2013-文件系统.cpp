/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/8 9:13:19
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

const int maxn = 1e3;
//dir��file
//dir��dir
 

vector<string> dir[maxn];//dir[i]�����i��dir���µ�Ŀ¼ 
vector<string> file[maxn];//file[i]�����i��dir���µ��ļ� 
//
map<string, int> mp; //dir�����ӳ�� 

int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0; i<maxn; i++){
			dir[i].clear();
			file[i].clear();
		}
		mp.clear();
		mp["root"] = 1;
		int n;
		cin>>n;
		string op,s,d;
		while(n--){
			cin>>op;
			if(op == "CREATEDIR"){
				cin>>s>>d;
				int dirPos = mp[d];
				dir[dirPos].push_back(s);
			}
			if(op == "CREATEFILE"){
				cin>>s>>d;
				int dirPos = mp[d];
				file[dirPos].push_back(s);
			}
			if(op == "LISTFILE"){
				cin>>d;
				int dirPos = mp[d];
				for(int i=0; i<file[dirPos].size(); i++){
					cout<<file[dirPos][i]<<endl;
				}
			}
			if(op == "LISTDIR"){
				cin>>d;
				int dirPos = mp[d];
				for(int i=0; i<dir[dirPos].size(); i++){
					cout<<dir[dirPos][i]<<endl;
				}
			}
		}
	} 

	return 0;
}

