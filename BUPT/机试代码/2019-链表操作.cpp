/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/1 11:31:18
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
typedef struct node{
	int val;
	struct node* next;
}ListNode, *LinkList;

LinkList create(){
	LinkList head;
	head = (ListNode*)malloc(sizeof(ListNode*));
	head->next = NULL;
	return head;
}
//头插法 
void insert(LinkList &list, int val){
	ListNode * q = (ListNode*)malloc(sizeof(ListNode*));
	if(!q){
		cout<<"error"<<endl;
		return;
	} 
	q->next = list->next;
	q->val = val;
	list->next = q;
}

// 尾插法
void insert_tail(LinkList &list, int val){
	ListNode * p = list;
	while(p->next){
		p = p->next;
	}
	ListNode *q = (ListNode*)malloc(sizeof(ListNode*));
	q->val = val;
	q->next = NULL;
	p->next = q;
}

// 链表逆置

void reverse(LinkList &list){
	//分成两段链表 
	ListNode * p = list->next;
	while(p){
		ListNode* cur = p;
		p = p->next;
		cur->next = list->next;
		list->next = cur;
	} 
}


void remove(LinkList &list, int val){
	ListNode * p = list->next;
	ListNode *pre = list;
	while(p){
		if(p->val == val){
			pre->next = p->next;
			p->next = NULL;
			free(p);
			return;
		}
		pre = p;
		p = p->next; 
	}
}

void output(LinkList list){
	ListNode *p = list->next;
	while(p != NULL){
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
}

int look_next(LinkList &list, int val){
	ListNode *p = list->next;
	while(p != NULL){
		if(p->val == val){
			if(p->next) return p->next->val;
			else return INT32_MAX;
		}
		p = p->next;
	}
	return INT32_MAX;
}
int main(){
	int n,m,t,op,x;
	cin>>t;
	while(t--){
		LinkList list = create();
		cin>>n>>m;
		for(int i=n; i>0; i--) insert(list , i);
		while(m--){
			cin>>op;
			if(op == 1){
				cin>>x;
				remove(list, x);
			}
			else if(op == 2){
				reverse(list);
			}
			else{
				cin>>x;
				int re = look_next(list, x);
				if(re != INT32_MAX)
					cout<<re<<endl;
				else cout<<"NONE"<<endl;
			}
		}
	}

	return 0;
}

