/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/3 10:31:26
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
// sscanf ���������سɹ���ֵ���ֶθ���������ֵ�������Ѷ�ȡ��δ��ֵ���ֶθ�����
int main(){
	int t,a,b,c,d;
	scanf("%d",&t);
	while(t--){
		char s[1000];
		scanf("%s",&s);
		if(sscanf(s,"%d.%d.%d.%d" ,&a,&b,&c,&d) == 4){
			if(a<=255 && a >=0 && b<=255 && b >=0 && c<=255 && c >=0 && d<=255 && d>=0)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else{
			printf("No\n");
		}
		
	} 


	return 0;
}

