/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/2 17:15:31
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

struct node{
	int x,y;
};
bool operator <(node a, node b){
	return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
}
priority_queue<node> q;
int main(){
	int T,n;
	string t;
	cin>>T;
	while(T--){
		while(!q.empty()) q.pop();
 		cin>>n;
		while(n--){
			cin>>t;
			if(t == "Pop"){
				if(q.empty()){
					cout<<"Empty!"<<endl;
					continue;
				}
				node fr = q.top();
				q.pop();
				cout<<fr.x<<"+"<<"i"<<fr.y<<endl;
				if(q.empty()) cout<<"Empty!"<<endl;
			}
			else{
				int x,y;
				scanf("%d+i%d",&x,&y);
				node k;
				k.x = x , k.y = y;
				q.push(k);
				cout<<"Size: "<<q.size()<<endl;
			}
		}
	}


	return 0;
}

