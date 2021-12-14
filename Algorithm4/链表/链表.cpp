/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2019/9/29 21:53:13
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
#include<stdlib.h>
using namespace std;
typedef long long ll;

typedef struct ListNode{
	int data;
	ListNode* next;
}ListNode, *LinkList; 

void insert(int value, LinkList list){
	//ListNode* p = list->next;
	ListNode* q = (ListNode*)malloc(sizeof(ListNode*));
	q->next = list->next;
	q->data = value;
	list->next = q;
}

LinkList create(){
	ListNode* q = (ListNode*)malloc(sizeof(ListNode*));
	q->next = NULL;
	return q;
}

void output(LinkList list) {
	ListNode* p = list->next;
	while(p){
		cout<<p->data<<endl;
		p = p->next;
	}
}

//查找链表倒数第K个元素，游标卡尺法 
int find(int k, LinkList list){
	ListNode *p, *q;
	p = q = list;
	int cnt = 1;
	bool flag = 0;
	while(p){
		p = p->next;
		cnt++;
		if(cnt == k+1) flag = 1;
		if(flag && p) q = q->next;
	}
	
	cout<<"cnt = "<<cnt<<endl; 
	
	if(cnt <= k+1 ) {
		cout<<"找不到，长度小了"<<endl;
		return 0;	
	}

	cout<<q->data<<endl;

	return 1;
}


int main(){
	LinkList list = create();
	for(int i=1; i<10; i++){
		insert(i , list);
	}
	output(list);
	cout<<"找倒数第9个"<<endl;
	find(9, list);

	return 0;
}

