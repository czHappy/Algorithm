/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/19 9:45:45
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
string pre;
string post;
bool flag = 0;
/*
8
ABCDEFGH
BDCEAFHG

*/
void solve(int now, int l, int r){
	if(l > r) return;
	int pos ;
	for(int i=0; i<post.size(); i++){
		if(post[i] == pre[now]){ //�ҵ�����������ڵ������������е�λ�� ����Ի����������� 
			pos = i;;
			break; 
		}
	}
	solve(now+1, l, pos-1); //l~pos-1���������� now+1������������ĸ��ڵ�
	solve(now+1+pos-l, pos+1, r); //pos-l���������Ľ��������now�Ǵ��������������е�λ�ã������������������������е�λ����(now+1)+(pos-l)

	cout<<pre[now]<<endl; //���ҵݹ������ٷ��ʸ��ڵ� ���Ǻ������ 
	

} 


int main(){
	int n;
	cin>>n;
	cin>>pre;
	cin>>post;
	solve(0, 0, n-1); 
	return 0;
}

