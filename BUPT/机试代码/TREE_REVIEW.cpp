/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/17 13:28:02
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
	char data;
	BiTNode* lchild;
	BiTNode* rchild;
}BiTNode, *BiTree; 


void build(BiTree &T){
	char ch;
	cin>>ch;
	if(ch == '.') T = NULL;
	else{
		T = (BiTNode *)malloc(sizeof(BiTNode));
		T->data = ch;
		build(T->lchild);
		build(T->rchild);
	}
}

//前序遍历

void preOrder(BiTree T){
	if(T){
		cout<<T->data<<endl;
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
} 

//中序遍历
void inOrder(BiTree T){
	if(T){	
		preOrder(T->lchild);
		cout<<T->data<<endl;
		preOrder(T->rchild);
	}
} 
 
//后序遍历
void postOrder(BiTree T){
	if(T){	
		preOrder(T->lchild); 
		preOrder(T->rchild);
		cout<<T->data<<endl;
	}
} 

//层序遍历
void levelOrder(BiTree T){
	if(!T) return;
	queue<BiTNode*> q;
	BiTNode* p; 
	q.push(T);
	while(!q.empty()){
		p = q.front();
		q.pop();
		cout<<p->data<<endl;
		if(p->lchild) q.push(p->lchild);
		if(p->rchild) q.push(p->rchild);
	}
} 

// 求树高
int treeHeight(BiTree T){
	int ans = 0;
	if(T){
		ans = max(treeHeight(T->lchild) , treeHeight(T->rchild) ) + 1;
	}
	return ans;
	
}
//层次遍历求树高度 
int treeLevelHeight(BiTree T){
	int ans = 0;
	if(!T) return 0;
	BiTNode* p;
	queue<BiTNode*> q;
	q.push(T);
	BiTNode* rear; //记录下一层最后一个结点 
	BiTNode* last = T; //last记录每层的最后一个结点 
	while(!q.empty()){
		p = q.front();
		q.pop(); 
		if(p->lchild){
			q.push(p->lchild);
			rear = p->lchild;
		}
		if(p->rchild){
			q.push(p->rchild);
			rear = p->rchild;
		}
		if(p == last){ //如果当前结点到了当前层的最后一个结点 
			last = rear; //last更新为 下一层最后一个结点 
			ans++; //
		}
	}
	return ans; 
}

//层次遍历 求树宽度
int levelWidth(BiTree T){
	int ans = 0;
	if(!T) return 0;
	BiTNode* p;
	queue<BiTNode*> q;
	q.push(T);
	ans = 1;
	int width = 0;
	BiTNode* rear; //记录下一层最后一个结点 
	BiTNode* last = T; //last记录每层的最后一个结点 
	while(!q.empty()){
		p = q.front();
		q.pop(); 
		if(p->lchild){
			q.push(p->lchild);
			rear = p->lchild;
			width += 1;
		}
		if(p->rchild){
			q.push(p->rchild);
			rear = p->rchild;
			width += 1;
		}
		if(p == last){ //如果当前结点到了当前层的最后一个结点 
			last = rear; //last更新为 下一层最后一个结点 
			ans = max(ans ,width);
			width = 0;
		}
	}
	return ans; 
	
	
} 


void treeWidth(BiTree T, int level, int count[]){
	if(T){
		count[level]++;
		treeWidth(T->lchild , level + 1, count);
		treeWidth(T->rchild , level + 1, count);
	}
} 

int getTreeWidth(BiTree T){
	int count[100] = {0};
	treeWidth(T, 1 , count);
	int ans = 0;
	for(int i=1; i<100; i++){
		ans = max(ans , count[i]);
	}
	return ans;
}

//判断是不是完全二叉树 
bool isComplete(BiTree T){
	queue<BiTNode*> q;
	BiTNode * p;
	if(!T) return true;
	q.push(T);
	while(!q.empty()){
		p = q.front();
		q.pop();
		if(p){ //不管儿子是不是空结点都进队列 
			q.push(p->lchild);
			q.push(p->rchild);
		}
		else{
			while(!q.empty()){ //处理到空结点时，后面必须都是空结点了，否则就不是二叉树 
				p = q.front();
				q.pop();
				if(p) return false;
			}
		}
	}
	return true;
}

int numOfNode(BiTree T){
	int ans = 0;
	if(T){
		ans = 1;
		ans += numOfNode(T->lchild) + numOfNode(T->rchild);
	}
	return ans;
}

bool isFull(BiTree T){
	int h = treeHeight(T);
	int n = numOfNode(T);
	cout<<"h = "<<h<<" n = "<<n<<endl;
	if(n == (pow(2 , h) - 1))  return 1;
	return 0;
}


int main(){
	BiTree T;
	build(T);
	printf("构造完毕\n");
	cout<<"先序遍历"<<endl;
	preOrder(T);
	cout<<"层序遍历"<<endl;
	levelOrder(T);
	cout<<"高度(递归): "<<treeHeight(T)<<endl;
	cout<<"高度(层序): "<<treeLevelHeight(T)<<endl;
	cout<<"宽度："<<levelWidth(T)<<endl;
	cout<<"宽度(递归)："<<getTreeWidth(T)<<endl;
	cout<<"是不是完全二叉树："<<(isComplete(T) ? "true" : "false")<<endl;
	cout<<"是不是满二叉树："<<(isFull(T) ? "true" : "false")<<endl;
	return 0;
}
/*
A
B
D
E
.
.
.
.
C
F
.
.
G
.
.



A
B
D
E
.
.
.
.
C
F
H
J
.
.
.
I
.
.
G
.
.




*/
