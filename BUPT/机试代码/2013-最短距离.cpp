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
char s[maxn];//Դ�ַ��� 
char op[maxn];//������ insert or query 
char x;//��������ĸ 
int idx;//����ѯλ�� 
vector<int> pos[30];//26����ĸ����Щλ�� 

int distance(int x){
	int ans = 9999999;
	int k = s[x] - 'a'; //�ҵ���x����ĸ��pos��Ϣ 
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
		int len = 0;//��ʼ�� 
		for(int i=0; i<30; i++) pos[i].clear();
		//len = strlen(s); 
		scanf("%s",s);//����char���� ������Ҫ&����( ��Ҳû�б���) 
		for(int i=0; s[i]; i++){
			len++;
			pos[s[i]-'a'].push_back(i); //ͳ��ÿ����ĸ��λ�ö�����Щ 
		}  
		scanf("%d",&m);
		while(m--){
			scanf("%s",op);
			if(op[0] == 'I'){
				getchar(); //�������Ƕ����ַ��ʶ���Ҫgetchar 
				scanf("%c",&x);
				pos[x-'a'].push_back(len);//��������λ�� 
				s[len++] = x; //β��������ĸ 
			}
			else{
				scanf("%d",&idx);
				cout<< distance(idx)<<endl;	 // ��ѯ���� 
			}
		}
	}
	return 0;
}

