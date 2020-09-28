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
    int a[10];
    string s,t;
    while(cin>>s){
        cin>>t;
        MS(a , 0);
        bool f = 0;
        for(int i=0; i<s.size(); i++) a[s[i] - '0']++;
        if(t.length() != 5){
            for(int i=t[0]-'0'+1; i<10; i++)
                if(a[i] >= t.length())
                    f = 1;
        }
        else{
            int st = t[0] - '0';
            for(int i=st+1; i<6; i++){
                if(a[i]&&a[i+1]&&a[i+2]&&a[i+3]&&a[i+4])
                    f = 1;
            }
        }
        
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}