/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/3/5 9:45:46
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
	char a,b;
	int sum;
	node(){sum = 0;}
	
};

int getDEC(node t){
	char a = t.a;
	char b = t.b;
	int sum = 0;
	if(a >= 'a' && a <= 'f') sum += (a - 'a' + 10) * 16;
	else sum += (a - '0') * 16;
	if(b >= 'a' && b <= 'f') sum += (b - 'a' + 10);
	else sum += (b - '0');
	return sum;
}

vector<node> x;

int main(){
	int T;
	cin>>T;
	getchar();
	string s;
	string t;
	int cas = 1;
	while(T--){
		x.clear();
		s = "";
		t = "";
		getline(cin,s);
		for(int i=0; i<s.length(); i++){
			if(s[i] != ' ') t += s[i]; 
		}
		s = t;
		for(int i=0; i<s.length();i+=2){
			node tmp;
			tmp.a = s[i];
			tmp.b = s[i+1];
			tmp.sum = getDEC(tmp);
			x.push_back(tmp);
		}
		cout<<"Case #"<<cas++<<endl;
		cout<<"Total length = "<<x[2].sum*256+x[3].sum<<" bytes"<<endl;
		cout<<"Source = "<<x[12].sum<<"."<<x[13].sum<<"."<<x[14].sum<<"."<<x[15].sum<<endl;
		cout<<"Destination = "<<x[16].sum<<"."<<x[17].sum<<"."<<x[18].sum<<"."<<x[19].sum<<endl;
		cout<<"Source Port = "<<x[20].sum*256+x[21].sum<<endl;
		cout<<"Destination Port = "<<x[22].sum*256+x[23].sum<<endl;
		cout<<endl;
	}


	return 0;
}
/*
2
45 00 00 34 7a 67 40 00 40 06 63 5a 0a cd 0a f4 7d 38 ca 09 cd f6 00 50 b4 d7 ae 1c 9b cf f2 40 80 10 ff 3d fd d0 00 00 01 01 08 0a 32 53 7d fb 5e 49 4e c8
45 00 00 c6 56 5a 40 00 34 06 e0 45 cb d0 2e 01 0a cd 0a f4 00 50 ce 61 e1 e9 b9 ee 47 c7 37 34 80 18 00 b5 81 8f 00 00 01 01 08 0a 88 24 fa c6 32 63 cd 8d

*/

