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

//ǰ�����

void preOrder(BiTree T){
	if(T){
		cout<<T->data<<endl;
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
} 

//�������
void inOrder(BiTree T){
	if(T){	
		preOrder(T->lchild);
		cout<<T->data<<endl;
		preOrder(T->rchild);
	}
} 
 
//�������
void postOrder(BiTree T){
	if(T){	
		preOrder(T->lchild); 
		preOrder(T->rchild);
		cout<<T->data<<endl;
	}
} 

//�������
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

// ������
int treeHeight(BiTree T){
	int ans = 0;
	if(T){
		ans = max(treeHeight(T->lchild) , treeHeight(T->rchild) ) + 1;
	}
	return ans;
	
}
//��α��������߶� 
int treeLevelHeight(BiTree T){
	int ans = 0;
	if(!T) return 0;
	BiTNode* p;
	queue<BiTNode*> q;
	q.push(T);
	BiTNode* rear; //��¼��һ�����һ����� 
	BiTNode* last = T; //last��¼ÿ������һ����� 
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
		if(p == last){ //�����ǰ��㵽�˵�ǰ������һ����� 
			last = rear; //last����Ϊ ��һ�����һ����� 
			ans++; //
		}
	}
	return ans; 
}

//��α��� �������
int levelWidth(BiTree T){
	int ans = 0;
	if(!T) return 0;
	BiTNode* p;
	queue<BiTNode*> q;
	q.push(T);
	ans = 1;
	int width = 0;
	BiTNode* rear; //��¼��һ�����һ����� 
	BiTNode* last = T; //last��¼ÿ������һ����� 
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
		if(p == last){ //�����ǰ��㵽�˵�ǰ������һ����� 
			last = rear; //last����Ϊ ��һ�����һ����� 
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

//�ж��ǲ�����ȫ������ 
bool isComplete(BiTree T){
	queue<BiTNode*> q;
	BiTNode * p;
	if(!T) return true;
	q.push(T);
	while(!q.empty()){
		p = q.front();
		q.pop();
		if(p){ //���ܶ����ǲ��ǿս�㶼������ 
			q.push(p->lchild);
			q.push(p->rchild);
		}
		else{
			while(!q.empty()){ //�����ս��ʱ��������붼�ǿս���ˣ�����Ͳ��Ƕ����� 
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
	printf("�������\n");
	cout<<"�������"<<endl;
	preOrder(T);
	cout<<"�������"<<endl;
	levelOrder(T);
	cout<<"�߶�(�ݹ�): "<<treeHeight(T)<<endl;
	cout<<"�߶�(����): "<<treeLevelHeight(T)<<endl;
	cout<<"��ȣ�"<<levelWidth(T)<<endl;
	cout<<"���(�ݹ�)��"<<getTreeWidth(T)<<endl;
	cout<<"�ǲ�����ȫ��������"<<(isComplete(T) ? "true" : "false")<<endl;
	cout<<"�ǲ�������������"<<(isFull(T) ? "true" : "false")<<endl;
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
