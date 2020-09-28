/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/10 21:55:58
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
const int inf = 0x3f3f3f3f;
typedef struct BiTNode{
	int w;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
	BiTNode(){}
}BiTNode, *BiTree; 

//½¨Ê÷ 
void build(BiTree &T){
	int w;
	cin>>w;
	if(w == -1) T = NULL;
	else{
		T = (BiTNode *)malloc(sizeof(BiTNode));
		T->w = w;
		build(T->lchild);
		build(T->rchild); 
	}
}
bool flag = 1, ans = 1;
void judge(BiTree T){
	int l,r,f;
	
	if(T != NULL){
		int l = T->lchild ? T->lchild->w : inf;
		int r = T->rchild ? T->rchild->w : inf;
		if(T->w > min(l ,r)) ans = 1; 
		judge(T->lchild);
		judge(T->rchild);
	}
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		BiTree T = NULL;
		build(T);
		flag = 0;
		ans = 0;
		judge(T);
		
		if(ans) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}



	return 0;
}
/*11
10
15
24
27
-1
-1
-1
28
-1
-1
24
25
-1
-1
26
-1
-1*/
