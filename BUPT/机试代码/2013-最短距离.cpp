/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/6 11:37:50
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
const int maxn = 1e5+10;
int m,t;
char s[maxn];//源字符串 
char op[maxn];//操作符 insert or query 
char x;//待插入字母 
int idx;//待查询位置 
vector<int> pos[30];//26个字母有哪些位置 

int distance(int x){
	int ans = 9999999;
	int k = s[x] - 'a'; //找到第x个字母的pos信息 
	if(pos[k].size() == 1) return -1;
	for(int i=0; i<pos[k].size(); i++){
		if(pos[k][i] == x) continue;
		ans = min(ans , abs(x - pos[k][i]));
	}
	return ans;
}

int main(){
	scanf("%d",&t);
	while(t--){
		int len = 0;//初始化 
		for(int i=0; i<30; i++) pos[i].clear();
		//len = strlen(s); 
		scanf("%s",s);//读入char数组 ，不需要&符号( 有也没有报错) 
		for(int i=0; s[i]; i++){
			len++;
			pos[s[i]-'a'].push_back(i); //统计每个字母的位置都有哪些 
		}  
		scanf("%d",&m);
		while(m--){
			scanf("%s",op);
			if(op[0] == 'I'){
				getchar(); //接下来是读入字符故而需要getchar 
				scanf("%c",&x);
				pos[x-'a'].push_back(len);//记下新增位置 
				s[len++] = x; //尾部插入字母 
			}
			else{
				scanf("%d",&idx);
				cout<< distance(idx)<<endl;	 // 查询距离 
			}
		}
	}
	return 0;
}

