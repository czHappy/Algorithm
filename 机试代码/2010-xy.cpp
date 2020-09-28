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

struct node{
    int x;
    int y;
}num[1005];
bool cmp(node a , node b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int n;
int main(){
    while(cin>>n){
        int a, b;
        for(int i=0; i<n; i++){
            cin>>num[i].x>>num[i].y;
        }
        sort(num , num + n , cmp);
        cout<<num[0].x<<" "<<num[0].y<<endl;
    }
    return 0;
}