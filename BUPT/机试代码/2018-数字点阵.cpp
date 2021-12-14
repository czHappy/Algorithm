//给定只含01的字符串，找出最长平衡子串的长度（平衡串：包含0和1的个数相同），串长最大10^5
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
#define MS(x,i) memset(x,i,sizeof(x))
#define rep(i,s,e) for(int i=s; i<=e; i++)
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define debug printf("debug......\n");
#define pfd(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
const double eps=1e-8;
const double PI = acos(-1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 0x7fffffff;
const int maxn = 2e2+10;
int dx[4] = {0, 0, 1, -1};
int dy[4]  = {1, -1, 0 , 0};

//数字点阵
struct node{
	string ans[5];
};

node trans(int i){
   node t;
    if(i == 0){
        t.ans[0] = "111";
        t.ans[1] = "101";
        t.ans[2] = "101";
        t.ans[3] = "101";
        t.ans[4] = "111";
    }
    if(i == 1){
        t.ans[0] = "001";
        t.ans[1] = "001";
        t.ans[2] = "001";
        t.ans[3] = "001";
        t.ans[4] = "001";
    }

    if(i == 2){
        t.ans[0] = "111";
        t.ans[1] = "001";
        t.ans[2] = "111";
        t.ans[3] = "100";
        t.ans[4] = "111";
    }

    if(i == 3){
        t.ans[0] = "111";
        t.ans[1] = "001";
        t.ans[2] = "111";
        t.ans[3] = "001";
        t.ans[4] = "111";
    }

    if(i == 4){
        t.ans[0] = "101";
        t.ans[1] = "101";
        t.ans[2] = "111";
        t.ans[3] = "001";
        t.ans[4] = "001";
    }

    if(i == 5){
        t.ans[0] = "111";
        t.ans[1] = "100";
        t.ans[2] = "111";
        t.ans[3] = "001";
        t.ans[4] = "111";
    }

    if(i == 6){
        t.ans[0] = "111";
        t.ans[1] = "100";
        t.ans[2] = "111";
        t.ans[3] = "101";
        t.ans[4] = "111";
    }

    if(i == 7){
        t.ans[0] = "111";
        t.ans[1] = "001";
        t.ans[2] = "001";
        t.ans[3] = "001";
        t.ans[4] = "001";
    }

    if(i == 8){
        t.ans[0] = "111";
        t.ans[1] = "101";
        t.ans[2] = "111";
        t.ans[3] = "101";
        t.ans[4] = "111";
    }

    if(i == 9){
        t.ans[0] = "111";
        t.ans[1] = "101";
        t.ans[2] = "111";
        t.ans[3] = "001";
        t.ans[4] = "111";
    }
    return t;
} 

    


int main(){
   int len;//字串长度
   int t;
   cin>>t;
   string s;
   while(t--){
        cin>>s;
        node re;
        for(int i=0; i<s.length(); i++){
        	node tmp = trans(s[i] - '0'); 
            for(int j=0; j<5; j++){
                re.ans[j] += tmp.ans[j];
            }
        }
        for(int i=0; i<5; i++) {
            cout<<re.ans[i]<<endl;
        }  
   }
   
   

    return 0;
}



