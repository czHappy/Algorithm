/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/13 9:46:11
  Description:
*/


/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4+10;

struct node{
	string log;
	string start;
	double len;
	

}rec[maxn];

bool operator < ( const node& a,  const node& b ){
	if(fabs(a.len - b.len) < 1e-6) return a.start < b.start;
	return a.len < b.len;
}

int main(){
	int cnt = 0;
	string str;
	while(getline(cin , str)){
		if(str.size() == 0) break;
		istringstream strout(str);
		
		string name,ymd,t;
		double l;
		strout >> name >> ymd >> t >> l;
		rec[cnt].len = l;
		rec[cnt].log = str;
		rec[cnt].start = ymd + t;
		cnt++;	
	}

	sort(rec , rec + cnt);
	for(int i=0; i<cnt; i++) cout<<rec[i].log<<endl;
	return 0;
}
*/

//法2：使用sscanf 
/*
  Name:
  CopyRight:
  Author: Cz
  Date: 2020/4/13 9:46:11
  Description:
*/



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4+10;

struct node{
	string log;
	string start;
	double len;
}rec[maxn];

bool operator < ( const node& a,  const node& b ){
	if(fabs(a.len - b.len) < 1e-6) return a.start < b.start;
	return a.len < b.len;
}

int cnt = 0;
char str[50];
char name[50];
char ymd[50];
char t[50];
double l;

//法2：使用sscanf 
int main(){

	while(gets(str)){
		if(strlen(str) == 0) break;
		sscanf(str , "%s %s %s %lf(s)", &name, &ymd, &t, &l);
		rec[cnt].len = l;
		rec[cnt].log = str;
		strcat( ymd, t );
		rec[cnt].start = ymd;
		//cout<<rec[cnt].log<<endl;
		cnt++;	
		
	}

	sort(rec , rec + cnt);
	for(int i=0; i<cnt; i++) cout<<rec[i].log<<endl;
	return 0;
}
