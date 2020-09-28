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


int main(){
    string s,replace,str;
    int cnt,x,st,len;
    while(cin>>s){
        cin>>cnt;
        while(cnt--){
            cin>>str;
            st = str[1] - '0';
            len = str[2] - '0';
            if(str[0] == '0'){
                string tmp="";
                for(int i=st+len-1; i>=st; i--){
                    tmp += s[i];
                }
                for(int i=0; i<len; i++){
                    s[i+st] = tmp[i];
                }
                cout<<s<<endl;
            }
            else{
                replace = str.substr(3);
                for(int i=0; i<len; i++){
                    s[st+i] = replace[i];
                }
                cout<<s<<endl;
            }
        }
    }
    return 0;
}