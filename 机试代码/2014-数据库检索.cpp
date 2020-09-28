/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/11 20:21:56
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
#include<cstring>
#include<stdio.h>
using namespace std;
typedef long long ll;
int n,m;// 学生数  询问数 
struct node{
	string name;
	string sex;
	int year;
	int month;
	int day;
}stu[505]; 

struct condition{
	string type;
	string value;
	int y,m,d;
	condition(string a, string b){
		type = a;
		value = b;
	}
};

void find(vector<condition> setCon){
	vector<string> ans;
	ans.clear();
	for(int i=0; i<n; i++){
		bool flag = 1;
		for(int j=0; j<setCon.size(); j++){
			
			if(setCon[j].type == "Name"){
				if(stu[i].name != setCon[j].value) flag = 0;
			}
			
			if(setCon[j].type == "Sex"){
				if(stu[i].sex != setCon[j].value) flag = 0;
			}
			
			if(setCon[j].type == "Birthday"){
				if(stu[i].year != setCon[j].y && setCon[j].y != -1) flag = 0;
				if(stu[i].month != setCon[j].m && setCon[j].m != -1) flag = 0;
				if(stu[i].day != setCon[j].d && setCon[j].d != -1) flag = 0;
			}
			
		}
		if(flag) ans.push_back(stu[i].name);
	}
	if(ans.size() == 0) cout<<"NULL"<<endl;
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<endl;
	}
}


int main(){
	
	int t;
	cin>>t;
	while(t--){
		vector<string> ans;
		cin>>n>>m;
		for(int i=0; i<n; i++){
			cin>>stu[i].name;
			cin>>stu[i].sex;
			scanf("%d/%d/%d",&stu[i].year, &stu[i].month, &stu[i].day);
		}
		
		string s;
		string con="";
		
		getchar();
		for(int i=0; i<m; i++){
			
			getline(cin , s);//循环中getline不要再getchar了 之前要 
			vector<condition> setCon;
			setCon.clear(); 
			for(int i=0; i<s.length()-3; i++){
				if(s[i]=='N' && s[i+1]=='a' && s[i+2]=='m' && s[i+3]=='e'){
					con = "Name";
					string v="";
					for(int j=i+6; s[j] != '\'' ; j++){
						v += s[j];
					}
					condition x = condition(con , v);
					cout<<x.type<<" : "<<x.value<<endl;
					setCon.push_back(x);
				}	
			}
			
			
			for(int i=0; i<s.length()-2; i++){
				if(s[i]=='S' && s[i+1]=='e' && s[i+2]=='x'){
					con = "Sex";
					string v="";
					for(int j=i+5; s[j] != '\''; j++){
						v += s[j];
					}
					condition x = condition(con , v);
					setCon.push_back(x);
				}	
			}
			
			
			for(int i=0; i<s.length()-7; i++){
				if(s[i]=='B' && s[i+1]=='i' && s[i+2]=='r' && s[i+3]=='t'&& s[i+4]=='h'&& s[i+5]=='d'&& s[i+6]=='a'&& s[i+7]=='y'){
					con = "Birthday";
					string v="";
					for(int j=i+10; s[j] != '\''; j++){
						v += s[j];
					}
					v += '/';
					condition x = condition(con , v);
					string tmp = "";
					int cnt = 0;
					for(int i=0; i<v.size(); i++){
						if(v[i] != '/'){
							tmp += v[i];
						}
						else{
							if(cnt == 0){ //year
								if(tmp == "*") x.y = -1;
								else x.y = (tmp[0]-'0')*1000 + (tmp[1]-'0')*100 + (tmp[2]-'0')*10 + (tmp[3]-'0');
							}
							if(cnt == 1){
								if(tmp == "*") x.m = -1;
								else x.m = (tmp[0]-'0')*10 + (tmp[1]-'0');
							}
							if(cnt == 2){
								if(tmp == "*") x.d = -1;
								else x.d = (tmp[0]-'0')*10 + (tmp[1]-'0');
							}
							cnt++;
							tmp = "";
						}
					}
					setCon.push_back(x);
				}
					
			}
			
			find(setCon);
		}
	}

	return 0;
}

//1
//5 6
//Michael Male 1990/02/28
//Amy Female 1992/04/03
//Tom Male 1991/12/15
//Lynn Female 1991/04/09
//Zheng Male 1990/04/20
//Name='Amy'
//Name='Betty'
//Sex='Female' Birthday='*/04/09'
//Sex='Female' Birthday='*/*/*'
//Name='Michael' Sex='Female'
//Name='Michael'  Sex='Male'  Birthday='1990/02/*'

