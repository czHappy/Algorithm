/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/4 10:28:33
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
//ADT
typedef struct BiTNode{
	int key;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree; 

int insert(BiTree &T, int key, int par){
	if(T == NULL){
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->key = key;
		T->lchild = NULL;
		T->rchild = NULL;
		return par;
	}
	else{
		if(T->key > key){
			insert(T->lchild, key, T->key);
		}
		else{
			insert(T->rchild, key, T->key);
		}
		
	}
}

int main(){
	int n,x;
	cin>>n;
	BiTree root;
	root = NULL;
	while(n--){
		cin>>x;
		cout<<root<<endl;
		cout<<insert(root , x, -1)<<endl;
	}	
	return 0;
}

