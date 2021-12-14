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
		if(post[i] == pre[now]){ //找到先序遍历根节点在中序序列中的位置 则可以划分左右子树 
			pos = i;;
			break; 
		}
	}
	solve(now+1, l, pos-1); //l~pos-1都是左子树 now+1是这棵左子树的根节点
	solve(now+1+pos-l, pos+1, r); //pos-l是左子树的结点数量，now是大树树根在先序中的位置，则右子树树根在先序序列中的位置是(now+1)+(pos-l)

	cout<<pre[now]<<endl; //左右递归完了再访问根节点 故是后序遍历 
	

} 


int main(){
	int n;
	cin>>n;
	cin>>pre;
	cin>>post;
	solve(0, 0, n-1); 
	return 0;
}

